// Problem: Simulation Mario movement
// Description
// Mario stands in a MAZE which is a grid of N x M cells including free cells and obstacle cells. The MAZE is represented by 0-1 matrix aNxM 
// in which a_i,j = 1 means that the cell (i,j)  (row i and column j) is an obstacle, and ai,j = 1 means that the cell row i and column j is an empty cell. 
// Mario executes a sequence of movements including:
// move-up: move from a current cell (r,c) to the cell (r-1,c) if this cell is an empty cell within the MAZE, otherwise, Mario does nothing (he stands at the current cell).
// move-down: move from a current cell (r,c) to the cell (r+1,c) if this cell is an empty cell within the MAZE, otherwise, Mario does nothing (he stands at the current cell).
// move-left: move from a current cell (r,c) to the cell (r,c-1) if this cell is an empty cell within the MAZE, otherwise, Mario does nothing (he stands at the current cell).
// move-right: move from a current cell (r,c) to the cell (r,c+1) if this cell is an empty cell within the MAZE, otherwise, Mario does nothing (he stands at the current cell).
// Find the last cell that Mario stands after the movements.
// Input
// Line 1: contains N, M, r, c in which N and M are numbers of rows and columns of the MAZE; r, c are the row and column indices of the cell that Mario stands at the beginning (1 <= r <= N <= 1000, 1 <= c <= M <= 1000)
// Line i+1 (i = 1, 2, ..., N): contains the ith row of the matrix a
// Subsequence lines (terminated by a line containing #), each line contains a string of types: move-up, move-down, move-left, move-right
// Output
// Write the row and column indices (separated by a SPACE character) of the last cell that Mario stands after the movements.
// Example
// Input
// 5 5 5 3
// 0 0 0 0 0
// 0 0 0 0 0
// 0 1 1 0 0 
// 0 0 0 0 0 
// 0 0 0 0 0
// move-up
// move-up
// move-left
// move-up
// move-left
// move-up
// #
// Output
// 3 1

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int N, M, r, c;
    cin >> N >> M >> r >> c;
    
    r--; c--;
    
    vector<vector<int> > a(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "move-up") {
            if (r > 0 && a[r-1][c] == 0) r--;  
        } else if (cmd == "move-down") {
            if (r < N-1 && a[r+1][c] == 0) r++;  
        } else if (cmd == "move-left") {
            if (c > 0 && a[r][c-1] == 0) c--;  
        } else if (cmd == "move-right") {
            if (c < M-1 && a[r][c+1] == 0) c++;  
        } else break;
    }

    cout << r+1 << " " << c+1;

    return 0;
}
