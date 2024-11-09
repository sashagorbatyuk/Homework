#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
public:
    // Конструктор за замовчуванням
    String() : str(nullptr) {}

    // Конструктор з переданим рядком
    String(const char* s) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else {
            str = nullptr;
        }
    }

    // Деструктор для очищення пам'яті
    ~String() {
        delete[] str;
    }

    // Перевантаження оператора []
    char operator[](int index) const {
        if (str && index >= 0 && index < strlen(str)) {
            return str[index];
        }
        else {
            return '\0'; // Повертаємо нульовий символ, якщо індекс некоректний
        }
    }

    // Перевантаження оператора ()
    int operator()(char ch) const {
        if (str) {
            for (int i = 0; i < strlen(str); ++i) {
                if (str[i] == ch) {
                    return i; // Повертаємо індекс першого входження символу
                }
            }
        }
        return -1; // Якщо символ не знайдений, повертаємо -1
    }

    // Перевантаження оператора приведення до типу int
    operator int() const {
        return (str) ? strlen(str) : 0; // Повертаємо довжину рядка
    }

    // Метод для виведення рядка
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

    // Перевірка перевантажених операторів
    cout << "Character at index 7: " << s1[7] << endl;  // Виведе 'w'
    cout << "Index of 'o': " << s1('o') << endl;  // Виведе 4
    cout << "Length of string: " << int(s1) << endl;  // Виведе 13

    return 0;
}