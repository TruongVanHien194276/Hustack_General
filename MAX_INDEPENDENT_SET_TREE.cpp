// Problem: Max Independent Set on a Tree
// Description
// Cho cây T = (V,E) trong đó V = {1,…,n} là tập các đỉnh và E là tập gồm n-1 cạnh. Mỗi đỉnh v của đồ thị có trọng số w(v). Hãy chọn ra tập S các đỉnh sao cho hai đỉnh kề nhau không cùng được chọn và tổng trọng số các đỉnh được chọn là lớn nhất.
// Dữ liệu
// · Dòng 1: ghi số nguyên dương n (1 <= n <= 100000)
// · Dòng 2: ghi n số nguyên dương w(1), w(2), …, w(n) là trọng số các đỉnh tương ứng
// · Dòng i+2 (i = 1,…,n-1): ghi 2 số nguyên dương u và v là 2 đầu mút của cạnh thứ i của T
// Kết quả:
// · Ghi ra tổng trọng số của các đỉnh được chọn
// Ví dụ
// Dữ liệu
// 9
// 9 5 10 4 3 2 6 1 8
// 1 5
// 2 3
// 2 4
// 2 6
// 3 5
// 6 7
// 6 8
// 6 9
// Kết quả
// 38

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

vector<int> adj[MAX];
vector<int> w;     
vector<vector<int> > dp; 

void DFS(int u, int parent) {
    dp[u][0] = 0; 
    dp[u][1] = w[u];  
    
    for (int v : adj[u]) {
        if (v == parent) continue; 
        
        DFS(v, u); 
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    
    w.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.resize(n, vector<int>(2, 0)); 
    DFS(0, -1);

    cout << max(dp[0][0], dp[0][1]);

    return 0;
}
