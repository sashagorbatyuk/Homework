#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2. Написати функцію, яка отримує в якості параметрів 2 цілих числа та повертає суму чисел із діапазону між ними
/// </summary>
int sumInRange(int a, int b) {
    int sum = 0;

    // Знаходимо мінімальне і максимальне значення
    int start = min(a, b);
    int end = max(a, b);

    // Додаємо всі числа від start до end (включно)
    for (int i = start; i <= end; ++i) {
        sum += i;
    }

    return sum;
}

int main() {
    int num1, num2;

    // Введення двох цілих чисел
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // Обчислення суми чисел у діапазоні
    int result = sumInRange(num1, num2);

    // Виведення результату
    cout << "Sum of numbers between " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
