// Problem: Minimum Spanning Tree - Kruskal
// Description
// Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E has weight w(u,v). Compute minimum spanning tree of G.
// Input
// Line 1: N and M (1≤N,M≤10^5) in which NN is the number of nodes and MM is the number of edges.
// Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
// Output
// Write the weight of the minimum spanning tree found.
// Example
// Input
// 5 8
// 1 2 1
// 1 3 4
// 1 5 1
// 2 4 2
// 2 5 1
// 3 4 3
// 3 5 3
// 4 5 2
// Output
// 7

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

int parent[MAX], r[MAX];

int find(int u) {
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (r[u] > r[v]) parent[v] = u;
    else if (r[u] < r[v]) parent[u] = v;
    else {
        parent[v] = u;
        r[u]++;
    }
}

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int> > > edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v))); 
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        r[i] = 0;
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if (find(u) != find(v)) {
            merge(u, v);
            res += w;
        }
    }

    cout << res;

    return 0;
}