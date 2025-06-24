#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// Template Parameters:
// T - Rubik's Cube representation (e.g., 1D, 3D, Bitboard)
// H - Corresponding hash function for the representation
template <typename T, typename H>
class BFSSolver {
private:
    T rubiksCube;  // Initial cube configuration
    std::vector<RubiksCube::MOVE> moves;  // Moves to solve the cube

    std::unordered_map<T, bool, H> visited;               // Tracks visited states
    std::unordered_map<T, RubiksCube::MOVE, H> move_done; // Back-pointer map for reconstruction

    // Performs BFS to find the solution
    T bfs() {
        std::queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            T current = q.front();
            q.pop();

            if (current.isSolved()) {
                return current;
            }

            for (int i = 0; i < 18; ++i) {
                RubiksCube::MOVE move = RubiksCube::MOVE(i);
                current.move(move);

                if (!visited[current]) {
                    visited[current] = true;
                    move_done[current] = move;
                    q.push(current);
                }

                current.invert(move); // Revert move to try next one
            }
        }

        return rubiksCube; // Should never reach here if cube is solvable
    }

public:
    // Constructor
    BFSSolver(const T& _rubiksCube) : rubiksCube(_rubiksCube) {}

    // Solves the cube using BFS and returns the move sequence
    std::vector<RubiksCube::MOVE> solve() {
        T solvedCube = bfs();
        assert(solvedCube.isSolved());

        // Backtrack to reconstruct the path
        T current = solvedCube;
        while (!(current == rubiksCube)) {
            RubiksCube::MOVE move = move_done[current];
            moves.push_back(move);
            current.invert(move); // Go back one step
        }

        std::reverse(moves.begin(), moves.end());
        rubiksCube = solvedCube; // Update internal state to solved
        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_BFSSOLVER_H
