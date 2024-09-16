#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2.6. Користувач вводить ціле число. 
/// Необхідно вивести всі цілі числа, на які задане число ділиться без залишку
/// </summary>
int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    cout << "The divisors of " << number << " are: ";

    for (int i = 1; i <= abs(number); i++) {
        if (number % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
