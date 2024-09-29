#include <iostream>
using namespace std;

/// <summary>
/// Шаблон для підрахунку кількості елементів: Напишіть шаблон функції, яка підраховує кількість елементів у масиві будь-якого типу. Передайте довжину масиву як аргумент.
/// </summary>

template <typename T>
int countElements(const T* array, int size) {
    return size;
}

int main() {
    // Перевірка для масиву цілих чисел
    int intArray[] = { 1, 2, 3, 4, 5 };
    int intCount = countElements(intArray, 5);
    cout << "Number of elements (int array): " << intCount << endl;

    // Перевірка для масиву дійсних чисел
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleCount = countElements(doubleArray, 5);
    cout << "Number of elements (double array): " << doubleCount << endl;

    return 0;
}
