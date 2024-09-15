#include <iostream>

/// <summary>
/// Завдання 1.4. Користувач вводить два числа. Визначити, чи рівні ці числа, і якщо ні, вивести їх на екран за зростанням
/// </summary>
int main() {
    int num1, num2;

    // Введення двох чисел
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Перевірка на рівність
    if (num1 == num2) {
        std::cout << "The numbers are equal." << std::endl;
    }
    else {
        // Виведення чисел за зростанням
        if (num1 < num2) {
            std::cout << "Numbers in ascending order: " << num1 << ", " << num2 << std::endl;
        }
        else {
            std::cout << "Numbers in ascending order: " << num2 << ", " << num1 << std::endl;
        }
    }

    return 0;
}
