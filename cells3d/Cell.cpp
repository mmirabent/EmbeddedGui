#include <iostream>
#include "Cell.h"

using namespace std;

void Cell::tick() {
    cout << this->loc.x << " ";
    cout << this->loc.y << " ";
    cout << this->loc.z << endl;
}

Cell::Cell() {
    this->loc.x = 0;
    this->loc.y = 0;
    this->loc.z = 0;

    functions = new FuncPointer[3];
}

Cell::~Cell() {
    delete[] functions;
}

