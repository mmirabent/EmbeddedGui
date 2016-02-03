#include <iostream>
#include <string>
#include <cstdlib>
#include "Cell.h"

using namespace std;

int main() {

    // Local variables
    bool done = false;
    int x, y, z, i, j, k;
    Cell ****myArray;
    string welcome_msg = "Welcome to 3D Cells Exercise";
    string rows_msg = "X: ";
    string cols_msg = "Y: ";
    string height_msg = "Z: ";
    string repeat_msg = "Would you like to create another array [Y/n]? ";
    string number_error = "Please enter positive numbers";
    string another_one = "";

    // Display a nice welcome message
    cout << welcome_msg << endl;

    // Loop until the user says so
    while (!done) {

        // Reset x and y
        x = 0;
        y = 0;
        z = 0;

        // Get x and y from user
        cout << rows_msg;
        cin >> x;
        cout << cols_msg;
        cin >> y;
        cout << height_msg;
        cin >> z;

        // Check x, y, and z for correctness
        if (x <= 0 || y <= 0 || z <= 0) {
            cout << number_error << endl;
            continue;
        }

        // Allocate a 3d array
        myArray = new Cell ***[z];
        for (k = 0; k < z; k++) {
            myArray[k] = new Cell **[y];
            for (j = 0; j < y; j++) {
                myArray[k][j] = new Cell *[x];
            }
        }

        // Fill the array
        for (k = 0; k < z; k++) {
            for (j = 0; j < y; j++) {
                for (i = 0; i < x; i++) {
                    myArray[k][j][i] = new Cell();
                }
            }
        }

        cout << endl;

        // Print the array
        for (k = 0; k < z; k++) {
            cout << "Z: " << k << endl;
            for (j = 0; j < y; j++) {
                for (i = 0; i < x; i++) {
                    myArray[k][j][i]->tick();
                }
                cout << endl;
            }
            cout << endl;
        }

        // Delete the array
        for (k = 0; k < z; k++) {
            for (j = 0; j < y; j++) {
                delete[] myArray[k][j];
            }
            delete[] myArray[k];
        }
        delete[] myArray;

        // Ask if the user want's another array
        cout << repeat_msg;
        cin >> another_one;

        if (another_one == "n" || another_one == "N") {
            done = true;
        }

    } // While
} // Main
