#include <iostream>
#include "Cell.h"

using namespace std;

void Cell::tick() {
    cout << this->loc.x << " ";
    cout << this->loc.y << " ";
    cout << this->loc.z << endl;
}

Cell::Cell() {
    Cell(0,0,0);
}

Cell::Cell(int x, int y, int z)  {
    this->loc.x = x;
    this->loc.y = y;
    this->loc.z = z;

    functions = new FuncPointer[3];
}

Cell::~Cell() {
    delete[] functions;
}

