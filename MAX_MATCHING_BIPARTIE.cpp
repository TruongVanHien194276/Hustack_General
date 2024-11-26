// Problem: Max Matching on Bipartie Graph
// Description
// There are  n tasks 1,. . .,n and m staffs 1, . . , m. T(i) is the set of staffs that can perform the task i (i=1, . . ., n). Compute an assignment of staffs to tasks such that each task is assigned to at most one staff and each staff cannot be assigned to more than one task and the number of tasks assigned is maximal.
// Input
// Line 1: contains 2 positive integer n và m (1 <=  n,m <= 10000)
// Line i+1 (i=1, . . .,n) contains a positive integer k and k integer of T(i)
// Output
// Write the maximum number of tasks that are assigned to staffs.
// Example
// Input
// 3 4
// 2 1 4
// 2 1 3
// 1 2

// Output
// 3

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;

vector<int> Graph[MAX]; 
int match[MAX];  
bool visited[MAX];  

bool DFS(int u) {
    for (int v : Graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || DFS(match[v])) {
                match[v] = u;  
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        Graph[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> Graph[i][j]; 
        }
    }

    memset(match, -1, sizeof(match));  
    
    int res = 0;
    for (int u = 1; u <= n; u++) {
        memset(visited, 0, sizeof(visited));  
        if (DFS(u)) res++;  
    }
    
    cout << res;
    return 0;
}
