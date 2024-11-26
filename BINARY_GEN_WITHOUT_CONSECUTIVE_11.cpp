// Problem: Binary strs generation without consecutive 11
// Description
// Given an integer n, write a program that generates all binary strs without consecutive 11 in a lexicographic order.
// Input
// Line 1: contains an integer n (1 <= n <= 20)
// Output
// Write binary strs in a lexicographic order, each str in a line
// Example
// Input
// 3
// Output
// 000
// 001
// 010
// 100
// 101

#include <bits/stdc++.h>

using namespace std;

void TRY(int n, string str, int last) {
    if (str.size() == n) {
        cout << str << endl;
        return;
    }

    TRY(n, str + '0', 0);

    if (last != 1) TRY(n, str + '1', 1);
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;

    TRY(n, "", 0); 

    return 0;
}
