#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isCorrect(const string& input) {
    stack<char> st;  // ���� ��� ��������� ����������� �����
    for (int i = 0; i < input.size(); ++i) {
        char ch = input[i];

        // ���� �� ���������� �����
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        // ���� �� ���������� �����
        else if (ch == ')' || ch == ']' || ch == '}') {
            // ���� ���� ������� ��� ����� �� ���������
            if (st.empty()) return false;

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                st.pop();  // �������� ����, ������ � �����
            }
            else {
                return false;  // ������ ����
            }
        }
        // ���� ������ � ����� (�� �����), ���������� ��������
    }
    // ���� ���� �������, �� ����� ��������� ������
    return st.empty();
}

int main() {
    string input;
    getline(cin, input);  // ������ ����� �� ������� ";"

    if (input.back() == ';') {
        input.pop_back();  // ��������� ������ ���� ����� ";"
    }

    if (isCorrect(input)) {
        cout << "Correct string" << endl;
    }
    else {
        cout << "Incorrect string" << endl;
    }

    return 0;
}