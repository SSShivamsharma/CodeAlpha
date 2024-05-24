// soduku solver in c++
#include <iostream>
#include <vector>
using namespace std;
const int N = 9;
void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    // Check  box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}
// backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    bool isEmpty = false;
   //empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
//    solved pr not 
    if (!isEmpty) {
        return true;
    }
    // placing numbers
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            // rec solve
            if (solveSudoku(grid)) {
                return true;
            }
            // backtrack when no solution
            grid[row][col] = 0;
        }
    }
    return false;
}
int main() {
    // grid 
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    if (solveSudoku(grid)) {
        cout << "Sudoku solved:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the Sudoku.\n";
    }
    return 0;
}
