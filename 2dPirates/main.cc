#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

    // Local variables
    bool done = false;
    int x, y, i, j;
    int** myArray;
    string welcome_msg  = "Welcome to the 2D Array Exercise";
    string rows_msg     = "How many rows you would like: ";
    string cols_msg     = "How many columns you would like: ";
    string repeat_msg   = "Would you like to create another array [Y/n]? ";
    string alloc_error  = "Not enough memory for an array of that size.";
    string number_error = "Please enter positive numbers of rows and columns";
    string another_one  = "";

    // Display a nice welcome message
    cout << welcome_msg << endl;

    // Loop until the user says so
    while(!done) {

        // Reset x and y
        x = 0;
        y = 0;

        // Get x and y from user
        cout << rows_msg;
        cin >> x;
        cout << cols_msg;
        cin >> y;

        // Check x and y for correctness
        if(x <= 0 || y <= 0) {
            cout << number_error << endl;
            continue;
        }

        try {
            // Allocate a 2d array
            myArray = new int*[x];
            for(i = 0; i < x; i++) {
                myArray[i] = new int[y];
            }

            // Fill the array 
            for(i = 0; i < x; i++) {
                for(j = 0; j < y; j++) {
                    myArray[i][j] = rand() % 100 + 1; // Random numbers 1-100
                }
            }

            // Print the array
            for(i = 0; i < x; i++) {
                for(j = 0; j < y; j++) {
                    cout << myArray[i][j] << " ";
                }
                cout << endl;
            }
        } catch (const bad_alloc& e) {
            cout << alloc_error << endl;
        }

        // Delete the array
        for(i = 0; i < x; i++) {
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


