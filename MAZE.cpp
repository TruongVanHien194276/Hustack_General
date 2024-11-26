// Problem: MAZE
// Description
// Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống. Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.

// Input
// Dòng 1: ghi 4 số nguyên dương n, m, r, c trong đó n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
// Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A

// Output
// Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.

// Ví dụ

// Input
// 8 12 5 6
// 1 1 0 0 0 0 1 0 0 0 0 1
// 1 0 0 0 1 1 0 1 0 0 1 1
// 0 0 1 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 1 0 0 1 0 1
// 1 0 0 1 0 0 0 0 0 1 0 0
// 1 0 1 0 1 0 0 0 1 0 1 0
// 0 0 0 0 1 0 1 0 0 0 0 0
// 1 0 1 1 0 1 1 1 0 1 0 1

// Output
// 7

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1010;

int n, m, c, r;
queue<pair<int, int>> q;
vector<vector<int>> A(MAX, vector<int>(MAX, -1));
vector<vector<int>> dis(MAX, vector<int>(MAX, -1));

int add(int a, int b, int c, int d) {
    if (a < 0 || a >= n || b < 0 || b >= m) return dis[c][d];
    else if (A[a][b] == 1 || dis[a][b] > -1) return 0;
    else {
        dis[a][b] = dis[c][d] + 1;
        q.push({a, b});
        return 0;
    }
}

int main(int argc, char const *argv[]){
    cin >> n >> m >> c >> r;
    c--;
    r--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    if (A[c][r] == 1) {
        cout << -1;
        return 0;
    } else {
        q.push({c, r});
        dis[c][r] = 1;
        while (q.size() > 0) {
            pair<int, int> top = q.front();
            c = top.first;
            r = top.second;
            q.pop();
            int res = add(c + 1, r, c, r);
            res = max(res, add(c, r + 1, c, r));
            res = max(res, add(c - 1, r, c, r));
            res = max(res, add(c, r - 1, c, r));
            if (res > 0) {
                cout << res;
                return 0;
            }
        }
        cout << -1;
    }

    return 0;
}