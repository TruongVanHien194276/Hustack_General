// Problem: Range Minimum Query
// Description
// Given a sequence of n integers a0,. . .,an-1. 
// We denote rmq(i,j) the minimum element of the sequence ai, ai+1, . . .,aj. 
// Given m pairs (i1, j1),. . .,(im, jm), compute the sum Q = rmq(i1,j1) + . . . + rmq(im, jm)
// Input
// Line 1: n (1 <=  n <= 10^6)
// Line 2: a0, . . . ,an-1 ( 1  <=  ai <= 10^6)
// line 3: m (1  <= m <= 10^6)
// Line k+3 (k=1, . . ., m): ik, jk  (0  <=  ik < jk < n)
// Output
// Write the value Q
// Example
// Input
// 16
// 2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
// 4
// 1 5
// 0 9
// 1 15
// 6 10

// Output
// 6

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000010;

int n, a[MAX], m;
int start[MAX], finish[MAX];
int M[20][MAX];

void inputData(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        start[i] = tmp1;
        finish[i] = tmp2;
    }
}

void pre_processing(){
    for (int i = 0; i < n; i++) M[0][i] = i;

    for (int j = 1; (1<<j) <= n; j++){
        for (int i = 0; i+(1<<j)-1 < n; i++){
            if (a[M[j-1][i]] < a[M[j-1][i+(1<<(j-1))]]) M[j][i] = M[j-1][i];
            else M[j][i] = M[j-1][i + (1<<(j-1))];
        }
    }
}

int RMQ(int i, int j){
    int k = floor(log2(j-i+1));

    if (a[M[k][i]] <= a[M[k][j-(1<<k)+1]]) return a[M[k][i]];
    else return a[M[k][j-(1<<k)+1]];
}

int main(int argc, const char** argv) {
    inputData();
    pre_processing();

    int res = 0;
    for (int i = 0; i < m; i++){
        res += RMQ(start[i], finish[i]);
    }
    cout << res;

    return 0;
}
