#include <iostream>

/// <summary>
/// Завдання 1.1. Користувач вводить число. Визначити, чи є воно парним
/// </summary>
int main() {
    int number;

    // Ask the user for a number
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Check if the number is even or odd
    if (number % 2 == 0) {
        std::cout << number << " is even." << std::endl;
    }
    else {
        std::cout << number << " is odd." << std::endl;
    }

    return 0;
}