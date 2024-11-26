// Problem: Chapter 3 - Polynomial Manipulation
// Description
// A polynomial is stored in a linked list:
//     Each term is stored in a node of the list with 2 fields: coefficient and exponent
//     Nodes are always sorted in a decreasing order of exponents 
//     No two nodes have the same value of exponents
// Each polynomial has an identifier which is a positive integer from 1 to 10000

// Given a list of commands over polynomials below:
//     Create <poly_id>: create a polynomial with identifier <pol_id> if this polynomial does not exists, otherwise, do nothing
//     AddTerm <poly_id> <coef> <exp>: Add a term with coefficient <coef> and exponent <exp> to the polynomial having identifier <poly_id> (create a new polynomial if it does not exist)
//     EvaluatePoly <poly_id> <variable_value>: Evaluate and print the value of the polynomial having identifier <poly_id> and <variable_value> is the value of the variable (print 0 if the polynomial does not exist) 
//     AddPoly <poly_id1> <poly_id2> <result_poly_id>: Perform the addition operation over two polynomials <pol_id1> and <poly_id2>. The resulting polynomial will have identifier <result_poly_id> (if the polynomial <result_poly_id> exists, then overrides the existing polynomial)
//     PrintPoly <poly_id>: print the polynomial <poly_id> (if it exists) to stdout under the form <c_1> <e_1> <c_2> <e_2> ... (sequence of pairs of (coefficient, exponent) of terms of the polynomial in a decreasing order of exponents)
//     Destroy <poly_id>: destroy the polynomial having identifier <poly_id>

// Input
// Each line contains a command described above (terminated by a line containing *)
// Output
// Each line contains the information printed out by the PrintPoly and EvaluatePoly above
 
// Example
// Input
// AddTerm 1 3 2
// AddTerm 1 4 0
// AddTerm 1 6 2
// AddTerm 2 3 2
// AddTerm 2 7 5
// PrintPoly 1
// PrintPoly 2
// AddPoly 2 1 3
// PrintPoly 3
// EvaluatePoly 2 1
// *

// Output
// 9 2 4 0
// 7 5 3 2
// 7 5 12 2 4 0
// 10    

#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int coef;
    int exp;
    struct Node* next;
} Node;

typedef struct Polynomial {
    int id;
    Node* head;
} Poly;


Node* createNode(int coef, int exp) {
    Node* node = new Node();
    node->coef = coef;
    node->exp = exp;
    node->next = NULL;
    return node;
}

Poly* createPoly(int id) {
    Poly* poly = new Poly();
    poly->id = id;
    poly->head = NULL;
    return poly;
}

Poly* Polys[10000];
int n = 0;

Poly* getPoly(int id) {
    for (int i = 0; i < n; i++) {
        if (Polys[i]->id == id) {
            return Polys[i];
        }
    }
    return NULL;
}

void create(int id) {
    if (getPoly(id) == NULL) {
        Polys[n++] = createPoly(id);
    }
}

void addTerm(int id, int coef, int exp) {
    Poly* poly = getPoly(id);
    if (poly == NULL) {
        poly = createPoly(id);
        Polys[n++] = poly;
    }

    Node* node = createNode(coef, exp);
    if (poly->head == NULL) poly->head = node;
    else {
        Node* cur = poly->head;
        Node* prev = NULL;
        while (cur != NULL && cur->exp > exp) {
            prev = cur;
            cur = cur->next;
        }
        if (cur != NULL && cur->exp == exp) {
            cur->coef += coef;
            delete node;
        } else {
            if (prev == NULL) {
                node->next = poly->head;
                poly->head = node;
            } else {
                prev->next = node;
                node->next = cur;
            }
        }
    }
}

void evaluatePoly(int id, int variableValue) {
    Poly* poly = getPoly(id);
    if (poly == NULL) {
        cout << "0" << endl;
        return;
    }

    Node* cur = poly->head;
    int res = 0;
    while (cur != NULL) {
        res += cur->coef * pow(variableValue, cur->exp);
        cur = cur->next;
    }
    cout << res << endl;
}

void addPoly(int id1, int id2, int resId) {
    Poly* poly1 = getPoly(id1);
    Poly* poly2 = getPoly(id2);
    Poly* res = getPoly(resId);
    if (res == NULL) {
        res = createPoly(resId);
        Polys[n++] = res;
    }

    Node* cur1 = poly1->head;
    Node* cur2 = poly2->head;
    while (cur1 != NULL || cur2 != NULL) {
        if (cur1 == NULL) {
            addTerm(resId, cur2->coef, cur2->exp);
            cur2 = cur2->next;
        } else if (cur2 == NULL) {
            addTerm(resId, cur1->coef, cur1->exp);
            cur1 = cur1->next;
        } else {
            if (cur1->exp > cur2->exp) {
                addTerm(resId, cur1->coef, cur1->exp);
                cur1 = cur1->next;
            } else if (cur1->exp < cur2->exp) {
                addTerm(resId, cur2->coef, cur2->exp);
                cur2 = cur2->next;
            } else {
                addTerm(resId, cur1->coef + cur2->coef, cur1->exp);
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }
    }
}

int degree(Poly* poly) {
    if (poly == NULL) return -1;

    Node* cur = poly->head;
    int maxDegree = -1;
    while (cur != NULL) {
        if (cur->exp > maxDegree) maxDegree = cur->exp;
        cur = cur->next;
    }
    return maxDegree;
}

void printPoly(int id) {
    Poly* poly = getPoly(id);
    if (poly == NULL) return;

    Node* cur = poly->head;
    while (cur != NULL) {
        cout << cur->coef << " " << cur->exp << " ";
        cur = cur->next;
    }
    cout << endl;
}


void destroy(int id) {
    for (int i = 0; i < n; i++) {
        if (Polys[i]->id == id) {
            free(Polys[i]);
            for (int j = i; j < n - 1; j++) {
                Polys[j] = Polys[j + 1];
            }
            n--;
            break;
        }
    }
}


int main(int argc, char const *argv[]){
    string cmd;
    int id, coef, exp, variableValue, resId, id1, id2;

    while (1) {
        cin >> cmd;
        if (cmd == "Create") {
            scanf("%d", &id);
            create(id);
        } else if (cmd == "AddTerm") {
            scanf("%d %d %d", &id, &coef, &exp);
            addTerm(id, coef, exp);
        } else if (cmd == "EvaluatePoly") {
            scanf("%d %d", &id, &variableValue);
            evaluatePoly(id, variableValue);
        } else if (cmd == "AddPoly") {
            scanf("%d %d %d", &id1, &id2, &resId);
            addPoly(id1, id2, resId);
        } else if (cmd == "PrintPoly") {
            scanf("%d", &id);
            printPoly(id);
        } else if (cmd == "Destroy") {
            scanf("%d", &id);
            destroy(id);
        } else break;
    }

    return 0;
}