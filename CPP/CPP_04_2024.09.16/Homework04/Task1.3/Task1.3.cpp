#include <iostream>

/// <summary>
/// Завдання 1.3. Користувач вводить число. Визначити, додатне це число, від'ємне чи дорівнює нулю
/// </summary>
int main() {
    int number;

    // Введення числа
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Перевірка числа
    if (number > 0) {
        std::cout << number << " is positive." << std::endl;
    }
    else if (number < 0) {
        std::cout << number << " is negative." << std::endl;
    }
    else {
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}
