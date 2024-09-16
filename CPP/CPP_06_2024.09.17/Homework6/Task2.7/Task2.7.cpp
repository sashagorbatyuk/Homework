#include <iostream>
#include <algorithm> // for std::min

using namespace std;

/// <summary>
/// Завдання 2.7. Користувач вводить два цілих числа. Необхідно вивести всі цілі числа, на які обидва введені числа діляться без залишку
/// </summary>
int main() {
    int num1, num2;

    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    int absNum1 = abs(num1);
    int absNum2 = abs(num2);

    int maxDivisor = min(absNum1, absNum2);

    cout << "The common divisors of " << num1 << " and " << num2 << " are: ";

    for (int i = 1; i <= maxDivisor; i++) {
        if (absNum1 % i == 0 && absNum2 % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}