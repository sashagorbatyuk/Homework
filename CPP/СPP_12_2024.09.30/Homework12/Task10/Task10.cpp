#include <iostream>
using namespace std;

/// <summary>
/// Шаблон для пошуку індексу: Напишіть шаблон функції, яка шукає індекс першої появи елемента у масиві будь-якого типу. Якщо елемент не знайдений, функція повинна повертати -1.
/// </summary>
template <typename T>
int findIndex(const T* array, int size, T element) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return i;  // Повертаємо індекс першої появи елемента
        }
    }
    return -1;  // Якщо елемент не знайдений
}

int main() {
    // Перевірка для масиву цілих чисел
    int intArray[] = { 1, 2, 3, 4, 5 };
    int intIndex = findIndex(intArray, 5, 3);
    cout << "Index of 3 in int array: " << intIndex << endl;

    // Перевірка для масиву дійсних чисел
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleIndex = findIndex(doubleArray, 5, 4.4);
    cout << "Index of 4.4 in double array: " << doubleIndex << endl;

    // Перевірка на відсутність елемента
    int notFoundIndex = findIndex(intArray, 5, 10);
    cout << "Index of 10 in int array: " << notFoundIndex << endl;

    return 0;
}
