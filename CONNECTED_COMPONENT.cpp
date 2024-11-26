// Problem: Connected Components of undirected graphs
// Description
// Given a undirected graph G=(V,E) where V={1,. . .,N} is the number of nodes and the set E has M edges. Compute the number of connected components of G.
// Input
// Line 1: two positive integers N and M (1 <= N <= 10^5, 1 <= M <= 10^5)
// Line i+1 (i=1, . . .,M): contains two positive integers u and v which are endpoints of ith edge
// Output
// Write the number of connected components of G.

// Example
// Input
// 8 8
// 1 2
// 1 7
// 1 8
// 2 7
// 4 5
// 4 6
// 5 6
// 7 8

// Output
// 3

#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

vector<vector<int> > Graph;
int n, m;
bool visited[MAX];

void inputData(){
    cin >> n >> m;
    Graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
}

void DFS(int u){
    visited[u] = true;
    for (int v : Graph[u]){
        if (!visited[v]) DFS(v);
    }
}

int main(int argc, const char** argv) {
    inputData();
    memset(visited, false, sizeof(visited));

    int res = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            DFS(i);
            res++;
        }
    }
    cout << res;
    
    return 0;
}
