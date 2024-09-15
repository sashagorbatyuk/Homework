#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2.1
/// Користувач вводить з клавіатури два числа. Порахувати їхню суму, добуток і середнє арифметичне.
/// </summary>

int main() {
    // Input: two numbers
    double num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Calculate sum, product, and arithmetic mean
    double sum = num1 + num2;
    double product = num1 * num2;
    double average = sum / 2.0;

    // Output the results
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    cout << "Arithmetic mean: " << average << endl;

    return 0;
}
