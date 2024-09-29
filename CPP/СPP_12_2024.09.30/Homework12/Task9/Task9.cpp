#include <iostream>
using namespace std;

/// <summary>
/// Шаблон для перестановки значень: Реалізуйте шаблон функції, яка переставляє місцями два елементи масиву на позиціях i і j. Перевірте її для масивів цілих і дійсних чисел.
/// </summary>
template <typename T>
void swapElements(T* array, int i, int j) {
    T temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int main() {
    // Перевірка для масиву цілих чисел
    int intArray[] = { 1, 2, 3, 4, 5 };
    cout << "Before swap (int array): ";
    for (int k = 0; k < 5; ++k) {
        cout << intArray[k] << " ";
    }
    cout << std::endl;

    // Перестановка елементів на позиціях 1 і 3
    swapElements(intArray, 1, 3);

    cout << "After swap (int array): ";
    for (int k = 0; k < 5; ++k) {
        cout << intArray[k] << " ";
    }
    cout << endl;

    // Перевірка для масиву дійсних чисел
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "Before swap (double array): ";
    for (int k = 0; k < 5; ++k) {
        cout << doubleArray[k] << " ";
    }
    cout << endl;

    // Перестановка елементів на позиціях 0 і 4
    swapElements(doubleArray, 0, 4);

    cout << "After swap (double array): ";
    for (int k = 0; k < 5; ++k) {
        cout << doubleArray[k] << " ";
    }
    cout << endl;

    return 0;
}
