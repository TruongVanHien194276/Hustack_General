// Problem: Permutation generation
// Description
// Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
// Example
// Input 
// 3
// Output
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

void print(){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void TRY(int x){
    for (int i = 1; i <= n; i++){
        bool ok = true;
        for (int k = 0; k < x; k++){
            if (a[k] == i){
                ok = false;
                break;
            }
        }
        if (ok){
            a[x] = i;
            if (x == n-1) print();
            else TRY(x+1);
        }
    }
}

int main(int argc, char const *argv[]){
    cin >> n;
    a.resize(n);

    TRY(0);

    return 0;
}