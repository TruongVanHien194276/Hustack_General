// Problem: Tree manipulation query depth - height
// Description
// Mỗi nút trên 1 cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
// Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
// · MakeRoot u: Tạo ra nút gốc u của cây
// · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không thêm mới)
// · Height u:  Tính và trả về độ cao của nút u
// · Depth u: Tính và trả về độ sâu của nút u
// Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
// · Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
// · Kết quả: ghi ra mỗi dòng kết quả của các lệnh Height và Depth tương ứng đọc được từ đầu vào
// Ví dụ:
// Dữ liệu
// MakeRoot 10
// Insert 11 10
// Insert 1 10
// Insert 3 10
// Insert 5 11
// Insert 4 11
// Height 10
// Depth 10
// Insert 8 3
// Insert 2 3
// Insert 7 3
// Insert 6 4
// Insert 9 4
// Height 10
// Depth 10
// Depth 3
// *
// Kết quả
// 3
// 1
// 4
// 1
// 2

#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int id;
    Node* leftMostChild;
    Node* rightSibling;

    Node(int v) : id(v), leftMostChild(NULL), rightSibling(NULL) {}
} Tree;

Tree* root = NULL;

Tree* makeNode(int v) {
    return new Tree(v);
}

Tree* findNode(Tree* r, int v) {
    if (!r) return NULL;
    if (r->id == v) return r;

    Tree* p = r->leftMostChild;
    while (p) {
        Tree* found = findNode(p, v);
        if (found) return found;
        p = p->rightSibling;
    }
    return NULL;
}

void insertNode(int u, int v) {
    Tree* parent = findNode(root, v);
    if (!parent || findNode(root, u)) return; 

    Tree* newNode = makeNode(u);
    if (!parent->leftMostChild) {
        parent->leftMostChild = newNode;
    } else {
        Tree* child = parent->leftMostChild;
        while (child->rightSibling) {
            child = child->rightSibling;
        }
        child->rightSibling = newNode;
    }
}

int height(Tree* r) {
    if (!r) return 0;

    int maxHeight = 0;
    Tree* child = r->leftMostChild;
    while (child) {
        maxHeight = max(maxHeight, height(child));
        child = child->rightSibling;
    }
    return maxHeight + 1;
}

int depth(Tree* r, int v) {
    if (!r) return -1;
    if (r->id == v) return 1;

    Tree* child = r->leftMostChild;
    while (child) {
        int d = depth(child, v);
        if (d != -1) return d + 1;
        child = child->rightSibling;
    }
    return -1;
}

int main(int argc, char const *argv[]){
    string cmd;
    int u, v;

    while (true) {
        cin >> cmd;
        if (cmd == "MakeRoot") {
            cin >> u;
            root = makeNode(u);
        } else if (cmd == "Insert") {
            cin >> u >> v;
            insertNode(u, v);
        } else if (cmd == "Height") {
            cin >> u;
            Tree* node = findNode(root, u);
            cout << height(node) << endl;
        } else if (cmd == "Depth") {
            cin >> u;
            cout << depth(root, u) << endl;
        } else break;
    }

    return 0;
}
