#include <iostream>
#include <string>
#include <cstdlib>

int main() {

    // Local variables
    bool done = false;
    int x, y, i, j;
    int** myArray;
    std::string welcome_msg = "Welcome to the 2D Array Exercise";
    std::string rows_msg = "How many rows you would like: ";
    std::string cols_msg = "How many columns you would like: ";
    std::string repeat_msg = "Would you like to create another array [Y/n]? ";
    std::string another_one = "";

    // Display a nice welcome message
    std::cout << welcome_msg << std::endl;

    // Loop until the user says so
    while(!done) {

        // Get x and y from user
        std::cout << rows_msg;
        std::cin >> x;
        std::cout << cols_msg;
        std::cin >> y;

        // Check x and y for correctness
        if(x <= 0 || y <= 0) {
            std::cout << "Please enter positive numbers of rows and columns\n";
            continue;
        }

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
                std::cout << myArray[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Delete the array
        for(i = 0; i < x; i++) {
            delete[] myArray[i];
        }
        delete[] myArray;

        // Ask if the user want's another array
        std::cout << repeat_msg;
        std::cin >> another_one;

        if(another_one == "n" || another_one == "N") {
            done = true;
        }

    } // While
} // Main


