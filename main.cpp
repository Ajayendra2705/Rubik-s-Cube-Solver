#include <bits/stdc++.h>
using namespace std;
#include "Model/RubiksCube.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCubeBitboard.cpp"

int main() {
    cout << "1D Cube Model" << '\n';
    RubiksCube1dArray cube1D;
    cube1D.print();
    cube1D.u().l().f().r().b().d();
    cube1D.print();
    cube1D.dPrime().bPrime().rPrime().fPrime().lPrime().uPrime();
    cube1D.print();
    cube1D.randomShuffleCube(20);
    cube1D.print();

    cout << "3D Cube Model" << '\n';
    RubiksCube3dArray cube3D;
    cube3D.print();
    cube3D.u().l().f().r().b().d();
    cube3D.print();
    cube3D.dPrime().bPrime().rPrime().fPrime().lPrime().uPrime();
    cube3D.print();
    cube3D.randomShuffleCube(20);
    cube3D.print();

    cout << "Bitboard Cube Model" << '\n';
    RubiksCube1dArray Bitcube;
    Bitcube.print();
    Bitcube.u().l().f().r().b().d();
    Bitcube.print();
    Bitcube.dPrime().bPrime().rPrime().fPrime().lPrime().uPrime();
    Bitcube.print();
    Bitcube.randomShuffleCube(20);
    Bitcube.print();

    return 0;
}
