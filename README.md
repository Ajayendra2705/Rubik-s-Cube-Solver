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

Each model class inherits from a common abstract base `RubiksCube`, and implements these core methods:

### ✅ Move Functions

- `move(std::string moveName)`: Applies a single move.
  - Supported moves: `"U"`, `"D"`, `"L"`, `"R"`, `"F"`, `"B"`
  - Variants (`"U'"`, `"R2"`, etc.) can be extended.
  