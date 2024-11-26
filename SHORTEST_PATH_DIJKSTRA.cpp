// Problem: Shortest Path between 2 nodes on a directed graph with non-negative weights
// Description
// Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes. Each arc (u,v) has a non-negative weight w(u,v). Given two nodes s and t of G. Find the shortest path from s to t on G.
// Input
// Line 1: contains two integers n and m which are the number of nodes and the number of arcs of G (1 <= n <= 100000)
// Line i + 1(i = 1,2,...,m): contains 3 integers u, v, w in which w is the weight of arc(u,v) (0 <= w <= 100000)
// Line m+2: contains two integers s and t
// Output
// Write the weight of the shortest path found or write -1 if no path from s to t was found
// Example
// Input
// 5 7
// 2 5 87
// 1 2 97
// 4 5 78
// 3 1 72
// 1 4 19
// 2 3 63
// 5 1 18
// 1 5

// Output
// 97

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

struct comp{
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int n, m;
vector<vector<pair<int, int> > > Graph;
int s, t;

void inputData(){
    cin >> n >> m;
    Graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }

    cin >> s >> t;
}

int DijkstraAlgorithm(){
    priority_queue<pair<int, int>, vector< pair<int, int> >, comp> q;
    int dist[MAX];

    for (int i = 1; i <= n; i++){
        dist[i] = 1e9;
    }
    dist[s] = 0;
    for (int i = 1; i <= n; i++){
        q.push({i, dist[i]});
    }

    while (!q.empty()){
        pair<int, int> x = q.top(); 
        q.pop();
        int x_point = x.first;

        for (auto v : Graph[x_point]){
            int v_point = v.first;
            int v_dist = v.second;

            if (dist[v_point] > dist[x_point] + v_dist){
                dist[v_point] = dist[x_point] + v_dist;
                q.push({v_point, dist[v_point]});
            }
        }
    }

    return dist[t];
}

int main(int argc, const char** argv) {
    inputData();
    cout << DijkstraAlgorithm();
    return 0;
}