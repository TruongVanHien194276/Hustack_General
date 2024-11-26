// Problem: Tree manipulation count leaves and kChild nodes
// Description
// Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
// · MakeRoot u: Tạo ra nút gốc u của cây
// · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
// · CountLeaves u:  đếm và trả ra số nút lá trên cây có gốc là u
// · CountKChildren u k: đếm và trả về số nút có đúng k nút con trên cây gốc u
// Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
// · Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
// · Kết quả: ghi ra mỗi dòng kết quả của các lệnh CountLeaves và CountKChildren tương ứng đọc được từ đầu vào
// Ví dụ:
// Dữ liệu
// MakeRoot 10
// Insert 11 10
// Insert 1 10
// Insert 3 10
// Insert 5 11
// Insert 4 11
// CountLeaves 4
// CountKChildren 10 3
// Insert 8 3
// Insert 2 3
// Insert 7 3
// Insert 6 4
// Insert 9 4
// CountKChildren 10 3
// CountLeaves 10
// CountLeaves 3
// *
// Kết quả
// 1
// 1
// 2
// 7
// 3

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> root;

int CountLeaves(int u) {
    if (root.find(u) == root.end() || root[u].empty()) return 1;

    int cnt = 0;
    for (int child : root[u]) {
        cnt += CountLeaves(child);  
    }
    return cnt;
}

int CountKChildren(int u, int k) {
    int cnt = 0;
    if (root.find(u) != root.end()) {
        int childCount = root[u].size();
        if (childCount == k) cnt++;

        for (int child : root[u]) {
            cnt += CountKChildren(child, k);
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]){
    string cmd;
    int u, v;
    
    while (cin >> cmd) {
        if (cmd == "MakeRoot") {
            cin >> u;
            root.clear(); 
            root[u] = {};  
        } else if (cmd == "Insert") {
            cin >> u >> v;
            root[v].push_back(u); 
            root[u] = {};  
        } else if (cmd == "CountLeaves") {
            cin >> u;
            cout << CountLeaves(u) << endl;
        } else if (cmd == "CountKChildren") {
            int k;
            cin >> u >> k;
            cout << CountKChildren(u, k) << endl;
        } else break;
    }

    return 0;
}
