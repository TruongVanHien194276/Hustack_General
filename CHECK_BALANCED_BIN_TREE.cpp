// Problem: Check balanced binary tree and compute the height
// Description
// Each node of a binary tree has a field id which is the identifier of the node. Build a binary tree and check if the tree is a balanced tree, compute the height of the given tree (the number of nodes of the tree can be upto 50000)
// Input
// Line 1 contains MakeRoot u: make the root of the tree having id = u
// Each subsequent line contains: AddLeft or AddRightcmds with the format
// AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
// AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
// The last line contains * which marks the end of the input
// Output
// Write two integers z and h (separated by a SPACE character) in which h is the height (the number of nodes of the longest path from the root to a leaf) and z = 1 if the tree is balanced and z = 0, otherwise

// Example
// Input
// MakeRoot 1
// AddLeft 2 1
// AddRight 3 1
// AddLeft 9 2
// AddRight 4 2
// AddLeft 6 3
// AddRight 5 3
// AddLeft 7 4
// AddRight 8 4
// *
// Output
// 1 4

#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int id;
    Tree* left;
    Tree* right;

    Tree(int data) : id(data), left(NULL), right(NULL) {}
};

unordered_map<int, Tree*> nodes;
Tree* root = NULL;

void addLeft(int u, int v) {
    Tree* parent = nodes[v];
    if (!parent->left) {
        parent->left = new Tree(u);
        nodes[u] = parent->left;
    }
}

void addRight(int u, int v) {
    Tree* parent = nodes[v];
    if (!parent->right) {
        parent->right = new Tree(u);
        nodes[u] = parent->right;
    }
}

int height(Tree* node, bool &isBalanced) {
    if (!node) return 0;

    int left_H = height(node->left, isBalanced);
    int right_H = height(node->right, isBalanced);

    if (abs(left_H - right_H) > 1) isBalanced = false;

    return max(left_H, right_H) + 1;
}

pair<bool, int> checkBalanceAndheight() {
    bool isBalanced = true;
    int h = height(root, isBalanced);
    return make_pair(isBalanced, h);  
}

int main(int argc, char const *argv[]){
    string cmd;
    int u, v;

    while (cin >> cmd) {
        if (cmd == "MakeRoot") {
            cin >> u;
            root = new Tree(u);
            nodes[u] = root;
        } else if (cmd == "AddLeft") {
            cin >> u >> v;
            addLeft(u, v);
        } else if (cmd == "AddRight") {
            cin >> u >> v;
            addRight(u, v);
        } else break;
    }

    pair<bool, int> res = checkBalanceAndheight();
    cout << res.first << " " << res.second;

    return 0;
}
