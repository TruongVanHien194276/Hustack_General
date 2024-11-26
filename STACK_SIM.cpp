// Problem: Simulation Stack
// Description
// Perform a sequence of operations over a stack, each element is an integer:
// PUSH v: push a value v into the stack
// POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
// Input
// Each line contains a command (operration) of type 
// PUSH  v
// POP
// Output
// Write the results of POP operations (each result is written in a line)
// Example
// Input
// PUSH 1
// PUSH 2
// PUSH 3
// POP
// POP
// PUSH 4
// PUSH 5
// POP
// #
// Output
// 3
// 2
// 5

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* push(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* pop(Node* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return head;
    } else {
        Node* tmp = head;
        head = head->next;
        cout << tmp->data << endl;
        delete tmp;
        return head;
    }
}

int main(int argc, char const *argv[]){
    Node* head = NULL;
    string cmd;

    while (true) {
        cin >> cmd;
        if (cmd == "PUSH") {
            int x;
            cin >> x;
            head = push(head, x);
        } else if (cmd == "POP") {
            head = pop(head);
        } else break;
    }

    return 0;
}