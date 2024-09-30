#include <iostream>
using namespace std;

// Рекурсивна функція для знаходження НСД двох чисел
int gcd(int a, int b) {
    // Базовий випадок: якщо одне з чисел дорівнює 0, повертаємо інше
    if (b == 0) {
        return a;
    }
    // Рекурсивний виклик: НСД(a, b) = НСД(b, a % b)
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
