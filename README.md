# 🧊 Rubik's Cube Solver – C++ Implementation

This project provides a flexible and extensible C++ implementation of a **Rubik’s Cube simulator** and solver backend. It features multiple cube models — including a simple 1D array, a natural 3D array, and an efficient Bitboard representation — each built with a consistent interface and capable of performing standard Rubik's Cube operations.

---

## 📦 Cube Models Implemented

### 1️⃣ Rubik'sCube1dArray

- Represents the cube as a flat 1D array of 54 elements.
- Compact, simple, and ideal for algorithmic manipulation and debugging.
- Faces are indexed: `U=0`, `R=1`, `F=2`, `D=3`, `L=4`, `B=5`.

### 2️⃣ Rubik'sCube3dArray

- Models the cube as a `3D array` of size `[6][3][3]`.
- Intuitive to visualize — mirrors the physical cube's structure.
- Useful for direct face manipulations and visualization algorithms.

### 3️⃣ Rubik'sCubeBitboard

- Uses bit manipulation and binary encoding for compact and performant cube representation.
- Each face is stored as an integer (or series of bitfields).
- Optimized for fast state comparisons and solver implementations.

---


## ⚙️ Core Functions

Each cube model (1D, 3D, Bitboard) inherits from the abstract base class `RubiksCube` and implements the following core functionality:

---

### 🔄 Move Operations

#### General

- `RubiksCube& move(MOVE ind)`  
  Applies a single move to the cube based on the `MOVE` enum.

- `RubiksCube& invert(MOVE ind)`  
  Applies the inverse of the given move.

- `vector<MOVE> randomShuffleCube(unsigned int times)`  
  Applies `times` number of random moves to scramble the cube and returns the list of moves applied.

---

#### Face Rotations (Pure Virtual, implemented per model)

Each of the 6 faces supports:

- Clockwise 90° (`move`)
- Counter-clockwise 90° (`prime`)
- 180° turn (`2`)

##### Front (F)
- `f()`
- `fPrime()`
- `f2()`

##### Up (U)
- `u()`
- `uPrime()`
- `u2()`

##### Left (L)
- `l()`
- `lPrime()`
- `l2()`

##### Right (R)
- `r()`
- `rPrime()`
- `r2()`

##### Down (D)
- `d()`
- `dPrime()`
- `d2()`

##### Back (B)
- `b()`
- `bPrime()`
- `b2()`

---

### 🧩 Cube State & Utilities

- `COLOR getColor(FACE face, unsigned row, unsigned col) const`  
  Returns the color of a sticker at a given face, row, and column.

- `bool isSolved() const`  
  Checks if the cube is in the solved (original) state.

- `void print() const`  
  Prints the cube in an unfolded 2D planar format.

- `static char getColorLetter(COLOR color)`  
  Returns a character (`W`, `G`, `R`, etc.) corresponding to a color enum.

- `static string getMove(MOVE ind)`  
  Returns the move notation string (e.g., `"R"`, `"F'"`, `"U2"`) for a given `MOVE` enum.

---

### 🔍 Corner Cubie Information

These functions provide advanced cube state introspection, useful for solvers and optimizations:

- `string getCornerColorString(uint8_t ind) const`  
  Returns the 3-character color string for a specific corner index (e.g., `"WGR"`).

- `uint8_t getCornerIndex(uint8_t ind) const`  
  Returns the unique permutation index of the corner at a given position.

- `uint8_t getCornerOrientation(uint8_t ind) const`  
  Returns the orientation (0, 1, or 2) of the corner cubie.

---

This unified interface allows interchangeable use of all models (1D array, 3D array, and Bitboard), making it easier to integrate solvers, visualizers, or testing frameworks.
