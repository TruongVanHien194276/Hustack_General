// Problem: Graph Isomophism
// Description
// Cho 2 đồ thị vô hướng G1 = (V1, E1) và G2 = (V2, E2) trong đó V1 = {1,…,n1} là tập đỉnh của G1 và G2 = {1,2,…,n2} là tập đỉnh của G2. Hai đồ thị được gọi là đẳng cấu nếu tồn tại một song ánh f từ V1 đến V2 sao cho (u,v) là cạnh của G1 khi vào chỉ khi (f(u), f(v)) là một cạnh của G2.
// Dữ liệu
// · Dòng 1: ghi số nguyên dương n1 và m1  (1 <= n1 <= 20, 1 <= m1 <= 40) tương ứng là số đỉnh và số cạnh của G1
// · Dòng thứ i+1 (i=1,…,n1): ghi 2 số nguyên dương u và v là đầu mút của cạnh thứ i của G1
// · Dòng thứ m1 + 2: ghi 2 số nguyên dương n2 và m2 (1 <= n2 <= 20, 1 <= m2 <= 40) tương ứng là số đỉnh và số cạnh của G2
// · Dòng thứ m1 + 2 + i (i = 1,…,m2): ghi 2 số nguyên dương u và v là đầu mút của cạnh thứ i của G2
// Kết quả
// · Ghi ra giá trị 1 nếu G1 và G2 đẳng cấu và ghi ra giá trị 0, nếu ngược lại
// Ví dụ
// Dữ liệu
// 4 5
// 1 2
// 1 3
// 2 3
// 2 4
// 3 4
// 4 5
// 1 2
// 1 3
// 1 4
// 2 3
// 3 4
// Kết quả
// 1

#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

vector<int> G1[MAX], G2[MAX];  
int n1, m1, n2, m2;            
vector<int> mapping(MAX, -1);  
vector<bool> visited(MAX, false); 

bool areIsomorphic() {
    for (int u = 0; u < n1; u++) {
        for (int v : G1[u]) {
            int mapped_u = mapping[u];
            int mapped_v = mapping[v];
            if (find(G2[mapped_u].begin(), G2[mapped_u].end(), mapped_v) == G2[mapped_u].end()) {
                return false;
            }
        }
    }
    return true;
}

bool TRY(int v) {
    if (v == n1) return areIsomorphic();

    for (int i = 0; i < n2; i++) {
        if (!visited[i]) {
            visited[i] = true;
            mapping[v] = i;

            if (TRY(v + 1)) return true;

            visited[i] = false;
        }
    }
    return false;
}

int main(int argc, char const *argv[]){
    cin >> n1 >> m1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--; 
        v--;  
        G1[u].push_back(v);
        G1[v].push_back(u);
    }

    cin >> n2 >> m2;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  
        G2[u].push_back(v);
        G2[v].push_back(u);
    }

    if (n1 != n2 || m1 != m2) {
        cout << 0;
        return 0;
    }

    if (TRY(0)) cout << 1; 
    else cout << 0; 

    return 0;
}
