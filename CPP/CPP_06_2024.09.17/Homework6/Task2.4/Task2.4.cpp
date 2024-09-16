#include <iostream>
#include <cmath>

using namespace std;

/// <summary>
/// Завдання 2.4. Користувач вводить будь-яке ціле число А.
/// Необхідно вивести всі цілі числа В, для яких А ділиться без залишку на В*В і не ділиться без залишку на В*В*В.
/// </summary>
int main() {
    int A;

    cout << "Enter an integer A: ";
    cin >> A;

    // Перебираємо всі можливі значення B
    for (int B = 1; B <= sqrt(A); B++) {
        if (A % (B * B) == 0 && A % (B * B * B) != 0) {
            cout << B << " is a valid number where A is divisible by B^2 but not by B^3." << endl;
        }
    }

    return 0;
}
