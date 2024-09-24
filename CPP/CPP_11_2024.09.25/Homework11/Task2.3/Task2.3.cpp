#include <iostream>
#include <cmath>
using namespace std;

/// <summary>
/// Завдання 3. Написати функцію для переведення числа,записаного у двійковому вигляді, у десяткову систему.
/// </summary>
int binaryToDecimal(long long binary) {
    int decimal = 0, i = 0;

    // Перебір кожної цифри двійкового числа
    while (binary != 0) {
        // Беремо останню цифру числа (0 або 1)
        int remainder = binary % 10;
        // Додаємо до десяткового числа значення останньої цифри двійкового числа, помножене на 2^i
        decimal += remainder * pow(2, i);
        // Переходимо до наступної цифри
        binary /= 10;
        i++;
    }

    return decimal;
}

int main() {
    long long binary;

    // Введення двійкового числа
    cout << "Enter a binary number: ";
    cin >> binary;

    // Виклик функції для переведення у десяткову систему
    int decimal = binaryToDecimal(binary);

    // Виведення результату
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}
