// Problem: Longest Path on a Tree
// Description
// Given a undirected tree G = (V, E) in which V = (1,…,N) is the set of nodes. Each edge (u,v) in E has weight w(u,v). 
// The length of a path is defined to be the sum of weights of edges of this path. Find the longest elementary path on G.
// Input
// Line 1: positive integer N (1 <= N <= 10^5)
// Line i+1: (i = 1,…,N-1): positive integers u, v, w in which w is the weight of edge (u,v) (1 ≤ w ≤ 100)
// Output
// The weight of the longest path on the given tree
// Example
// Input
// 6 
// 1 3 3
// 1 6 2 
// 2 6 5 
// 4 5 2
// 4 6 1
// Output
// 10

#include <bits/stdc++.h>

using namespace std;

const int maxN = 100010;
const int maxW = 110;

int N;
vector<int> a[maxN];
vector<int> c[maxN];
int d[maxN], p[maxN];

void BFS(int u){
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        int a_leng = a[v].size();
        for (int i = 0; i < a_leng; i++){
            int x = a[v][i];
            if (p[x] > -1) continue;
            Q.push(x);
            int w = c[v][i];
            d[x] = d[v] + w;
            p[x] = v;
        }
    }
}

int find_max(){
    int max_d = -1;
    int u = -1;
    for (int v = 1; v <= N; v++){
        if (max_d < d[v]){
            max_d = d[v];
            u = v;
        }
    }
    return u;
}

int SOLVE(){
    memset(d, -1, sizeof(d));
    memset(p, -1, sizeof(p));
    BFS(1);

    int u = find_max();
    memset(d, -1, sizeof(d));
    memset(p, -1, sizeof(p));
    BFS(u);

    return d[find_max()];
}

int main(int argc, char const *argv[]){
    cin >> N;
    for (int i = 1; i <= N-1; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(y);
        c[x].push_back(w);
        a[y].push_back(x);
        c[y].push_back(w);
    }

    cout << SOLVE();
    return 0;
}
