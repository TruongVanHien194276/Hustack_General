// Problem: Count solutions to an integer linear equation
// Description
// Given a positive integer n and n positive integers a1, a2, ..., an. Compute the number of positive integer solutions to the equation:
//                           a1X1 + a2X2 + . . . + anXn = M

// Input
// Dòng 1: n và M
// Dòng 2: a1, a2, ..., an
// Output
//    Số nghiệm nguyên dương
// Ví dụ
// Input
// 3 5
// 1 1 1
// Output
// 6

#include <bits/stdc++.h>

using namespace std;

int cnt_Solution(int n, int M, vector<int>& a) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int M_prime = M - sum;
    if (M_prime < 0) return 0;

    vector<int> dp(M_prime + 1, 0);
    dp[0] = 1; 
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= M_prime; j++) {
            dp[j] += dp[j - a[i]];
        }
    }

    return dp[M_prime];
}

int main(int argc, char const *argv[]){
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << cnt_Solution(n, M, a);

    return 0;
}
