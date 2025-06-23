#include "RubiksCube.h"

class RubiksCube1dArray : public RubiksCube {
private:
    char cube[54]{}; // 6 faces × 9 cells = 54

    static inline int getIndex(int face, int row, int col) {
        return face * 9 + row * 3 + col;
    }

    void rotateFace(int face) {
        char temp[9];
        for (int i = 0; i < 9; ++i)
            temp[i] = cube[face * 9 + i];

        for (int i = 0; i < 3; ++i) {
            cube[getIndex(face, 0, i)] = temp[getIndex(0, 2 - i, 0)];
            cube[getIndex(face, i, 2)] = temp[getIndex(0, 0, i)];
            cube[getIndex(face, 2, 2 - i)] = temp[getIndex(0, i, 2)];
            cube[getIndex(face, 2 - i, 0)] = temp[getIndex(0, 2, 2 - i)];
        }
    }

public:
    RubiksCube1dArray() {
        for (int f = 0; f < 6; ++f)
            for (int i = 0; i < 9; ++i)
                cube[f * 9 + i] = getColorLetter(static_cast<COLOR>(f));
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char c = cube[getIndex(static_cast<int>(face), row, col)];
        switch (c) {
            case 'B': return COLOR::BLUE;
            case 'G': return COLOR::GREEN;
            case 'R': return COLOR::RED;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
            default:  return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int f = 0; f < 6; ++f)
            for (int i = 0; i < 9; ++i)
                if (cube[f * 9 + i] != getColorLetter(static_cast<COLOR>(f)))
                    return false;
        return true;
    }

    // --- Cube Moves ---

    RubiksCube& u() override {
        rotateFace(0);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(3, 0, 2 - i)] = temp[i];
        return *this;
    }

    RubiksCube& uPrime() override { return u().u().u(); }
    RubiksCube& u2() override     { return u().u(); }

    RubiksCube& d() override {
        rotateFace(5);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(3, 2, i)] = temp[i];
        return *this;
    }

    RubiksCube& dPrime() override { return d().d().d(); }
    RubiksCube& d2() override     { return d().d(); }

    RubiksCube& l() override {
        rotateFace(1);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; ++i) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; ++i) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; ++i) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; ++i) cube[getIndex(2, i, 0)] = temp[i];
        return *this;
    }

    RubiksCube& lPrime() override { return l().l().l(); }
    RubiksCube& l2() override     { return l().l(); }

    RubiksCube& r() override {
        rotateFace(3);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; ++i) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; ++i) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; ++i) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; ++i) cube[getIndex(4, i, 0)] = temp[i];
        return *this;
    }

    RubiksCube& rPrime() override { return r().r().r(); }
    RubiksCube& r2() override     { return r().r(); }

    RubiksCube& f() override {
        rotateFace(2);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; ++i) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; ++i) cube[getIndex(3, i, 0)] = temp[i];
        return *this;
    }

    RubiksCube& fPrime() override { return f().f().f(); }
    RubiksCube& f2() override     { return f().f(); }

    RubiksCube& b() override {
        rotateFace(4);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; ++i) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; ++i) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; ++i) cube[getIndex(1, i, 0)] = temp[i];
        return *this;
    }

    RubiksCube& bPrime() override { return b().b().b(); }
    RubiksCube& b2() override     { return b().b(); }

    const char* getRawCube() const {
        return cube;
    }

    // --- Comparison and Assignment ---

    bool operator==(const RubiksCube1dArray& other) const {
        for (int i = 0; i < 54; ++i)
            if (cube[i] != other.cube[i])
                return false;
        return true;
    }

    RubiksCube1dArray& operator=(const RubiksCube1dArray& other) {
        for (int i = 0; i < 54; ++i)
            cube[i] = other.cube[i];
        return *this;
    }
};

// --- Hashing Support ---
struct Hash1d {
    size_t operator()(const RubiksCube1dArray& cube) const {
        return std::hash<std::string>()(std::string(cube.getRawCube(), cube.getRawCube() + 54));
    }
};
