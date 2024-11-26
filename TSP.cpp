// Problem: Chapter 2 - TSP
// Description
// There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.
// Input
// Line 1: a positive integer n (1 <= n <= 20)
// Linr i+1 (i = 1, . . ., n): contains the i-th row of the distance matrix x (elements are separated by a SPACE character)
// Output
// Write the total travel distance of the optimal itinerary found.
// Example
// Input
// 4
// 0 1 1 9
// 1 0 9 3
// 1 9 0 2
// 9 3 2 0
// Output
// 7

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<vector<int> > c;
vector<int> x;
vector<bool> mark;
int f = 0;
int f_min = INF;
int c_min = INF;

void inputData() {
    cin >> n;
    c.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] < c_min && i != j) {
                c_min = c[i][j];
            }
        }
    }
}

void updateBest() {
    if (f + c[x[n]][x[1]] < f_min) {
        f_min = f + c[x[n]][x[1]];
    }
}

void TRY(int k) {
    for (int v = 1; v <= n; v++) {
        if (!mark[v]) {
            x[k] = v;
            f = f + c[x[k-1]][x[k]];
            mark[v] = true;

            if (k == n) updateBest();
            else {
                int gk = f + c_min * (n - k);
                if (gk < f_min) TRY(k+1);
            }

            f = f - c[x[k-1]][x[k]];
            mark[v] = false;
        }
    }
}

int main(int argc, char const *argv[]){
    inputData();
    mark.assign(n+1, false);
    x.resize(n+1);

    x[1] = 1;
    mark[1] = true;
    
    TRY(2);
    cout << f_min;

    return 0;
}
