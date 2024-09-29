#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/// <summary>
/// Сума елементів масиву: Напишіть шаблон функції, яка підраховує суму елементів масиву будь-якого типу. Використайте функцію для масивів цілих, дійсних і дробових чисел.
/// </summary>

// Шаблон функції для підрахунку суми елементів масиву
template <typename T>
T sumArray(const vector<T>& arr) {
    return accumulate(arr.begin(), arr.end(), T(0));
}

int main() {
    // Масив цілих чисел
    vector<int> intArray = { 1, 2, 3, 4, 5 };
    cout << "Sum of integers: " << sumArray(intArray) << endl;

    // Масив дійсних чисел
    vector<double> doubleArray = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "Sum of doubles: " << sumArray(doubleArray) << endl;

    // Масив дробових чисел
    vector<float> floatArray = { 1.5f, 2.5f, 3.5f };
    cout << "Sum of floats: " << sumArray(floatArray) << endl;

    return 0;
}