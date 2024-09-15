#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2.2
/// Користувач вводить з клавіатури три числа. Порахувати їхню суму, добуток і середнє арифметичне.
/// </summary>

int main() {
    // Input: three numbers
    double num1, num2, num3;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the third number: ";
    cin >> num3;

    // Calculate sum, product, and arithmetic mean
    double sum = num1 + num2 + num3;
    double product = num1 * num2 * num3;
    double average = sum / 3.0;

    // Output the results
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    cout << "Arithmetic mean: " << average << endl;

    return 0;
}
