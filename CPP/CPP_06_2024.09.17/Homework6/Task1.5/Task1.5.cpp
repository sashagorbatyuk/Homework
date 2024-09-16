#include <iostream>

using namespace std;

/// <summary>
/// Завдання 5. Написати програму, яка виводить на екран
/// таблицю множення на k, де k — номер варіанта.Наприклад, для 7 - го варіанта :
/// 7 x 2 = 14;
/// 7 x 3 = 21.
/// </summary>

int main() {
    int k;

    cout << "Enter the value for k (variant number): ";
    cin >> k;

    for (int i = 2; i <= 10; i++) {
        cout << k << " x " << i << " = " << k * i << endl;
    }

    return 0;
}
