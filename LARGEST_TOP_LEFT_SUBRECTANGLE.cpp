// Problem: Top-Left 1-SubRectangle
// Description
// Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng (hàng, cột được đánh số từ 1, 2, …).
// Một hình chữ nhật con của bảng được định nghĩa là hình chữ nhật có ô góc trên bên trái là ô (1,1).
// Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
// Dữ liệu
// · Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 50)
// · Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
// Kết quả
// · Ghi ra diện tích của hình chữ nhật lớn nhất tìm được
// Ví dụ
// Dữ liệu
// 5 7
// 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1
// 1 1 1 1 1 0 1
// 1 1 1 0 1 0 1
// 1 1 1 1 1 1 1
// Kết quả
// 15

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m;
int a[N][N], f[N][N];
int res = 0;

int main(int argc, char const *argv[]){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m ; j++) {
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i * j == f[i][j]) res = max(res, i * j);
        }
    }

    cout << res;
    return 0;
}