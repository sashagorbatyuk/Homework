#include <iostream>

using namespace std;

/// <summary>
/// Завдання 4. Знайти здобуток усіх цілих чисел від a до 20 (значення a вводиться з клавіатури : 1 <= a <= 20).
/// </summary>
int main() {
    int a;
    long long product = 1;

    cout << "Enter a value for a (1 <= a <= 20): ";
    cin >> a;

    if (a < 1 || a > 20) {
        cout << "Invalid input! a must be between 1 and 20." << endl;
        return 1;
    }

    for (int i = a; i <= 20; i++) {
        product *= i;
    }

    cout << "The product of integers from " << a << " to 20 is: " << product << endl;

    return 0;
}
