#include <stdio.h>
#include <stdbool.h>

#define N 4 // Change this value to the desired board size (e.g., N=4 for 4x4 board)

// Function to print the board with queens placed
void printBoard(int board[N][N], int* p) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
    *p = *p +1;
}

// Function to check if a queen can be placed at a particular position (row, col)
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queen problem
bool solveNQueen(int board[N][N], int col, int* p) {
    // If all queens are placed then return true
    if (col >= N) {
        printBoard(board, p);
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place this queen in board[i][col]

            // Recur to place rest of the queens
            res = solveNQueen(board, col + 1, p) || res;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove the queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0}; // Initialize the board with zeros
    int n=0;
    int* p;
    p=&n;
    if (!solveNQueen(board, 0, p)) {
        printf("No solution exists for N=%d.\n", N);
    }
    printf("Number of solutions = %d", n);
    return 0;
}
