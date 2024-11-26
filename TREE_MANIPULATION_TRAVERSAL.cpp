// Problem: Tree manipulation and traversal
// Description
// Mỗi nút của cây có trường id (số nguyên duy nhất, không trùng lặp)
// Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây:
// MakeRoot u: Tạo ra nút gốc u của cây
// Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
// PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
// InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
// PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
// Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
// Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động $PreOrder, $InOrder, $PostOrder tương ứng đọc được từ dữ liệu đầu vào
// Ví dụ
// Dữ liệu
// MakeRoot 10
// Insert 11 10
// Insert 1 10
// Insert 3 10
// InOrder
// Insert 5 11
// Insert 4 11
// Insert 8 3
// PreOrder
// Insert 2 3
// Insert 7 3
// Insert 6 4
// Insert 9 4
// InOrder
// PostOrder
// *
// Kết quả
// 11 10 1 3
// 10 11 5 4 1 3 8
// 5 11 6 4 9 10 1 8 3 2 7
// 5 6 9 4 11 1 8 2 7 3 10

#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    int id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Tree;

Tree* root = NULL;

Tree* makeNode(int v){
    Tree* p = new(Tree);
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Tree* findNode(Tree* r, int v){
    if (r == NULL) return NULL;
    if (r->id == v) return r;
    Tree* p = r->leftMostChild;
    while (p != NULL){
        Tree* q = findNode(p, v);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

void insertNode(int u, int v){
    Tree* r = findNode(root, v);

    Tree* p = makeNode(u);
    if (r->leftMostChild == NULL){
        r->leftMostChild = p;
    } else {
        Tree* h = r->leftMostChild;
        while (h->rightSibling != NULL){
            h = h->rightSibling;
        }
        h->rightSibling = p;
    }
}

void preOrder(Tree* r){
    if (r == NULL) return;
    cout << r->id << " ";
    Tree* p = r->leftMostChild;
    while (p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}

void inOrder(Tree* r){
    if (r == NULL) return;
    Tree* p = r->leftMostChild;
    inOrder(p);
    cout << r->id << " ";
    if (p == NULL) return;
    p = p->rightSibling;
    while (p != NULL){
        inOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(Tree* r){
    if (r == NULL) return;
    Tree* p = r->leftMostChild;
    while (p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    cout << r->id << " ";
}

int main(int argc, char const *argv[]){
    string cmd;
    while (true){
        cin >> cmd;
        if (cmd == "MakeRoot"){
            int x;
            cin >> x;
            root = makeNode(x);
        } else if (cmd == "Insert"){
            int u, v;
            cin >> u >> v;
            insertNode(u, v);
        } else if (cmd == "PreOrder"){
            preOrder(root);
            cout << endl;
        } else if (cmd == "InOrder"){
            inOrder(root);
            cout << endl;
        } else if (cmd == "PostOrder"){
            postOrder(root);
            cout << endl;
        } else break;
    }
    
    return 0;
}


