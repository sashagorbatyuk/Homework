#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/// <summary>
/// Завдання 3. Створіть двовимірний масив. Заповніть його випадковими числами і покажіть на екран.
/// Користувач вибирає кількість зрушень і положення(вліво, вправо, вгору, вниз).Виконати зрушення масиву і показати на екран отриманий результат.Зрушення циклічне.
/// </summary>
void printArray(const vector<vector<int>>& array) {
    for (const auto& row : array) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}

// Функція для циклічного зрушення масиву вліво
void shiftLeft(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int s = 0; s < shifts; ++s) {
            int first = array[i][0];  // Запам'ятовуємо перший елемент
            for (int j = 0; j < cols - 1; ++j) {
                array[i][j] = array[i][j + 1];  // Зміщуємо вліво
            }
            array[i][cols - 1] = first;  // Останній елемент отримує перше значення
        }
    }
}

// Функція для циклічного зрушення масиву вправо
void shiftRight(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int s = 0; s < shifts; ++s) {
            int last = array[i][cols - 1];  // Запам'ятовуємо останній елемент
            for (int j = cols - 1; j > 0; --j) {
                array[i][j] = array[i][j - 1];  // Зміщуємо вправо
            }
            array[i][0] = last;  // Перший елемент отримує останнє значення
        }
    }
}

// Функція для циклічного зрушення масиву вгору
void shiftUp(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int s = 0; s < shifts; ++s) {
        vector<int> firstRow = array[0];  // Запам'ятовуємо перший рядок
        for (int i = 0; i < rows - 1; ++i) {
            array[i] = array[i + 1];  // Зміщуємо вгору
        }
        array[rows - 1] = firstRow;  // Останній рядок отримує перший рядок
    }
}

// Функція для циклічного зрушення масиву вниз
void shiftDown(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int s = 0; s < shifts; ++s) {
        vector<int> lastRow = array[rows - 1];  // Запам'ятовуємо останній рядок
        for (int i = rows - 1; i > 0; --i) {
            array[i] = array[i - 1];  // Зміщуємо вниз
        }
        array[0] = lastRow;  // Перший рядок отримує останній рядок
    }
}

int main() {
    srand(time(0));  // Ініціалізація генератора випадкових чисел

    // Введення розміру масиву
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Створення і заповнення масиву випадковими числами
    vector<vector<int>> array(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 10;  // Випадкові числа в діапазоні [0, 9]
        }
    }

    // Виведення початкового масиву
    cout << "Initial array:" << endl;
    printArray(array);

    // Вибір кількості зрушень і напряму
    int shifts;
    string direction;
    cout << "Enter the number of shifts: ";
    cin >> shifts;
    cout << "Enter the direction (left, right, up, down): ";
    cin >> direction;

    // Виконання циклічного зрушення
    if (direction == "left") {
        shiftLeft(array, shifts);
    }
    else if (direction == "right") {
        shiftRight(array, shifts);
    }
    else if (direction == "up") {
        shiftUp(array, shifts);
    }
    else if (direction == "down") {
        shiftDown(array, shifts);
    }
    else {
        cout << "Invalid direction!" << endl;
        return 1;
    }

    // Виведення результату після зрушення
    cout << "Array after shift:" << endl;
    printArray(array);

    return 0;
}
