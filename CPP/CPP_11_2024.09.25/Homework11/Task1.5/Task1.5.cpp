#include <iostream>

using namespace std;

/// <summary>
/// Завдання 5. Написати функцію, що визначає, чи є «щасливим» шестизначне число.
/// </summary>
bool isLuckyNumber(int number) {
    // Перевіряємо, чи число шестизначне
    if (number < 100000 || number > 999999) {
        cout << "The number is not six digits." << endl;
        return false;
    }

    // Отримуємо цифри числа
    int firstHalfSum = 0, secondHalfSum = 0;
    int digits[6];

    // Розбиваємо число на окремі цифри
    for (int i = 5; i >= 0; --i) {
        digits[i] = number % 10;
        number /= 10;
    }

    // Обчислюємо суми перших трьох і останніх трьох цифр
    for (int i = 0; i < 3; ++i) {
        firstHalfSum += digits[i];
        secondHalfSum += digits[i + 3];
    }

    // Порівнюємо суми
    return firstHalfSum == secondHalfSum;
}

int main() {
    int number;

    // Введення числа
    cout << "Enter a six-digit number: ";
    cin >> number;

    // Перевірка, чи є число щасливим
    if (isLuckyNumber(number)) {
        cout << "The number is lucky!" << endl;
    }
    else {
        cout << "The number is not lucky." << endl;
    }

    return 0;
}
