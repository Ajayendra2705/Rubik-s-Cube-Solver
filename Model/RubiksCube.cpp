#include "RubiksCube.h"

// Given a color, return its first letter
char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:   return 'B';
        case COLOR::GREEN:  return 'G';
        case COLOR::RED:    return 'R';
        case COLOR::YELLOW: return 'Y';
        case COLOR::WHITE:  return 'W';
        case COLOR::ORANGE: return 'O';
        default:            return '?';  // For safety
    }
}

// Convert MOVE enum to string notation
std::string RubiksCube::getMove(MOVE move) {
    switch (move) {
        case MOVE::L:       return "L";
        case MOVE::LPRIME:  return "L'";
        case MOVE::L2:      return "L2";
        case MOVE::R:       return "R";
        case MOVE::RPRIME:  return "R'";
        case MOVE::R2:      return "R2";
        case MOVE::U:       return "U";
        case MOVE::UPRIME:  return "U'";
        case MOVE::U2:      return "U2";
        case MOVE::D:       return "D";
        case MOVE::DPRIME:  return "D'";
        case MOVE::D2:      return "D2";
        case MOVE::F:       return "F";
        case MOVE::FPRIME:  return "F'";
        case MOVE::F2:      return "F2";
        case MOVE::B:       return "B";
        case MOVE::BPRIME:  return "B'";
        case MOVE::B2:      return "B2";
        default:            return "?";
    }
}

// Apply a move to the cube
RubiksCube& RubiksCube::move(MOVE move) {
    switch (move) {
        case MOVE::L:       return l();
        case MOVE::LPRIME:  return lPrime();
        case MOVE::L2:      return l2();
        case MOVE::R:       return r();
        case MOVE::RPRIME:  return rPrime();
        case MOVE::R2:      return r2();
        case MOVE::U:       return u();
        case MOVE::UPRIME:  return uPrime();
        case MOVE::U2:      return u2();
        case MOVE::D:       return d();
        case MOVE::DPRIME:  return dPrime();
        case MOVE::D2:      return d2();
        case MOVE::F:       return f();
        case MOVE::FPRIME:  return fPrime();
        case MOVE::F2:      return f2();
        case MOVE::B:       return b();
        case MOVE::BPRIME:  return bPrime();
        case MOVE::B2:      return b2();
        default:            return *this; // Do nothing if invalid
    }
}

// Return the inverse of a move
RubiksCube& RubiksCube::invert(MOVE move) {
    switch (move) {
        case MOVE::L:       return lPrime();
        case MOVE::LPRIME:  return l();
        case MOVE::L2:      return l2();
        case MOVE::R:       return rPrime();
        case MOVE::RPRIME:  return r();
        case MOVE::R2:      return r2();
        case MOVE::U:       return uPrime();
        case MOVE::UPRIME:  return u();
        case MOVE::U2:      return u2();
        case MOVE::D:       return dPrime();
        case MOVE::DPRIME:  return d();
        case MOVE::D2:      return d2();
        case MOVE::F:       return fPrime();
        case MOVE::FPRIME:  return f();
        case MOVE::F2:      return f2();
        case MOVE::B:       return bPrime();
        case MOVE::BPRIME:  return b();
        case MOVE::B2:      return b2();
        default:            return *this;
    }
}

// Print cube in unfolded planar form
void RubiksCube::print() const {
    std::cout << "Rubik's Cube:\n\n";

    // UP face
    for (int row = 0; row < 3; row++) {
        std::cout << "       ";
        for (int col = 0; col < 3; col++) {
            std::cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // LEFT, FRONT, RIGHT, BACK
    for (int row = 0; row < 3; row++) {
        for (FACE face : {FACE::LEFT, FACE::FRONT, FACE::RIGHT, FACE::BACK}) {
            for (int col = 0; col < 3; col++) {
                std::cout << getColorLetter(getColor(face, row, col)) << " ";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // DOWN face
    for (int row = 0; row < 3; row++) {
        std::cout << "       ";
        for (int col = 0; col < 3; col++) {
            std::cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Shuffle the cube with random moves
std::vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {
    std::vector<MOVE> movesPerformed;
    std::srand(std::time(0));

    for (unsigned int i = 0; i < times; ++i) {
        unsigned int moveIndex = std::rand() % 18;
        MOVE move = static_cast<MOVE>(moveIndex);
        movesPerformed.push_back(move);
        this->move(move);
    }

    return movesPerformed;
}

// Get corner color string from position index
std::string RubiksCube::getCornerColorString(uint8_t index) const {
    std::string str;

    switch (index) {
        case 0: // UFR
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;
        case 1: // UFL
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;
        case 2: // UBL
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;
        case 3: // UBR
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;
        case 4: // DFR
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;
        case 5: // DFL
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;
        case 6: // DBR
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;
        case 7: // DBL
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
        default:
            break;
    }

    return str;
}

// Get a compact ID for a corner based on its color pattern
uint8_t RubiksCube::getCornerIndex(uint8_t index) const {
    std::string corner = getCornerColorString(index);
    uint8_t ret = 0;

    for (char c : corner) {
        if (c == 'Y') ret |= (1 << 2);
        if (c == 'O') ret |= (1 << 1);
        if (c == 'G') ret |= (1 << 0);
    }

    return ret;
}

// Get the orientation of a corner piece
uint8_t RubiksCube::getCornerOrientation(uint8_t index) const {
    std::string corner = getCornerColorString(index);
    char upOrDown = '\0';

    for (char c : corner) {
        if (c == 'W' || c == 'Y') {
            upOrDown = c;
            break;
        }
    }

    if (corner[1] == upOrDown) return 1;
    if (corner[2] == upOrDown) return 2;
    return 0;
}
