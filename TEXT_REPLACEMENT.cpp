// Problem: Text Replacement
// Description
// Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
// Dữ liệu
// · Dòng 1: xâu P1
// · Dòng 2: xâu P2
// · Dòng 3: văn bản T
// Kết quả:
// · Ghi văn bản T sau khi thay thế
// Ví dụ
// Dữ liệu
// AI
// Artificial Intelligence
// Recently, AI is a key technology. AI enable efficient operations in many fields.
// Kết quả
// Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable efficient operations in many fields.

#include <bits/stdc++.h>

using namespace std;

void replace_strings(string &T, string &P1, string &P2) {
    size_t pos = 0;
    while ((pos = T.find(P1, pos)) != string::npos) {
        T.replace(pos, P1.length(), P2);
        pos += P2.length(); 
    }
}

int main(int argc, char const *argv[]){
    string P1, P2, T;
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);

    replace_strings(T, P1, P2);
    cout << T;

    return 0;
}
