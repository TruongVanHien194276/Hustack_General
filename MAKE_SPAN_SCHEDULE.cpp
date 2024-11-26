// Problem: Make Span Schedule
// Description
// A project has n tasks 1,. . ., n. Task i has duration d(i) to be completed (i=1,. . ., n). There are precedence constraints between tasks represented by a set Q of pairs: for each (i,j)  in Q, task j cannot be started before the completion of task i. Compute the earliest completion time  of the project.
// Input
// Line 1: contains n and m (1 <= n <= 10^4, 1 <= m <= 200000)
// Line 2: contains d(1),. . ., d(n) (1 <= d(i) <= 1000)
// Line i+3 (i=1,. . ., m) : contains i and j : task j cannot be started to execute before the completion of task i
// Output
// Write the earliest completion time of the project.
// Example
// Input
// 9 13
// 5 3 1 2 6 4 3 1 4
// 1 3
// 1 5
// 1 6
// 2 1
// 2 3
// 3 5
// 4 1
// 4 2
// 4 6
// 5 8
// 7 9
// 9 5
// 9 8

// Output
// 18

#include <bits/stdc++.h>

using namespace std;

int n, m;  
vector<int> d; 
vector<vector<int> > Graph; 
vector<int> degree; 
vector<int> dp;  

void input_data() {
    cin >> n >> m;
    d.resize(n + 1);
    Graph.resize(n + 1);
    degree.resize(n + 1, 0);
    dp.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v); 
        degree[v]++; 
    }
}

void cal_earliest_time() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : Graph[u]) {
            degree[v]--;
            if (degree[v] == 0) q.push(v);  

            dp[v] = max(dp[v], dp[u] + d[u]);
        }
    }
}

int SOLVE() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i] + d[i]);
    }
    return res;
}

int main(int argc, char const *argv[]){
    input_data();
    cal_earliest_time();
    cout << SOLVE();
    return 0;
}
