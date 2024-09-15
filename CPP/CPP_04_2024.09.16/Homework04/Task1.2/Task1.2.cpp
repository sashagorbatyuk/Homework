#include <iostream>

/// <summary>
/// Завдання 1.2. Користувач вводить два числа. Вивести наекран менше з цих чисел
/// </summary>
int main() {
    int num1, num2;

    // Запитуємо два числа
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Порівнюємо числа і виводимо менше
    if (num1 < num2) {
        std::cout << "The smaller number is: " << num1 << std::endl;
    }
    else if (num2 < num1) {
        std::cout << "The smaller number is: " << num2 << std::endl;
    }
    else {
        std::cout << "Both numbers are equal." << std::endl;
    }

    return 0;
}
