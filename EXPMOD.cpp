// Problem: EXPMOD
// Description
// Given two positive integers a and b. Compute a^b mod (10^9 + 7)
// Input
// One line contains two integers a and b (1 <= a,b <= 18446744073709551614)
// Output
// The value a^b mod (10^9+7)
// Example
// Input
// 2  3
// Output
// 8

#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;

unsigned long long sqr(unsigned long long x) {
    return x*x;
}
 
unsigned long long power(unsigned long long a, unsigned long long b) {
    if (b == 0) return 1 % MOD;
    else {
        if (b % 2 == 0) return sqr(power(a, b/2)) % MOD;
        else return a * (sqr(power(a, b/2)) % MOD) % MOD;
    }
}
 
int main(int argc, const char** argv) {
    unsigned long long a, b;
    cin >> a >> b;

    a %= MOD;
    b %= MOD - 1;
    cout << power(a, b);
    
    return 0;
}
