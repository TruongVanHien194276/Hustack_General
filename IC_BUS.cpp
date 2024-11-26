// Problem: Bus inter-city
// Description
// Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng. 
// Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
// Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất
// Input
// Dòng 1: chứa 2 số nguyên dương n và m trong đó n là số thành phố và m là số con đường kết nối các thành phố (1 <= n <= 5000, 1 <= m <= 10000)
// Dòng i+1 (i = 1,2,...,n): chứa 2 số nguyên dương C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
// Dòng n+1+i (i = 1, 2, ..., m): chứa 2 số nguyên dương i và j trong đó giữa thành phố i và j có con đường kết nối
// Output
// Số tiền tối thiểu phải bỏ ra để đi buýt từ thành phố 1 đến thành phố n

// Example
// Input
// 6 6
// 10 2
// 30 1
// 50 1
// 20 3
// 30 1
// 20 1
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 4 6
// Output
// 30

// Giải thích: 
// -Lên buýt 1 từ thành phố 1 đến thành phố 4 mất 10 đồng
// -Lên buýt 4 từ thành phố 4 đến thành phố 6 mất 20 đồng
// Tổng cộng mất 10 + 20 = 30 đồng

#include <bits/stdc++.h>

using namespace std;

const int MAX = 5010;

int n, k;
int D[MAX], C[MAX];
vector<vector<int> >a;
int dist[MAX][MAX];
int res[MAX], visited[MAX];

void inputData(){
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }

    a.resize(n + 1, vector<int>(0));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void BFS(int source, int dist[]) {
    queue<int> Q;
    Q.push(source);
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;
    while (!Q.empty()) {
        int u = Q.front(); 
        Q.pop();
        for (int v : a[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

void cal_dist() {
    for (int u = 1; u <= n; ++u){
        BFS(u, dist[u]);
    }
}

void Dijkstra() {
    for (int i = 0; i <= n; ++i) {
        res[i] = INT_MAX;
        visited[1] = 0;
    }

    res[1] = 0;
    int step = n;
    while (step--) {
        int u = 0;
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 0 && res[u] > res[i]) {
                u = i;
            }
        }
        if (u == 0) break;
        visited[u] = 1;
        for (int v = 1; v <= n; ++v) {
            if (dist[u][v] <= D[u]) {
                res[v] = min(res[v], res[u] + C[u]);
            }
        }
    }
    cout << res[n];
}

int main(int argc, const char** argv) {
    inputData();
    cal_dist();
    Dijkstra();
    return 0;
}