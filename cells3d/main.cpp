#include <iostream>
#include <string>
#include <cstdlib>
#include "Cell.h"

using namespace std;

int main() {

    // Local variables
    bool done = false;
    int x, y, z, i, j, k;
    int*** myArray;
    string welcome_msg  = "Welcome to the 3D Array Exercise";
    string rows_msg     = "How many rows you would like: ";
    string cols_msg     = "How many columns you would like: ";
    string height_msg   = "How many layers would you like: ";
    string repeat_msg   = "Would you like to create another array [Y/n]? ";
    string number_error = "Please enter positive numbers";
    string another_one  = "";

    // Display a nice welcome message
    cout << welcome_msg << endl;

    Cell* foo = new Cell();
    foo->loc.x = 10;
    foo->loc.y = 20;
    foo->loc.z = 30;
    foo->tick();

    delete foo;

    // Loop until the user says so
    while(!done) {

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
        if(x <= 0 || y <= 0 || z <= 0) {
            cout << number_error << endl;
            continue;
        }

        // Allocate a 3d array
        myArray = new int**[x];
            for(i = 0; i < x; i++) {
                myArray[i] = new int*[y];
                for(j = 0; j < y; j++) {
                    myArray[i][j] = new int[z];
                }
            }

            // Fill the array 
            for(i = 0; i < x; i++) {
                for(j = 0; j < y; j++) {
                    for(k = 0; k < z; k++) {
                        myArray[i][j][k] = rand() % 100 + 1; // Random numbers 1-100
                    }
                }
            }

            // Print the array
            for(k = 0; k < z; k++) {
                cout << "Z: " << k << endl;
                for(i = 0; i < x; i++) {
                    for(j = 0; j < y; j++) {
                        cout << myArray[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }

        // Delete the array
        for(i = 0; i < x; i++) {
            for(j = 0; j < y; j++) {
                delete[] myArray[i][j];
            }
            delete[] myArray[i];
        }
        delete[] myArray;

        // Ask if the user want's another array
        cout << repeat_msg;
        cin >> another_one;

        if(another_one == "n" || another_one == "N") {
            done = true;
        }

    } // While
} // Main


