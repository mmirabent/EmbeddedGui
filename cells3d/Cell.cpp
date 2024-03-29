#include <iostream>
#include "Cell.h"

using namespace std;

Cell::Cell() : Cell(0, 0, 0) {}

Cell::Cell(int x, int y, int z) {
    this->loc.x = x;
    this->loc.y = y;
    this->loc.z = z;

    functions = new FuncPointer[3];
    functions[0] = f1;
    functions[1] = f2;
    functions[2] = f3;
}

Cell::~Cell() { delete[] functions; }

void Cell::tick() {
    cout << "Cell(";
    cout << this->loc.x << ",";
    cout << this->loc.y << ",";
    cout << this->loc.z << ")" << endl;
    functions[rand() % 3]();
}

void Cell::f1() {
    // Do stuff?
    cout << "Inside f1" << endl;
}

void Cell::f2() {
    // Do stuff?
    cout << "Inside f2" << endl;
}

void Cell::f3() {
    // Do stuff?
    cout << "Inside f3" << endl;
}
