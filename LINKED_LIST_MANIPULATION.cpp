// Problem: Linked List Manipulation
// Description
// Viết chương trình thực hiện công việc sau:
// Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a1, a2,...,an. sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

// Input
// Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
// Dòng 2: ghi các số nguyên dương a1, a2,...,an
// Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
// addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
// addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
// addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
// addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
// remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
// reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
// Output
// Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho

// Example
// Input
// 5
// 5 4 3 2 1
// addlast 3
// addlast 10
// addfirst 1
// addafter 10 4
// remove 1
// #

// Output
// 5 4 3 2 10 

#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data){
    Node *newNode = new(Node);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int findNode(Node *head, int key){
    Node *p = head;
    while (p != NULL){
        if (p->data == key) return 1;
        p = p->next;
    }
    return 0;
}

Node* addFirst(Node *head, int data){
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* addLast(Node *head, int data){
    Node *temp = head;
    Node *newNode = createNode(data);
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* addAfter(Node *head, int data, int key){
    Node *temp = head;
    while (temp != NULL){
        if (temp->data == key){
            Node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* addBefore(Node *head, int data, int key){
    if (head->data == key){
        Node *newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL){
        if (temp->next->data == key){
            Node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* removeNode(Node *head, int key){
    if (head->data == key){
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL){
        if (temp->next->data == key){
            Node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* reverse(Node *head){
    Node *cur = head;
    Node *pre = NULL;
    Node *next = NULL;
    while (cur != NULL){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void printList(Node *head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        if (head == NULL) head = createNode(x);
        else head = addLast(head, x);
    }

    string cmd;
    while (true){
        cin >> cmd;
        
        if (cmd == "addlast"){
            int k;
            cin >> k;
            if (!findNode(head, k)) head = addLast(head, k);
        } else if (cmd == "addfirst"){
            int k;
            cin >> k;
            if (!findNode(head, k)) head = addFirst(head, k);
        } else if (cmd == "addafter"){
            int u, v;
            cin >> u >> v;
            if (!findNode(head, u) && findNode(head, v)) head = addAfter(head, u, v);
        } else if (cmd == "addbefore"){
            int u, v;
            cin >> u >> v;
            if (!findNode(head, u) && findNode(head, v)) head = addBefore(head, u, v);
        } else if (cmd == "remove"){
            int k;
            cin >> k;
            if (findNode(head, k)) head = removeNode(head, k);
        } else if (cmd == "reverse"){
            head = reverse(head);
        } else {
            printList(head);
            break;
        }
    }

    return 0;
}
