#include <fstream>
#include <iostream>

using namespace std;

class Sudoku {

private:

    int grid[9][9];

    bool scanCol(int col, int number);
    bool scanRow(int row, int number);
    bool scanBox(int row, int col, int number);

public:

    Sudoku();
    Sudoku(int n);

    bool solve();

    int getValue(int row, int col);

    void setValue(int row, int col, int value);

    void printGrid();

};

/*---------------------------------------------------------------------------*/
// CONSTRUCTORS

Sudoku::Sudoku() {

    // Initialize the whole grid to 0s

    for (int i = 0; i <= 8; i++) {

        for (int j = 0; j <= 8; j++) {

            this->grid[i][j] = 0;

        }

    }

}

// May not need this one to work
Sudoku::Sudoku(int n) {

    

}

/*---------------------------------------------------------------------------*/

void Sudoku::setValue(int row, int col, int value) {

    this->grid[row][col] = value;

}

/*---------------------------------------------------------------------------*/
// SOLVER

bool Sudoku::scanCol(int col, int number) {

    for (int row_scan = 0; row_scan < 9; row_scan++) {

        if (this->grid[row_scan][col] == number) {

            // We found given number in the row
            return true;

        }

    }

    // We didn't find given number in the column
    return false;

}

bool Sudoku::scanRow(int row, int number) {

    
    for (int col_scan = 0; col_scan < 9; col_scan++) {

        if (this->grid[row][col_scan] == number) {

            // We found given number in the row
            return true;

        }

    }

    // We didn't find given number in the row
    return false;

}

bool Sudoku::scanBox(int row, int col, int number) {

    int row_min, row_max, col_min, col_max;

    // i goes from 0 to 3 to 6
    for (int i = 0; i <= 6; i += 3) {

        // j goes from 0 to 3 to 6
        for (int j = 0; j <= 6; j += 3) {

            // Set row min and max for scan based on given row and column
            if (row >= i && row <= (i+2) && col >= j && col <= (j+2)) {

                row_min = i;
                row_max = i+2;
                col_min = j;
                col_max = j+2;

            }

        }

    }

    int row_scan = row_min;
    int col_scan = col_min;

    // go until we find given number in the box
    while (this->grid[row_scan][col_scan] != number) {

        // If we didn't find a number that matched,
        if (col_scan == col_max && row_scan == row_max) {

            return false;

        }

        // If we reached the end of the row
        else if (col_scan == col_max) {

            col_scan = col_min;
            row_scan++;

        }

        // Else, move along the row
        else {

            col_scan++;

        }

    }

    // If we made it to this point, we found given number in the box
    return true;

}

bool Sudoku::solve() {

    // Start at the beginning of the grid
    int row = 0;
    int col = 0;

    // Find first empty entry in grid
    while (this->grid[row][col] != 0) {

        // If we couldn't find one, the puzzle's most likely solved
        if (row == 8 && col == 8) {

            return true;

        }

        // If we reached the end of the row
        else if (col == 8) {

            // Move to beginning of next row
            col = 0;
            row++;

        }

        // Else, move along the row
        else {

            col++;

        }
            
    }

    // Find first number that works
    for (int number = 1; number <= 9; number++) {

        if (

        // If we didn't find given number in current row
        this->scanRow(row, number) == false &&

        // or current column
        this->scanCol(col, number) == false &&

        // or current 3x3 box 
        this->scanBox(row, col, number) == false

        )
        {

            // If given number worked, set current spot to that number
            this->grid[row][col] = number;

            // Call Sudoku::solve() again
            // if that returned true, puzzle is solved!
            if (this->solve() == true) {

                // Return true to calling instance of solve()
                return true;

            }

            // if that returned false, we need to reset the current spot and continue with this loop
            else {

                this->grid[row][col] = 0;

            }

        }

    }

    // If we made it to this point, we couldn't find a number that worked, so we should return false
    return false;

}

/*---------------------------------------------------------------------------*/

istream &operator>>(istream &input, Sudoku &s) {
    
    int value;
    
    for (int i = 0; i <= 8; i++) {

        for (int j = 0; j <= 8; j++) {

            input >> value;
            s.setValue(i, j, value);

        }

    }

    return input;

}

/*---------------------------------------------------------------------------*/

int Sudoku::getValue(int row, int col) {

    return this->grid[row][col];

}

/*---------------------------------------------------------------------------*/

void Sudoku::printGrid() {

    for (int i = 0; i <= 8; i++) {

        for (int j = 0; j <= 8; j++) {

            cout << this->grid[i][j] << " ";

        }

        cout << endl;

    }

}