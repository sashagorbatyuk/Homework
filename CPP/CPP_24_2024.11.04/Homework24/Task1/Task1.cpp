#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

// Функція для знаходження максимального елемента масиву
template <typename T>
T findMax(const vector<T>& arr) {
    T maxElem = arr[0];
    for (const auto& elem : arr) {
        if (elem > maxElem) {
            maxElem = elem;
        }
    }
    return maxElem;
}

// Функція для знаходження мінімального елемента масиву
template <typename T>
T findMin(const vector<T>& arr) {
    T minElem = arr[0];
    for (const auto& elem : arr) {
        if (elem < minElem) {
            minElem = elem;
        }
    }
    return minElem;
}

// Функція для сортування масиву
template <typename T>
void sortArray(vector<T>& arr) {
    sort(arr.begin(), arr.end()); // Сортуємо масив
}

// Функція для двійкового пошуку
template <typename T>
int binarySearch(const vector<T>& arr, const T& target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Знайдено
        }
        if (arr[mid] < target) {
            left = mid + 1; // Шукаємо в правій частині
        }
        else {
            right = mid - 1; // Шукаємо в лівій частині
        }
    }
    return -1; // Не знайдено
}

// Функція для заміни елемента масиву на передане значення
template <typename T>
void replaceElement(vector<T>& arr, int index, const T& newValue) {
    if (index >= 0 && index < arr.size()) {
        arr[index] = newValue; // Заміна елемента
    }

    else {
        cout << "Index out of bounds!" << endl; // Виводимо повідомлення про помилку
    }
}

int main() {
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6 };

    cout << "Original array: ";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Max: " << findMax(arr) << endl; // Знаходимо максимальний елемент
    cout << "Min: " << findMin(arr) << endl; // Знаходимо мінімальний елемент

    sortArray(arr); // Сортуємо масив
    cout << "Sorted array: ";
    for (const auto& num : arr) 
    {
        cout << num << " ";
    } cout << endl;

    int target = 5;

    int index = binarySearch(arr, target); // Виконуємо двійковий пошук

    if (index != -1) {
        cout << "Found " << target << " at index: " << index << endl;
    }
    else {
        cout << target << " not found!" << endl;
    }

    replaceElement(arr, 2, 10); // Замінюємо елемент
    cout << "Array after replacement: ";
    
    for (const auto& num : arr) {
        cout << num << " ";
    } cout << endl;

    return 0;
}