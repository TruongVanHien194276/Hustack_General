// Problem: Disjoint Segment
// Description
// Given a set of segments X = {(a1, b1), . . . , (an, bn)} in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in which no two segments of the subset intersect
// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line i+1 (i= 1,...,n): contains ai and bi (0 <= ai <= bi <= 1000000)
// Output
// Number of segments in the solution found.
// Example
// Input
// 6
// 0 10
// 3 7
// 6 14
// 9 11
// 12 15
// 17 19

// Output
// 4

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > s;
int n;

bool comp(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

int solve(){
    sort(s.begin(), s.end(), comp);
    int res = 0;
    int last = -1e9; 
    for (int i = 0; i < n; i++){
        if (s[i].first > last){
            res++;
            last = s[i].second;
        }
    }
    return res;
}

int main(int argc, const char** argv) {
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        s.push_back(make_pair(a, b));
    }

    cout << solve();
    return 0;
}