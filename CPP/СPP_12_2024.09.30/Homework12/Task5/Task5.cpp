#include <iostream>
using namespace std;

/// <summary>
/// Шаблон для порівняння трьох значень: Напишіть шаблон функції, яка приймає три значення одного типу і повертає найменше. Перевірте функцію для цілих і дійсних типів.
/// </summary>

template <typename T>
T getMinOfThree(T a, T b, T c) {
    T minValue = (a < b) ? a : b;
    minValue = (minValue < c) ? minValue : c;
    return minValue;
}

int main() {
    // Перевірка для цілих чисел
    int a = 10, b = 5, c = 7;
    int minInt = getMinOfThree(a, b, c);
    cout << "Min of 10, 5, 7 (int): " << minInt << endl;

    // Перевірка для дійсних чисел
    double x = 3.14, y = 2.71, z = 4.56;
    double minDouble = getMinOfThree(x, y, z);
    cout << "Min of 3.14, 2.71, 4.56 (double): " << minDouble << endl;

    return 0;
}
