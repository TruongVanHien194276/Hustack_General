// Problem: Add two integers
// Description
// Compute the sum of two integers a and b.
// Input
// Line 1 contains two integers a and b (0 <= a, b <= 10^19)
// Ouput
// Write the sum of a and b
// Example
// Input
// 3 5
// Output
// 8

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long s1 = a / 10 + b / 10;
    unsigned long long s2 = a % 10 + b % 10;
    if (s1 != 0){
        if (s2 / 10 == 1) {
            cout << s1 + 1 << s2 % 10;
        } else cout << s1 << s2;
    } else cout << s2;

    return 0;
}