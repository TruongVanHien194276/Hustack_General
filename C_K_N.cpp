// Problem: Compute C_k_n
// Description
// Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
// Input
// Line 1: two positive integers k and n (1 <= k,n <= 999)
// Output
// Write te value C(k,n) modulo 10^9+7.
// Example
// Input
// 3  5
// Output
// 10

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

// Tính (x^y)%p
unsigned long long power(unsigned long long x, int y){
    unsigned long long res = 1;
    x = x % MOD;
 
    while (y > 0){
        if (y & 1) res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}
 
// Tính nghịch đảo theo modulo p của n: inv(n) = n^(p-2) % MOD
unsigned long long modInverse(unsigned long long n){
    return power(n, MOD - 2);
}

// Tính nCk % p sử dụng định lý Fermat nhỏ
unsigned long long SOLVE(unsigned long long n, int k){
    if (n < k) return 0;
    if (k == 0) return 1;
 
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    return (fac[n] * modInverse(fac[k]) % MOD * modInverse(fac[n - k]) % MOD) % MOD;
}
 

int main(int argc, const char** argv) {
    int k, n;
    cin >> k >> n;
    cout << SOLVE(n, k);
    return 0;
}