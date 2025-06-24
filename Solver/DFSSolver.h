#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Template Parameters:
// T - Rubik's Cube representation (e.g., 1D, 3D, Bitboard)
// H - Corresponding hash function for the representation
template <typename T, typename H>
class DFSSolver {
private:
    T rubiksCube;  // Initial cube state
    std::vector<RubiksCube::MOVE> moves;  // Stores the solution path
    int max_search_depth;  // Maximum depth to limit DFS search

    // Recursive DFS function to find the solution up to a certain depth
    bool dfs(int depth) {
        if (rubiksCube.isSolved()) return true;
        if (depth > max_search_depth) return false;

        for (int i = 0; i < 18; ++i) {
            RubiksCube::MOVE move = RubiksCube::MOVE(i);
            rubiksCube.move(move);
            moves.push_back(move);

            if (dfs(depth + 1)) return true;

            moves.pop_back();           // Backtrack
            rubiksCube.invert(move);   // Undo the move
        }

        return false; // No solution found within current depth
    }

public:
    // Constructor
    DFSSolver(const T& _rubiksCube, int _max_search_depth = 8)
        : rubiksCube(_rubiksCube), max_search_depth(_max_search_depth) {}

    // Initiates DFS and returns the sequence of moves to solve the cube
    std::vector<RubiksCube::MOVE> solve() {
        dfs(1); // Start depth from 1
        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_DFSSOLVER_H
