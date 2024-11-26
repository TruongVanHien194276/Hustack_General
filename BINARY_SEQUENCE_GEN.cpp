// Problem: Binary sequence generation
// Description
// Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
// Input
// Line 1: contains an integer n (1 <= n <= 20)
// Output
// Write binary sequences in a lexicographic ordder, eac sequence in a line

// Example
// Input
// 3
// Output
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

void print(){
    for (int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << endl;
}

void TRY(int x){
    for (int i = 0; i <= 1; i++){
        a[x] = i;
        if (x == n-1) print();
        else TRY(x+1);
    }
}

int main(int argc, char const *argv[]){
    cin >> n;
    a.resize(n);

    TRY(0);

    return 0;
}