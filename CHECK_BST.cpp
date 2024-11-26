// Problem: Check if a given binary tree is a BST
// Description
// Each node of a binary tree has a field key which is the key of the node. Build a binary tree and check if the tree is a binary search tree (BST), and compute the sum of keys of nodes of the given tree (keys of the nodes are distinct and in the range 1, 2, …, 105)
// Input
// •Line 1 contains MakeRoot u: make the root of the tree having id = u
// •Each subsequent line contains: AddLeft or AddRight commands with the format
// •AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
// •AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
// •The last line contains * which marks the end of the input
// Output
// •Write two integers z and s in which s is the sum of keys of nodes of the tree and z = 1 if the tree is a BST and z = 0, otherwise
// Example
// Input
// MakeRoot 4
// AddRight 5 4
// AddLeft 3 4
// AddRight 8 5
// AddLeft 1 3
// AddLeft 7 8
// AddLeft 6 7
// AddRight 2 1
// AddRight 10 8
// AddLeft 9 10
// *
// Output
// 1 55

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int k) : key(k), left(NULL), right(NULL) {}
};

map<int, Node*> nodes;

bool checkBST(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->key <= minVal || root->key >= maxVal) return false;
    return checkBST(root->left, minVal, root->key) && checkBST(root->right, root->key, maxVal);
}

long long cal_Sum(Node* root) {
    if (!root) return 0;
    return (long long)root->key + cal_Sum(root->left) + cal_Sum(root->right);
}

int main(int argc, char const *argv[]){
    Node* root = NULL;
    int u, v;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "MakeRoot") {
            cin >> u;
            root = new Node(u);
            nodes[u] = root;
        } else if (cmd == "AddLeft") {
            cin >> u >> v;
            if (nodes.find(v) == nodes.end()) continue;
            if (nodes.find(u) == nodes.end()) nodes[u] = new Node(u);
            nodes[v]->left = nodes[u];
        } else if (cmd == "AddRight") {
            cin >> u >> v;
            if (nodes.find(v) == nodes.end()) continue;
            if (nodes.find(u) == nodes.end()) nodes[u] = new Node(u);
            nodes[v]->right = nodes[u];
        } else break;
    }

    long long s = cal_Sum(root); 
    int z = checkBST(root, INT_MIN, INT_MAX) ? 1 : 0;

    cout << z << " " << s;

    return 0;
}
