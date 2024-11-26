// Problem: Largest black subrectangle
// Description
// A Rectangle of size n x mis divided into unit-square 1 x 1 with two colors black and white. The rectangle is represented by a matrix A(nx m) in which A(i, j) = 1 means that the unit-square at row i, column jis black and A(i, j) = 0 means that the unit-square at row icolumn jis white.
// Find the sub-rectangle of the given rectangle containing only black unit-squares such that the area is maximal.
// Input
// •Line 1: contains 2 positive integers nand m(1 <= n, m<= 1000)
// •Line i+1 (i= 1,…, n): contains the ith of the matrix A
// Output
// Write the area of the sub-rectangle found.

// Example 
// Input
// 4 4
// 0 1 1 1
// 1 1 1 0
// 1 1 0 0
// 1 1 1 0
// Output
// 6
// ---------------------------
// Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
// Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
// Dữ liệu
// · Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 1000)
// · Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
// Kết quả
// · Ghi ra diện tích của hình chữ nhật lớn nhất tìm được
// Ví dụ
// Dữ liệu
// 4 4
// 0 1 1 1
// 1 1 1 0
// 1 1 0 0
// 1 1 1 0
// Kết quả
// 6

#include <bits/stdc++.h>

using namespace std;

int n, m; 
vector<vector<int> > A; 
vector<int> height; 
int res = 0; 

int largestArea() {
    stack<int> st;
    int maxArea_row = 0;
    int size = height.size();
    
    for (int i = 0; i < size; i++) {
        while (!st.empty() && height[i] < height[st.top()]) {
            int h = height[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1; 
            maxArea_row = max(maxArea_row, h * width); 
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        int h = height[st.top()];
        st.pop();
        int width = st.empty() ? size : size - st.top() - 1; 
        maxArea_row = max(maxArea_row, h * width);
    }
    
    return maxArea_row;
}

void SOLVE() {
    height.assign(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            height[j] = (A[i][j] == 0) ? 0 : height[j] + 1;
        }
        
        res = max(res, largestArea());
    }
}

int main(int argc, char const *argv[]){
    cin >> n >> m;

    A.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    
    SOLVE();
    cout << res;
    
    return 0;
}
