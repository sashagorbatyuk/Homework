#include <iostream>
using namespace std;

/// <summary>
/// Шаблон для обчислення середнього значення: Напишіть шаблон функції, яка обчислює середнє арифметичне масиву значень будь-якого типу. Перевірте функцію на масивах цілих та дійсних чисел.
/// </summary>

template <typename T>
T average(const T* array, int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}

int main() {
    // Перевірка для масиву цілих чисел
    int intArray[] = { 1, 2, 3, 4, 5 };
    int intAvg = average(intArray, 5);
    cout << "Average (int): " << intAvg << endl;

    // Перевірка для масиву дійсних чисел
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double doubleAvg = average(doubleArray, 5);
    cout << "Average (double): " << doubleAvg << endl;

    return 0;
}
