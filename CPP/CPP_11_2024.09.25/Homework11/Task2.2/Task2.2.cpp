#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// Завдання 2. Написати функцію, що реалізує алгоритм бінарного пошуку заданого ключа в одновимірному масиві
/// </summary>
int binarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;

    // Поки індекси не перетнулися
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    // Якщо ключ не знайдено
    return -1;
}

int main() {
    int size, key;

    // Введення розміру масиву
    cout << "Enter the size of the array: ";
    cin >> size;

    // Створення вектора заданого розміру
    vector<int> arr(size);

    // Введення відсортованих елементів вектора
    cout << "Enter the sorted elements of the array: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Введення ключа для пошуку
    cout << "Enter the key to search: ";
    cin >> key;

    // Виклик функції бінарного пошуку
    int result = binarySearch(arr, key);

    // Виведення результату
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
