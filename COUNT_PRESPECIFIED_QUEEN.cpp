// Problem: Count Queen Solutino with some specified queens
// Description
// Count number of solutions to place n queens on a chess board n x n (rows and columns are indexed 1, 2, 3, ..., n) such that no two queens attach each other.
// Input
// Line 1: a positive integer n (1 <= n <= 20)
// Line 2: a positive integer K (1 <= K <= 20)
// Line k+2 (k=1, 2, ..., K): contains two integers r and c in which there is a queen in column c and row r.
// Output
// Write number of solutions found.
// Example
// Input
// 5
// 1
// 2  1
// Output
// 2

#include <bits/stdc++.h>
using namespace std;

int n, K, cnt = 0;
vector<int> colUsed, d1, d2;  // column, diagonal 1 (row - col), diagonal 2 (row + col)
vector<int> board;        

bool checkPlace(int r, int c) {
    return !colUsed[c] && !d1[r - c + n - 1] && !d2[r + c];
}

void TRY(int r) {
    if (r == n) {
        cnt++;
        return;
    }

    if (board[r] != -1) {
        TRY(r + 1);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (checkPlace(r, c)) {
            colUsed[c] = d1[r - c + n - 1] = d2[r + c] = 1;
            TRY(r + 1);
            colUsed[c] = d1[r - c + n - 1] = d2[r + c] = 0;
        }
    }
}

bool checkConflict() {
    for (int r = 0; r < n; r++) {
        if (board[r] != -1) {
            int c = board[r];
            if (!checkPlace(r, c)) return false;  // conflict found
            colUsed[c] = d1[r - c + n - 1] = d2[r + c] = 1;
        }
    }
    return true;  // no conflict
}

int main(int argc, char const *argv[]){
    cin >> n >> K;

    colUsed.resize(n, 0);
    d1.resize(2 * n - 1, 0);
    d2.resize(2 * n - 1, 0);
    board.resize(n, -1);  

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--; 
        board[r] = c; 
    }

    if (checkConflict()) TRY(0);

    cout << cnt << endl;

    return 0;
}
