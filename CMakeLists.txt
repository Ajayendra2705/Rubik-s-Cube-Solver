cmake_minimum_required(VERSION 3.20)
project(rubiks_cube_solver)

set(CMAKE_CXX_STANDARD 14)

# Add include directories
include_directories(Model)
# include_directories(Solver)
# include_directories(PatternDatabases)

# List all source files
set(SOURCES
    main.cpp

    # Model
    Model/RubiksCube.cpp
    Model/RubiksCube1dArray.cpp
    Model/RubiksCube3dArray.cpp
    Model/RubiksCubeBitboard.cpp

    # Pattern Databases
    # PatternDatabases/NibbleArray.cpp
    # PatternDatabases/PatternDatabase.cpp
    # PatternDatabases/CornerPatternDatabase.cpp
    # PatternDatabases/CornerDBMaker.cpp
    # PatternDatabases/math.cpp
)

# Create executable
add_executable(rubiks_cube_solver ${SOURCES})
