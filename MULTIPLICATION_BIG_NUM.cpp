// Problem: Multiplication of Big numbers
// Description
// Cho hai số nguyên dương a và b rất lớn (số chữ số có thể lên tới 10000). Hãy tính và in ra tích của 2 số đó.
// Input
// Dòng 1: ghi số a
// Dòng 2: ghi số b
// Output
// Ghi kết quả a*b

// Example
// Input
// 123
// 654

// Output
// 80442

// Example
// Input
// 100000000000000000
// 123456789
// Output
// 12345678900000000000000000

#include <bits/stdc++.h>

using namespace std;

string multiplyStrings(string& a, string& b) {
    int m = a.length();
    int n = b.length();
    vector<int> res(m + n, 0);

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1]; 
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10; 
        }
    }

    string res_str = "";
    for (int i = 0; i < res.size(); ++i) {
        if (!(res_str.empty() && res[i] == 0)) {
            res_str.push_back(res[i] + '0');
        }
    }

    return res_str.empty() ? "0" : res_str;
}

int main(int argc, char const *argv[]){
    string a, b;
    cin >> a >> b;

    cout << multiplyStrings(a, b);

    return 0;
}
