// Problem: Compute Strongly Connected Components of directed graphs
// Description
// Given a directed graph G=(V,E) where V={1,. . ., N} is the number of nodes and the set E has M arcs. Compute number of strongly connected components of G
// Input
// Line 1: two positive integers N and M (1 <= N <= 10^5, 1 <= M <= 10^6)
// Line i+1 (i=1,. . ., M\): contains two positive integers u and v which are endpoints of ith arc
// Output
// Write the number of strongly connected components of G
// Example
// Input
// 8 13
// 1 2
// 1 8
// 2 3
// 2 6
// 3 6
// 4 3
// 4 6
// 5 4
// 6 5
// 7 1
// 7 2
// 7 6
// 8 7
// Output
// 3

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int n, m;
vector<vector<int> > a;
vector<vector<int> > b;
bool mark[MAX], check[MAX];
vector<int> c;

void DFS1(int u){
    mark[u] = false;
    for (int v : a[u]){
        if (mark[v]) {
            DFS1(v);
            c.push_back(v);
        }
    }
}

void DFS2(int u){
    mark[u] = false;
    for (int v : b[u]){
        if (mark[v]) DFS2(v);
    }
}

int main(int argc, const char** argv) {
    cin >> n >> m;
    a.resize(n+1);
    b.resize(n+1);

    memset(mark, true, sizeof(mark));
    memset(check, true, sizeof(check));

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        b[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        if (mark[i]){
            DFS1(i);
            c.push_back(i);
        }
    }

    memset(mark, true, sizeof mark);
    int res = 0;
    for (int i = c.size() - 1; i >= 0; i--){
        if (mark[c[i]]) {
            DFS2(c[i]);
            res++;
        }
    }
    cout << res;
    
    return 0;
}