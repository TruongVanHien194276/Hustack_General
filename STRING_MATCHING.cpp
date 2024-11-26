// Problem: String Matching
// Description
// Given a string T and a pattern P which is also a string. Find the number of occurrences of P in T.
// Input
// Line 1: contains string P (length is less than or equals to 10^5)
// Line 2: contains the string T (length is less than or equals to 10^6)
// Output
// Write the number of occurrences of P in T
// Exmple
// Input
// computer
// There are so many kinds of computers today including high performance computers, laptop computers. Mobile phones are also computers
// Output
// 4

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    string p, t;
    getline(cin, p);
    getline(cin, t);

    int n = p.size();
    int m = t.size();
    vector<int> f(n, 0);
    for (int i = 1; i < n; i++) {
        int j = f[i - 1];
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) j++;
        f[i] = j;
    }

    int res = 0;
    for (int i = 0, j = 0; i < m; i++) {
        while (j > 0 && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) j++;
        if (j == n) {
            res++;
            j = f[j - 1];
        }
    }

    cout << res;
    return 0;
}