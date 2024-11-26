// Problem: Check Parenthesis
// Description
// Given a string containing only characters (, ), [, ] {, }. Write a program that checks whether the string is correct in expression.
// Example
//  ([]{()}()[]): correct
//  ([]{()]()[]): incorrect
// Input
// One line contains the string (the length of the string is less than or equal to 10^6)One line contains the string (the length of the string is less than or equal to 10^6)
// Output
// Write 1 if the sequence is correct, and write 0, otherwise
// Example
// Input
// (()[][]{}){}{}[][]({[]()})
// Output
// 1

#include <bits/stdc++.h>

using namespace std;

stack<char> st;

bool check(char c) {
    if (c == ')' && st.top() == '(') return true;
    if (c == ']' && st.top() == '[') return true;
    if (c == '}' && st.top() == '{') return true;
    return false;
}

int main(int argc, char const *argv[]){
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty() || !check(s[i])) {
                cout << 0;
                return 0;
            }
            st.pop();
        }
    }
    
    if (!st.empty()) {
        cout << 0;
        return 0;
    }

    cout << 1;
    return 0;
}
