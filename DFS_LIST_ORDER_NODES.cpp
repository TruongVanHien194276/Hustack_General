// Problem: List order of nodes visited by a DFS
// Description
// Given a undirected graph =(V,E) in which V = {1,2,..,n} is the set of nodes. Write a program that visit nodes of G by a DFS (consider a lexicorgraphic order of nodes).
// Input
// Line 1: contains 2 integers n and m (1 <= n,m <= 100000)
// Line i+1: contains u and v which are two end-points of the ith edge

// Output
// Sequence of nodes visited by DFS
// Example
// Input
// 7 12
// 1 2
// 1 3
// 2 3
// 2 4
// 2 7
// 3 5 
// 3 7
// 4 5
// 4 6
// 4 7
// 5 6
// 5 7 
// Output
// 1 2 3 5 4 6 7

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

vector<int> Graph[MAX]; 
bool visited[MAX]; 

void DFS(int u) {
    visited[u] = true;
    cout << u << " "; 
    for (int v : Graph[u]) {
        if (!visited[v]) DFS(v);
    }
}

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u); 
    }
    
    for (int i = 1; i <= n; i++) {
        sort(Graph[i].begin(), Graph[i].end());
    }

    DFS(1);
    
    return 0;
}
