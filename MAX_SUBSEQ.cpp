// Problem: Max SubSequence
// Description
// Given an integers sequence a=(a1, a2,…, an). A subsequence of a is defined to be ai, ai+1,…, aj. 
// The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.
// Input
// Line 1 contains n (1≤n≤10^6)
// Line 2 contains a1,…,an (−500≤ai≤500)
// Output
// Write the weight of the highest subsequence found.
// Example
// input
// 10
// 3 -1 -3 5 2 5 0 -1 5 4
// output
// 20


#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000010;

int n;
int a[MAX], s[MAX];

int MaxSub(){
    s[1] = a[1];
    int res = s[1];
    for (int i = 2; i <= n; i++){
        if (s[i-1] > 0) s[i] = s[i-1] + a[i];
        else s[i] = a[i];

        res = max(res, s[i]);
    }
    return res;
}

int main(int argc, const char** argv) {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << MaxSub();
    return 0;
}


