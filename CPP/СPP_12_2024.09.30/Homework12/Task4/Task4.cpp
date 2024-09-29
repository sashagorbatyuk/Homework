#include <iostream>
using namespace std;

/// <summary>
/// Шаблон для пошуку максимального елемента у масиві: Реалізуйте шаблон функції, яка знаходить максимальний елемент у масиві будь-якого типу. Перевірте функцію на масивах цілих і дійсних чисел.
/// </summary>

template <typename T>
T getMaxElement(const T* array, int size) {
    T maxElement = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    cout << "Max element: " << maxElement << endl;
    return maxElement;
}

int main() {
    // Перевірка для масиву цілих чисел
    int intArray[] = { 1, 9, 3, 7, 5 };
    int maxInt = getMaxElement(intArray, 5);
    cout << "Max integer: " << maxInt << endl;

    // Перевірка для масиву дійсних чисел
    double doubleArray[] = { 2.2, 3.3, 1.1, 5.5, 4.4 };
    double maxDouble = getMaxElement(doubleArray, 5);
    cout << "Max double: " << maxDouble << endl;

    return 0;
}
