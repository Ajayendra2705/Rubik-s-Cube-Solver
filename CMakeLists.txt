set(SOURCES
    main.cpp

    # Model
    Model/RubiksCube.cpp
    Model/RubiksCube1dArray.cpp
    Model/RubiksCube3dArray.cpp
    Model/RubiksCubeBitboard.cpp

    # Solver
    Solver/DFSSolver.cpp
    Solver/BFSSolver.cpp
    Solver/IDDFSSolver.cpp
    Solver/IDAstarSolver.cpp

    # Pattern Databases
    PatternDatabases/NibbleArray.cpp
    PatternDatabases/PatternDatabase.cpp
    PatternDatabases/CornerPatternDatabase.cpp
    PatternDatabases/CornerDBMaker.cpp
    PatternDatabases/math.cpp
)
