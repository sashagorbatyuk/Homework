#include <iostream>

/// <summary>
/// Завдання 2.2 Користувач вводить з клавіатури число.Якщо воно парне, помножити його на три, інакше — поділити на два. Результат вивести на екран
/// </summary>
int main() {
    int number;

    // Введення числа
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Перевірка, чи є число парним або непарним
    if (number % 2 == 0) {
        // Якщо парне, помножити на три
        number *= 3;
        std::cout << "The number is even. After multiplying by 3: " << number << std::endl;
    }
    else {
        // Якщо непарне, поділити на два
        number /= 2;
        std::cout << "The number is odd. After dividing by 2: " << number << std::endl;
    }

    return 0;
}
