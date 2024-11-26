// Problem: Bounding rectangle
// Description
// Cho một danh sách các hình chữ nhật 1, 2,…, n. Hãy tìm diện tích hình chữ nhật nhỏ nhất bao tất cả các hình chữ nhật trong danh sách trên
// Dữ liệu
// · Dòng 1: chứa số nguyên dương n (1 <= n <= 1000)
// · Dòng i+1 (i=1,…,n): chứa 4 số nguyên dương x1,y1, x2,y2 trong đó (x1,y1) và (x2,y2) là tọa độ 2 đỉnh đối của hình chữ nhật thứ i (1 <= x1, y1, x2, y2 <= 100)
// Kết quả
// · Ghi ra diện tích của hình chữ nhật nhỏ nhất tìm được
// Ví dụ
// Dữ liệu
// 3
// 2 4 2 7
// 3 2 4 7
// 1 2 5 2
// Kết quả
// 20

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cin >> n;

    int min_x = 101, min_y = 101, max_x = 0, max_y = 0;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        min_x = min(min_x, min(x1, x2));
        max_x = max(max_x, max(x1, x2));
        min_y = min(min_y, min(y1, y2));
        max_y = max(max_y, max(y1, y2));
    }

    int area = (max_x - min_x) * (max_y - min_y);
    cout << area << endl;

    return 0;
}
