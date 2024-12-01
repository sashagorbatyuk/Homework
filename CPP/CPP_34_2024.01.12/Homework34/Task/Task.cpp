#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

// ����� �������
void findSubstring() {
    string str, substr;
    cout << "Enter the string: "; // ������ �����
    getline(cin, str);
    cout << "Enter the substring: "; // ������ �������
    getline(cin, substr);

    size_t index = str.find(substr); // ��������� ����� ��������� �������
    if (index != string::npos) {
        cout << "Substring found at position: " << index << endl; // ϳ������ �������� �� �������
    }
    else {
        cout << "Substring not found" << endl; // ϳ������ �� ��������
    }
}

// ������� �������
void replaceSubstring() {
    string str, old_substr, new_substr;
    cout << "Enter the string: "; // ������ �����
    getline(cin, str);
    cout << "Enter the substring to replace: "; // ������ ������� ��� �����
    getline(cin, old_substr);
    cout << "Enter the new substring: "; // ������ ����� �������
    getline(cin, new_substr);

    size_t pos = str.find(old_substr); // ��������� ������� �������
    if (pos != string::npos) {
        str.replace(pos, old_substr.length(), new_substr); // ����� �������
        cout << "Modified string: " << str << endl; // �������� ������� �����
    }
    else {
        cout << "Substring not found" << endl; // ϳ������ �� ��������
    }
}

// ������ �����
string reverseString(const string& str) {
    string reversed = str; // ������� �����
    reverse(reversed.begin(), reversed.end()); // ��������� �����
    return reversed; // ��������� ������������ �����
}

// ʳ������ �������� �������
int countCharacterOccurrences(const string& str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++; // ˳������� �������� �������
        }
    }
    return count; // ��������� ������� ��������
}

// �������� �� ��������
bool isPalindrome(const string& str) {
    string reversed = reverseString(str); // �������� ������������ �����
    return str == reversed; // ��������� � ����������� ������
}

// ��������� �����
vector<string> splitString(const string& str) {
    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) { // ������ ����� �����
        words.push_back(word); // ������ ������ ���
    }
    return words; // ��������� ������ ���
}

// ��������� ������
string removeExtraSpaces(const string& str) {
    string result;
    bool inSpaces = false;
    for (char c : str) {
        if (isspace(c)) { // ���� �����
            if (!inSpaces) {
                result += ' '; // ������ ���� ���� �����
                inSpaces = true;
            }
        }
        else {
            result += c; // ������ �������, �� �� ������
            inSpaces = false;
        }
    }
    if (!result.empty() && result.back() == ' ') {
        result.pop_back(); // ��������� ����� � ����
    }
    return result; // ��������� ���������
}

int main() {
    // ������� ������������ ��� �������
    findSubstring();
    replaceSubstring();

    string str = "madam";
    cout << "Is palindrome: " << (isPalindrome(str) ? "Yes" : "No") << endl;

    cout << "Reversed string: " << reverseString("hello") << endl;

    cout << "Count of 'l' in 'hello': " << countCharacterOccurrences("hello", 'l') << endl;

    string sentence = "This is a test sentence";
    vector<string> words = splitString(sentence);
    cout << "Words in sentence: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;

    string text = "  This  is  an   example   ";
    cout << "After removing extra spaces: '" << removeExtraSpaces(text) << "'" << endl;

    return 0;
}