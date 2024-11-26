// Problem: Gold Mining
// Description
// The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2,..., n. The warehouse i has amount of ai
//  (aiai is non-negative integer) and is located at coordinate i (i=1,...,n). The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds with respect to the condition that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.
// Input
// Line 1 contains n, L1, and L2 (1≤n≤1000000,1≤L1≤L2≤n)
// Line 2 contains n integers a1,a2,…,n
// Output
// Contains only one single integer denoting the total amount of golds of selected warehouses.
// Example
// Input
// 6 2 3
// 3 5 9 6 7 4

// Output
// 19

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000005;

int n, L1, L2;
int a[MAX], dp[MAX];
vector<int> b[MAX];

void SOLVE(){
    for (int i = 1; i <= L1; i++){
        dp[i] = a[i];
    }

    priority_queue<int> Q;
    Q.push(a[1]);
    for (int i = L1 + 1; i <= n; i++){
        int t = Q.top();
        dp[i] = t + a[i];
        Q.push(dp[i-L1+1]);
    }
    
    int res = 0;
    for(int i = n - L2; i <= n; i++){
        res = max(res, dp[i]);
    }
    cout << res;
}

int main(int argc, const char** argv) {
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    SOLVE();

    return 0;
}

