#include <iostream>
#include <iomanip>
#include <string>


// I want to take a 9x9 sudoku puzzle, store it as a 9x9 array, and generate the 1st round of possible candidates for the missing numbers.
/*
steps:
1. create a 9x9 array that is defined as it is created.
2. attach another dimension to the 9x9. This is the candidate dimension. Array is now [9x9x9] or [Row x Column x Candidate]
3. create a function that uses the [Row x Column] dimensions and determines the values for the [Candidate] dimension.
4. print the [Row x Column] dimensions and the [Candidate] dimension

Plans for steps:
3. finding the [Candidate]'s values.
    a. for i in Row[i] Column[i] as box_value:
        if box_value.isDigit():
            set Candidate to nothing or box_value // might be useful for it to set to ONLY 1 value (box_value)

        if box_value == "-": find the value's that the box CAN'T be equal to. and numbers in the same box, row or column.

*/


using namespace std;

// 1st array is a 9x9
// 2nd array to hold possible values


// square grid settings:
const int SIZE = 9;

const int MIN_VALUE = 1;
const int MAX_VALUE = 9;

//int arr1[1] = {1};
//int arr2[2][1] =   { {1}, {2} };
//int arr3[3][2][1] = { { {1}, {2} }, { {3}, {4} }, { {5}, {6} } };

void printArray(char arr[SIZE][SIZE+1][SIZE]);
void findCandidates(char arr[SIZE][SIZE][SIZE]);

int main() {
    // [row][col] --> [row][col][candidates]. 
    // defines [0][size][size]
    // i want the starting numbers to be the first array, 

    // row value, column value, 


                                //};
    char sudokuArray[SIZE][SIZE+1][SIZE] = {

        { {'-', '-', '-',  '-', '7', '-',  '-', '2', '-'} },
        { {'-', '8', '-',  '-', '-', '-',  '-', '3', '-'} },
        { {'6', '-', '-',  '-', '-', '4',  '7', '-', '8'} },

        { {'-', '-', '-',  '-', '-', '-',  '-', '-', '-'} },
        { {'-', '6', '-',  '-', '3', '-',  '-', '-', '1'} },
        { {'4', '-', '-',  '5', '-', '-',  '-', '-', '-'} },

        { {'-', '-', '9',  '-', '-', '3',  '-', '-', '-'} },
        { {'-', '1', '-',  '-', '9', '-',  '6', '-', '7'} },
        { {'-', '-', '-',  '-', '-', '-',  '2', '-', '-'} }
        
    }; // third dimension isn't defined. it needs to be set to 1 through 9?


    int count = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int column = 1; column < SIZE+1; column++) {
            for (int candidate = 0; candidate < SIZE; candidate++) {
                // assign numbers 1 through 9
                sudokuArray[row][column][candidate] = candidate + 49; // starts with 1 when i=0
                cout << sudokuArray[row][column][candidate] << " ";
                count++;
            }
            //cout << endl;
        }
        cout << endl;
    }
    cout << "count: " << count << endl;
    cout << "printing sudoku array: " << endl;

    // print initial arary.
    printArray(sudokuArray);




}

/*
RULES:


*/

void findCandidates(char arr[SIZE][SIZE][SIZE]) {

}

void printArray(char sudokuArray[SIZE][SIZE+1][SIZE]) {
    //char top_bar = "  -----   -----   -----  ";
    //top_bar = "";

    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        if (row != 0 && row % 3 == 0) { cout << endl; }
        for (int column = 0; column < 9; column++) {
            if (column % 3 == 0) { cout << "  "; }
            cout << sudokuArray[row][0][column] << " ";
        }
        cout << endl;
    }
    cout << "here is the junk values for [1][1][1]: " << sudokuArray[0][0][0];
    //cout << top_bar << endl;
}

/*
  -----   -----   -----
| 0 0 0 | 0 0 0 | 0 0 0 |
| 0 0 0 | 0 0 0 | 0 0 0 |
| 0 0 0 | 0 0 0 | 0 0 0 |
  ----- + ----- + -----
| 0 0 0 | 0 0 0 | 0 0 0 |
| 0 0 0 | 0 0 0 | 0 0 0 |
| 0 0 0 | 0 0 0 | 0 0 0 |
  ----- + ----- + -----
| 0 0 0 | 0 0 0 | 0 0 0 |
| 0 0 0 | 0 0 0 | 0 0 0 |
| 0 0 0 | 0 0 0 | 0 0 0 |
  -----   -----   -----
*/

/*
  ---------------------------------------------------
| 123 - 123 - 123 | 123 - 123 - 123 | 123 - 123 - 123 |
| 456 - 456 - 456 | 456 - 456 - 456 | 456 - 456 - 456 |
| 789 - 789 - 789 | 789 - 789 - 789 | 789 - 789 - 789 |
| --------------- + --------------- + --------------- |
| 123 - 123 - 123 | 123 - 123 - 123 | 123 - 123 - 123 |
| 456 - 456 - 456 | 456 - 456 - 456 | 456 - 456 - 456 |
| 789 - 789 - 789 | 789 - 789 - 789 | 789 - 789 - 789 |
| --------------- + --------------- + --------------- |
| 123 - 123 - 123 | 123 - 123 - 123 | 123 - 123 - 123 |
| 456 - 456 - 456 | 456 - 456 - 456 | 456 - 456 - 456 |
| 789 - 789 - 789 | 789 - 789 - 789 | 789 - 789 - 789 |
  ---------------------------------------------------
*/