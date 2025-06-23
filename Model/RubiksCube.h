#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"
using namespace std;

// Abstract base class for all Rubik's Cube representations.
// Provides shared functionality and interface for different models like 3D array, 1D array, bitboard, etc.
class RubiksCube {
public:
    // Enum representing the six faces of the cube
    enum class FACE {
        UP, LEFT, FRONT, RIGHT, BACK, DOWN
    };

    // Enum representing the six standard cube colors
    enum class COLOR {
        WHITE, GREEN, RED, BLUE, ORANGE, YELLOW
    };

    // Enum representing all 18 possible moves on the cube
    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    // Get the color of a specific face, row, and column
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    // Get the character representing a color (e.g., 'G' for GREEN)
    static char getColorLetter(COLOR color);

    // Check if the cube is in solved state
    virtual bool isSolved() const = 0;

    // Convert a MOVE enum to string (e.g., "R'", "U2")
    static string getMove(MOVE ind);

    // Print the cube in unfolded 2D planar format
    void print() const;

/*
     * Print the Rubik Cube in Planar format.
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     * rx -> row numbering
     * cx -> column numbering
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */

    // Shuffle the cube with random moves; return the moves performed
    vector<MOVE> randomShuffleCube(unsigned int times);

    // Apply a move to the cube
    RubiksCube &move(MOVE ind);

    // Apply the inverse of a move
    RubiksCube &invert(MOVE ind);

    // ---- Rotation Moves (pure virtual) ----

    virtual RubiksCube &f()       = 0;
    virtual RubiksCube &fPrime() = 0;
    virtual RubiksCube &f2()     = 0;

    virtual RubiksCube &u()       = 0;
    virtual RubiksCube &uPrime() = 0;
    virtual RubiksCube &u2()     = 0;

    virtual RubiksCube &l()       = 0;
    virtual RubiksCube &lPrime() = 0;
    virtual RubiksCube &l2()     = 0;

    virtual RubiksCube &r()       = 0;
    virtual RubiksCube &rPrime() = 0;
    virtual RubiksCube &r2()     = 0;

    virtual RubiksCube &d()       = 0;
    virtual RubiksCube &dPrime() = 0;
    virtual RubiksCube &d2()     = 0;

    virtual RubiksCube &b()       = 0;
    virtual RubiksCube &bPrime() = 0;
    virtual RubiksCube &b2()     = 0;

    // Get a 3-letter color string representing a corner piece (based on its position index)
    string getCornerColorString(uint8_t ind) const;

    // Get a unique index representing the color pattern of a corner piece
    uint8_t getCornerIndex(uint8_t ind) const;

    // Get the orientation (0, 1, or 2) of a corner piece
    uint8_t getCornerOrientation(uint8_t ind) const;
};

#endif // RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
