#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isCorrect(const string& input) {
    stack<char> st;  // —тек дл€ збер≥ганн€ в≥дкриваючих дужок
    for (int i = 0; i < input.size(); ++i) {
        char ch = input[i];

        // якщо це в≥дкриваюча дужка
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        // якщо це закриваюча дужка
        else if (ch == ')' || ch == ']' || ch == '}') {
            // якщо стек порожн≥й або дужки не зб≥гаютьс€
            if (st.empty()) return false;

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                st.pop();  //  оректна пара, зн≥маЇмо з стека
            }
            else {
                return false;  // Ќев≥рна пара
            }
        }
        // якщо символ Ї ≥ншим (не дужка), продовжуЇмо перев≥рку
    }
    // якщо стек порожн≥й, вс≥ дужки правильно закрит≥
    return st.empty();
}

int main() {
    string input;
    getline(cin, input);  // „итаЇмо р€док до символу ";"

    if (input.back() == ';') {
        input.pop_back();  // ¬идал€Їмо символ к≥нц€ р€дка ";"
    }

    if (isCorrect(input)) {
        cout << "Correct string" << endl;
    }
    else {
        cout << "Incorrect string" << endl;
    }

    return 0;
}