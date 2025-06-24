#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

// Template Parameters:
// T - Rubik's Cube representation (e.g., 1D, 3D, Bitboard)
// H - Corresponding hash function for the representation
template <typename T, typename H>
class IDDFSSolver {
private:
    T rubiksCube;  // Initial cube configuration
    int max_search_depth;  // Upper limit on depth for iterative deepening
    std::vector<RubiksCube::MOVE> moves;  // Stores the final move sequence

public:
    // Constructor
    IDDFSSolver(const T& _rubiksCube, int _max_search_depth = 7)
        : rubiksCube(_rubiksCube), max_search_depth(_max_search_depth) {}

    // Repeatedly applies DFS with increasing depth until solution is found
    std::vector<RubiksCube::MOVE> solve() {
        for (int depth = 1; depth <= max_search_depth; ++depth) {
            DFSSolver<T, H> dfsSolver(rubiksCube, depth);
            moves = dfsSolver.solve();

            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube; // Update state to solved
                break;
            }
        }

        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
