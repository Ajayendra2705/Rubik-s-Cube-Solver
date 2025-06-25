#ifndef RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
#include "../PatternDatabases/CornerPatternDatabase.h"

template<typename T, typename H>
class IDAstarSolver {
private:
    CornerPatternDatabase cornerDB;
    std::vector<RubiksCube::MOVE> moves;
    std::unordered_map<T, RubiksCube::MOVE, H> move_done;
    std::unordered_map<T, bool, H> visited;

    struct Node {
        T cube;
        int depth;
        int estimate;

        Node(T _cube, int _depth, int _estimate)
            : cube(_cube), depth(_depth), estimate(_estimate) {}
    };

    struct CompareCube {
        bool operator()(const std::pair<Node, int>& p1, const std::pair<Node, int>& p2) const {
            auto& n1 = p1.first;
            auto& n2 = p2.first;
            int f1 = n1.depth + n1.estimate;
            int f2 = n2.depth + n2.estimate;
            return (f1 == f2) ? (n1.estimate > n2.estimate) : (f1 > f2);
        }
    };

    void resetStructure() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }

    // Returns {solved cube, bound} if solved
    // Returns {rubiksCube, next_bound} if not solved
    std::pair<T, int> IDAstar(int bound) {
        std::priority_queue<std::pair<Node, int>, std::vector<std::pair<Node, int>>, CompareCube> pq;

        Node start(rubiksCube, 0, cornerDB.getNumMoves(rubiksCube));
        pq.push({start, 0});

        int next_bound = INT_MAX;

        while (!pq.empty()) {
            auto topPair = pq.top();
            auto node = topPair.first;
            auto moveIdx = topPair.second;

            pq.pop();

            if (visited[node.cube]) continue;
            visited[node.cube] = true;
            move_done[node.cube] = static_cast<RubiksCube::MOVE>(moveIdx);

            if (node.cube.isSolved()) return {node.cube, bound};

            int new_depth = node.depth + 1;

            for (int i = 0; i < 18; ++i) {
                RubiksCube::MOVE move = static_cast<RubiksCube::MOVE>(i);
                node.cube.move(move);

                if (!visited[node.cube]) {
                    int estimate = cornerDB.getNumMoves(node.cube);
                    if (new_depth + estimate > bound) {
                        next_bound = std::min(next_bound, new_depth + estimate);
                    } else {
                        pq.push({Node(node.cube, new_depth, estimate), i});
                    }
                }

                node.cube.invert(move); // undo move
            }
        }

        return {rubiksCube, next_bound};
    }

public:
    T rubiksCube;

    IDAstarSolver(T _rubiksCube, const std::string& fileName) : rubiksCube(_rubiksCube) {
        cornerDB.fromFile(fileName);
    }

    std::vector<RubiksCube::MOVE> solve() {
        int bound = 1;
        auto result = IDAstar(bound);

        while (result.second != bound) {
            resetStructure();
            bound = result.second;
            result = IDAstar(bound);
        }

        T solved_cube = result.first;
        assert(solved_cube.isSolved());

        T current = solved_cube;
        while (!(current == rubiksCube)) {
            RubiksCube::MOVE move = move_done[current];
            moves.push_back(move);
            current.invert(move);
        }

        rubiksCube = solved_cube;
        std::reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H
