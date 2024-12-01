#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

// Пошук підрядка
void findSubstring() {
    string str, substr;
    cout << "Enter the string: "; // Введіть рядок
    getline(cin, str);
    cout << "Enter the substring: "; // Введіть підрядок
    getline(cin, substr);

    size_t index = str.find(substr); // Знаходимо перше входження підрядка
    if (index != string::npos) {
        cout << "Substring found at position: " << index << endl; // Підрядок знайдено на позиції
    }
    else {
        cout << "Substring not found" << endl; // Підрядок не знайдено
    }
}

// Замінити підрядок
void replaceSubstring() {
    string str, old_substr, new_substr;
    cout << "Enter the string: "; // Введіть рядок
    getline(cin, str);
    cout << "Enter the substring to replace: "; // Введіть підрядок для заміни
    getline(cin, old_substr);
    cout << "Enter the new substring: "; // Введіть новий підрядок
    getline(cin, new_substr);

    size_t pos = str.find(old_substr); // Знаходимо позицію підрядка
    if (pos != string::npos) {
        str.replace(pos, old_substr.length(), new_substr); // Заміна підрядка
        cout << "Modified string: " << str << endl; // Виводимо змінений рядок
    }
    else {
        cout << "Substring not found" << endl; // Підрядок не знайдено
    }
}

// Реверс рядка
string reverseString(const string& str) {
    string reversed = str; // Копіюємо рядок
    reverse(reversed.begin(), reversed.end()); // Реверсуємо рядок
    return reversed; // Повертаємо реверсований рядок
}

// Кількість входжень символа
int countCharacterOccurrences(const string& str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++; // Лічильник входжень символа
        }
    }
    return count; // Повертаємо кількість входжень
}

// Перевірка на паліндром
bool isPalindrome(const string& str) {
    string reversed = reverseString(str); // Отримуємо реверсований рядок
    return str == reversed; // Порівнюємо з оригінальним рядком
}

// Розділення рядка
vector<string> splitString(const string& str) {
    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) { // Читаємо кожне слово
        words.push_back(word); // Додаємо вектор слів
    }
    return words; // Повертаємо вектор слів
}

// Видалення пробілів
string removeExtraSpaces(const string& str) {
    string result;
    bool inSpaces = false;
    for (char c : str) {
        if (isspace(c)) { // Якщо пробіл
            if (!inSpaces) {
                result += ' '; // Додаємо лише один пробіл
                inSpaces = true;
            }
        }
        else {
            result += c; // Додаємо символи, що не пробіли
            inSpaces = false;
        }
    }
    if (!result.empty() && result.back() == ' ') {
        result.pop_back(); // Видаляємо пробіл в кінці
    }
    return result; // Повертаємо результат
}

int main() {
    // Приклад використання всіх функцій
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