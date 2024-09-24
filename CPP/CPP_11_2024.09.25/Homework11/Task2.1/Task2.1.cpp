#include <iostream>
using namespace std;

/// <summary>
/// Завдання 1. Написати функцію, що реалізує алгоритм лінійного пошуку заданого ключа в одновимірному масиві.
/// </summary>
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;  // Повертаємо індекс знайденого ключа
        }
    }
    return -1;  // Якщо ключ не знайдено
}

int main() {
    int size, key;

    // Введення розміру масиву
    cout << "Enter the size of the array: ";
    cin >> size;

    // Динамічне виділення пам'яті для масиву
    int* arr = new int[size];

    // Введення елементів масиву
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Введення ключа для пошуку
    cout << "Enter the key to search: ";
    cin >> key;

    // Виклик функції лінійного пошуку
    int result = linearSearch(arr, size, key);

    // Виведення результату
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }

    // Звільнення пам'яті
    delete[] arr;

    return 0;
}
