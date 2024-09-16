#include <iostream>
#include <cmath>

using namespace std;

/// <summary>
/// Завдання 2.5. Користувач вводить ціле число А. 
/// Програма має визначити, що куб суми цифр цього числа дорівнює А*А.
/// </summary>
int main() {
    int A;

    cout << "Enter an integer A: ";
    cin >> A;

    int sum_of_digits = 0;
    int temp = abs(A);

    while (temp > 0) {
        sum_of_digits += temp % 10;
        temp /= 10;
    }

    int cube_of_sum = pow(sum_of_digits, 3);

    int a_squared = pow(A, 2);

    if (cube_of_sum == a_squared) {
        cout << "The cube of the sum of the digits is equal to A squared." << endl;
    }
    else {
        cout << "The cube of the sum of the digits is not equal to A squared." << endl;
    }

    return 0;
}