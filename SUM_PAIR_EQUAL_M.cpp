// Problem: Sum pair of sequence equal to a number
// Description
// Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

// Dữ liệu
// Dòng 1: ghi n và M (1 <= n, M <= 1000000)
// Dòng 2: ghi a1, a2, ..., an
// Kết quả
// Ghi ra giá trị Q
// Ví dụ
// Dữ liệu
// 5 6
// 5 2 1 4 3
// Kết quả
// 2

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<int, int> cnt;
    int res = 0;
    for (int i = 0; i < n; i++){
        if (cnt[M - a[i]] > 0) res += cnt[M - a[i]];
        cnt[a[i]] += 1;
    }

    cout << res << endl;

    return 0;
}