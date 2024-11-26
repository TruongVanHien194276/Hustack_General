// Problem: Chapter 6 - Hash Over Integers
// Description
// A database contains a sequence of key k1, k2, ..., kn which are integers (1<=n<=100000). Perform a sequence of actions of two kinds:
// · find k: find and return 1 if k exists in the database, and return 0, otherwise
// · insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
// Note that the value of any key is greater than or equal to 0 and less than or equal to 10
// 17
// .
// Input
// Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = "find" or "insert" and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
// Output
// Each line contains the result (0 or 1) of the corresponding action.
// Example
// Input
// 4
// 5
// 2
// *
// find 3
// insert 4
// find 2
// insert 3
// find 3
// ***
// Output
// 0
// 0
// 1
// 1
// 1

#include <bits/stdc++.h>

using namespace std;

const int HASH_SIZE = 1000003; // Prime number

struct Node {
    string key;
    Node* next;

    Node(string k) : key(k), next(NULL) {}
};

vector<Node*> hashTable(HASH_SIZE, NULL);

int hash_func(string& key) {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_SIZE;
}

int find(string& key) {
    int h = hash_func(key);
    Node* cur = hashTable[h];

    while (cur != NULL) {
        if (cur->key == key) return 1;
        cur = cur->next;
    }
    return 0; 
}

int insert(string& key) {
    if (find(key) == 1) return 0;
    else {
        int h = hash_func(key);
        Node* newNode = new Node(key);
        newNode->next = hashTable[h];
        hashTable[h] = newNode;
        return 1; 
    }
}

int main(int argc, char const *argv[]){
    string key;
    while (cin >> key) {
        if (key == "*") break;
        insert(key);
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "***") break;

        cin >> key;
        if (cmd == "find") {
            cout << find(key) << endl;
        } else if (cmd == "insert") {
            cout << insert(key) << endl;
        }
    }

    return 0;
}

