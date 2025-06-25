#include <bits/stdc++.h>
using namespace std;
#include "Model/RubiksCube.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCubeBitboard.cpp"

#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"

#include "PatternDatabases/NibbleArray.cpp"
#include "PatternDatabases/PatternDatabase.cpp"
#include "PatternDatabases/CornerPatternDatabase.cpp"
#include "PatternDatabases/CornerDBMaker.cpp"
#include "PatternDatabases/math.cpp"


int main() {
    // cout << "1D Cube Model" << '\n';
    // RubiksCube1dArray cube1D;
    // cube1D.print();
    // cube1D.u().l().f().r().b().d();
    // cube1D.print();
    // cube1D.dPrime().bPrime().rPrime().fPrime().lPrime().uPrime();
    // cube1D.print();
    // cube1D.randomShuffleCube(20);
    // cube1D.print();

    // cout << "3D Cube Model" << '\n';
    // RubiksCube3dArray cube3D;
    // cube3D.print();
    // cube3D.u().l().f().r().b().d();
    // cube3D.print();
    // cube3D.dPrime().bPrime().rPrime().fPrime().lPrime().uPrime();
    // cube3D.print();
    // cube3D.randomShuffleCube(20);
    // cube3D.print();

    // cout << "Bitboard Cube Model" << '\n';
    // RubiksCube1dArray Bitcube;
    // Bitcube.print();
    // Bitcube.u().l().f().r().b().d();
    // Bitcube.print();
    // Bitcube.dPrime().bPrime().rPrime().fPrime().lPrime().uPrime();
    // Bitcube.print();
    // Bitcube.randomShuffleCube(20);
    // Bitcube.print();

    // Solvers

    // DFS Solver
    // RubiksCubeBitboard dfsCube;

    // dfsCube.print();
    // std::vector<RubiksCube::MOVE> shuffleMoves = dfsCube.randomShuffleCube(5);
    
    // std::cout << "Random Shuffle Moves: ";
    // for (auto move : shuffleMoves) {
    //     std::cout << dfsCube.getMove(move) << " ";
    // }
    // std::cout << "\n";
    // dfsCube.print();

    // BFSSolver<RubiksCubeBitboard, HashBitboard> DFSSolver(dfsCube);
    // std::vector<RubiksCube::MOVE> DFSMoves = DFSSolver.solve();

    // std::cout << "DFS Solution: ";
    // for (auto move : DFSMoves) {
    //     std::cout << dfsCube.getMove(move) << " ";
    // }
    // std::cout << "\n";

    // for (auto move : DFSMoves) dfsCube.move(move);
    // dfsCube.print();

    // BFS Solver
    // RubiksCubeBitboard bfsCube;

    // bfsCube.print();
    // std::vector<RubiksCube::MOVE> shuffleMoves = bfsCube.randomShuffleCube(5);
    
    // std::cout << "Random Shuffle Moves: ";
    // for (auto move : shuffleMoves) {
    //     std::cout << bfsCube.getMove(move) << " ";
    // }
    // std::cout << "\n";
    // bfsCube.print();

    // BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(bfsCube);
    // std::vector<RubiksCube::MOVE> bfsMoves = bfsSolver.solve();

    // std::cout << "BFS Solution: ";
    // for (auto move : bfsMoves) {
    //     std::cout << bfsCube.getMove(move) << " ";
    // }
    // std::cout << "\n";

    // for (auto move : bfsMoves) bfsCube.move(move);
    // bfsCube.print();

    // IDDFS Solver
    // RubiksCubeBitboard IDDFSCube;

    // IDDFSCube.print();
    // std::vector<RubiksCube::MOVE> shuffleMoves = IDDFSCube.randomShuffleCube(6);
    
    // std::cout << "Random Shuffle Moves: ";
    // for (auto move : shuffleMoves) {
    //     std::cout << IDDFSCube.getMove(move) << " ";
    // }
    // std::cout << "\n";
    // IDDFSCube.print();

    // BFSSolver<RubiksCubeBitboard, HashBitboard> IDDFSSolver(IDDFSCube);
    // std::vector<RubiksCube::MOVE> IDDFSMoves = IDDFSSolver.solve();

    // std::cout << "IDDFS Solution: ";
    // for (auto move : IDDFSMoves) {
    //     std::cout << IDDFSCube.getMove(move) << " ";
    // }
    // std::cout << "\n";

    // for (auto move : IDDFSMoves) IDDFSCube.move(move);
    // IDDFSCube.print();

    // string dbPath = "cornerDepth7.txt";
    // CornerDBMaker dbMaker(dbPath, 0xF);
    // dbMaker.bfsAndStore();

//    Code to create Corner Database
//    CornerDBMaker dbMaker(fileName, 0x99);
//    dbMaker.bfsAndStore();

    RubiksCubeBitboard cube;
    auto shuffleMoves = cube.randomShuffleCube(11);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n";

    string fileName = R"(C:\Users\ajiit\Desktop\Future\Real Projects\Rubik-s-Cube-Solver\cornerDepth5.txt)";

    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    idaStarSolver.rubiksCube.print();
    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n";


}
