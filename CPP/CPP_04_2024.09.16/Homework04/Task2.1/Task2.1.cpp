#include <iostream>

/// <summary>
/// Завдання 2.1. Користувач з клавіатури вводить 5 оцінок студента
/// Визначити, чи допущений студент до іспиту
/// Студент отримує допуск, якщо його середній бал 4 і вище
/// </summary>
int main() {
    const int num_grades = 5;
    int grades[num_grades];
    int sum = 0;

    // Введення 5 оцінок
    std::cout << "Enter 5 grades: ";
    for (int i = 0; i < num_grades; ++i) {
        std::cin >> grades[i];
        sum += grades[i]; // Сума оцінок
    }

    // Обчислення середнього балу
    double average = static_cast<double>(sum) / num_grades;

    // Визначення, чи допущений студент
    if (average >= 4.0) {
        std::cout << "Student is allowed to take the exam. Average grade: " << average << std::endl;
    }
    else {
        std::cout << "Student is not allowed to take the exam. Average grade: " << average << std::endl;
    }

    return 0;
}
