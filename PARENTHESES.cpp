// Problem: Parentheses
// Description
// Given a string containing only characters (, ), [, ] {, }. Write a program that check whether the string is correct in expression. 
// Example:
// ([]{()}()[]): correct
// ([]{()]()[]): incorrect
// Input
// One line contains the string (the length of the string is less than or equal to 10^6)
// Output
// Write 1 if the sequence is correct, and write 0, otherwise
// Example:
// input
// (()[][]{}){}{}[][]({[]()})
// output
// 1

#include <bits/stdc++.h>

using namespace std;

int check(string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return 0;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                    return 0;  
            }
        }
    }

    return st.empty() ? 1 : 0;
}

int main(int argc, char const *argv[]){
    string s;
    cin >> s;  

    cout << check(s);

    return 0;
}
