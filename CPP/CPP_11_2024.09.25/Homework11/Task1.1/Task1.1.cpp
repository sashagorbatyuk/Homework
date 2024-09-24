#include <iostream>
using namespace std;

/// <summary>
/// Завдання 1. Написати функцію, яка приймає два параметри: основа степеня і показник степеня, та обчислює степінь числа на основі отриманих даних.
/// </summary>
double power(double base, int exponent) {
    double result = 1;  // Ініціалізуємо результат як 1
    for (int i = 0; i < abs(exponent); ++i) {
        result *= base;  // Множимо результат на основу exponent разів
    }

    // Якщо показник степеня від'ємний, повертаємо обернений результат
    if (exponent < 0) {
        return 1 / result;
    }

    return result;
}

int main() {
    double base;
    int exponent;

    // Введення основи і показника степеня
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    // Обчислення і виведення результату
    double result = power(base, exponent);
    cout << base << " raised to the power of " << exponent << " is: " << result << endl;

    return 0;
}
