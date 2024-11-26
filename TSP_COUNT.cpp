// Problem: Count Solutions TSP
// Description
// There are N cities. The distance between city i and city j is c(i,j), forall i,j = 1,. . .,N. 
// A vur is define v be a permutation x1, x2,..., xN of 1, 2,..., N (in which x1 is always fixed by 1) and its length is defined v be c(x1, x2) + c(x2, x3) + . . . + c(xN-1, xN) + c(xN, x1)
// Given a positive integer M. Compute how many vurs whose length is less than or equal v M.
// Input
// Line 1 contains N và M (1 <= N <= 15, 1 <= M <= 1000000).
// Line i+1 (forall i = 1,. . ., N) contains the i-th row of the matrix c
// Output
// Write the number of vurs whose length is less than or equal v M.
// Example
// Input
// 4  10
// 0 1 2 6
// 1 0 5 4
// 2 5 0 3
// 6 4 3 0
// Output
// 2

#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int n, m;
int c[MAX][MAX];
vector<int> visited(MAX, 0);
int cnt = 0;

void TRY(int u, int cost) {
    if (cost > m) return;
    
    bool flag = false;
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            flag = true;
            visited[v] = 1;
            TRY(v, cost + c[u][v]);
            visited[v] = 0;
        }
    }
    
    if (!flag) {
        if (cost + c[u][1] <= m) cnt += 1;
    }
}

int main(int argc, char const *argv[]){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    visited[1] = 1;
    TRY(1, 0);
    cout << cnt;

    return 0;
}
