#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
public:
    // ����������� �� �������������
    String() : str(nullptr) {}

    // ����������� � ��������� ������
    String(const char* s) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else {
            str = nullptr;
        }
    }

    // ���������� ��� �������� ���'��
    ~String() {
        delete[] str;
    }

    // �������������� ��������� []
    char operator[](int index) const {
        if (str && index >= 0 && index < strlen(str)) {
            return str[index];
        }
        else {
            return '\0'; // ��������� �������� ������, ���� ������ �����������
        }
    }

    // �������������� ��������� ()
    int operator()(char ch) const {
        if (str) {
            for (int i = 0; i < strlen(str); ++i) {
                if (str[i] == ch) {
                    return i; // ��������� ������ ������� ��������� �������
                }
            }
        }
        return -1; // ���� ������ �� ���������, ��������� -1
    }

    // �������������� ��������� ���������� �� ���� int
    operator int() const {
        return (str) ? strlen(str) : 0; // ��������� ������� �����
    }

    // ����� ��� ��������� �����
    void print() const {
        if (str) {
            cout << str << endl;
        }
        else {
            cout << "Empty string" << endl;
        }
    }
};

int main() {
    String s1("Hello, world!");

    // �������� �������������� ���������
    cout << "Character at index 7: " << s1[7] << endl;  // ������ 'w'
    cout << "Index of 'o': " << s1('o') << endl;  // ������ 4
    cout << "Length of string: " << int(s1) << endl;  // ������ 13

    return 0;
}