// Problem: Hash Over Strings
// Description
// Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}. Given a positive integer m, the hash code of s is defined by the formula:
// H(s) =  (s[1]*256^(k-1)+ s[2]*256^(k-2)  + . . . + s[k]*256^0 ) mod m  (the contant integer m is a parameter)
// Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes
// Input
// Line 1: n and m (1 <= n,m <= 100000)
// Line i+1 (i = 1,2,…,n): contains the string ki (the length of each string is less than or equal to 200)
// Output
// Each line contains the corresponding hash code of n given strings
// Example
// Input
// 4 1000
// a
// ab
// abc
// abcd
// Output
// 97
// 930
// 179
// 924

#include <bits/stdc++.h>

using namespace std;

int n, m;

int compute_hash(string& s) {
    int h = 0;
    for (int i = 0; i < s.length(); i++) {
        h = h * 256 + s[i];
        h %= m;
    }
    return h;
}

int main(int argc, char const *argv[]){
    cin >> n >> m;  

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str; 
        cout << compute_hash(str) << endl;  
    }

    return 0;
}
