// Problem: Find sum of number NVT
// Description
// Chương trình tính tổng n số nguyên (integer) nhập từ bàn phím
// Input:
// n: số số nguyên sẽ nhập từ bàn phím (1 <= n <= 10)
// a1, a2, ..., an các số nguyên
// Output:
// sum
// Ví dụ:
// Input:
// 3
// 1 2 3
// Output:
// 6

#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}
