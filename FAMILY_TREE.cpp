// Problem: Family Tree
// Description
// Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
// descendants <name>: return number of descendants of the given <name>
// generation <name>: return the number of generations of the descendants of the given <name>

// Note that: the total number of people in the family is less than or equal to 10
// 4
// Input
// Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
// Output
// Each line is the result of a corresponding query.
// Example
// Input
// Peter Newman
// Michael Thomas
// John David
// Paul Mark
// Stephan Mark
// Pierre Thomas
// Mark Newman
// Bill David
// David Newman
// Thomas Mark
// ***
// descendants Newman
// descendants Mark
// descendants David
// generation Mark
// ***
// Output
// 10
// 5
// 2
// 2

#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    string name;
    vector<Node*> child;
    Node* parent;

    Node(string n) : name(n), parent(NULL) {}
} Node;

Node* createNode(unordered_map<string, Node*>& root, string& name) {
    if (root.find(name) == root.end()) {
        root[name] = new Node(name);
    }
    return root[name];
}

Node* findNode(unordered_map<string, Node*>& root, string& name) {
    auto it = root.find(name);
    if (it != root.end()) return it->second;
    return NULL;
}

int cnt_Des(Node* node) {
    if (!node) return 0;

    int cnt = 0;
    for (Node* c : node->child) {
        cnt += 1 + cnt_Des(c);
    }
    return cnt;
}

int cnt_Gen(Node* node) {
    if (!node) return 0;

    int maxGen = 0;
    for (Node* c : node->child) {
        maxGen = max(maxGen, cnt_Gen(c));
    }
    return maxGen + 1;
}

int main(int argc, char const *argv[]){
    unordered_map<string, Node*> root; 
    string input;

    while (true) {
        getline(cin, input);
        if (input == "***") break;

        stringstream ss(input);
        string childName, parentName;
        ss >> childName >> parentName;

        Node* parent = findNode(root, parentName);
        if (!parent) parent = createNode(root, parentName);

        Node* child = findNode(root, childName);
        if (!child) child = createNode(root, childName);

        parent->child.push_back(child);
        child->parent = parent;
    }

    while (true) {
        getline(cin, input);
        if (input == "***") break;

        stringstream ss(input);
        string cmd, name;
        ss >> cmd >> name;

        Node* node = findNode(root, name);

        if (cmd == "descendants") {
            cout << cnt_Des(node) << endl;
        } else if (cmd == "generation") {
            cout << cnt_Gen(node) - 1 << endl; 
        }
    }

    for (auto& pair : root) {
        delete pair.second;
    }

    return 0;
}
