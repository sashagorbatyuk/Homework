#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// Простий шаблон функції: Напишіть шаблон функції, що повертає мінімальне значення з двох аргументів будь-якого типу. Перевірте для цілих, дійсних і рядкових значень.
/// </summary>
template <typename T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int a = 10, b = 20;
    cout << "Min(10, 20) = " << getMin(a, b) << endl;

    double x = 5.5, y = 3.3;
    cout << "Min(5.5, 3.3) = " << getMin(x, y) << endl;

    string str1 = "apple", str2 = "orange";
    cout << "Min(apple, orange) = " << getMin(str1, str2) << endl;

    return 0;
}