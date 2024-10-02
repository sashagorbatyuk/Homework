#include <iostream>
#include <algorithm>

using namespace std;

// Функція для ініціалізації квадратної матриці (перевантажена для int, double, char)
void initializeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;  // випадкові числа від 0 до 99
        }
    }
}

void initializeMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = static_cast<double>(rand() % 1000) / 100.0;  // випадкові дробові числа
        }
    }
}

void initializeMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 'A' + rand() % 26;  // випадкові літери від 'A' до 'Z'
        }
    }
}

// Функція для виведення матриці на екран (перевантажена для int, double, char)
void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція для визначення максимального і мінімального елемента на головній діагоналі
template <typename T>
void findMinMaxDiagonal(T** matrix, int size, T& minElem, T& maxElem) {
    minElem = matrix[0][0];
    maxElem = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] < minElem) {
            minElem = matrix[i][i];
        }
        if (matrix[i][i] > maxElem) {
            maxElem = matrix[i][i];
        }
    }
}

// Функція для сортування рядків матриці за зростанням
template <typename T>
void sortMatrixRows(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        sort(matrix[i], matrix[i] + size);
    }
}

// Основна функція для демонстрації роботи
int main() {
    int size = 4;  // розмір матриці

    // Для цілих чисел
    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        intMatrix[i] = new int[size];
    }
    initializeMatrix(intMatrix, size);
    cout << "Int Matrix:\n";
    printMatrix(intMatrix, size);
    int intMin, intMax;
    findMinMaxDiagonal(intMatrix, size, intMin, intMax);
    cout << "Min on diagonal (int): " << intMin << ", Max on diagonal (int): " << intMax << endl;
    sortMatrixRows(intMatrix, size);
    cout << "Sorted Int Matrix:\n";
    printMatrix(intMatrix, size);

    // Для дійсних чисел
    double** doubleMatrix = new double* [size];
    for (int i = 0; i < size; ++i) {
        doubleMatrix[i] = new double[size];
    }
    initializeMatrix(doubleMatrix, size);
    cout << "\nDouble Matrix:\n";
    printMatrix(doubleMatrix, size);
    double doubleMin, doubleMax;
    findMinMaxDiagonal(doubleMatrix, size, doubleMin, doubleMax);
    cout << "Min on diagonal (double): " << doubleMin << ", Max on diagonal (double): " << doubleMax << endl;
    sortMatrixRows(doubleMatrix, size);
    cout << "Sorted Double Matrix:\n";
    printMatrix(doubleMatrix, size);

    // Для символів
    char** charMatrix = new char* [size];
    for (int i = 0; i < size; ++i) {
        charMatrix[i] = new char[size];
    }
    initializeMatrix(charMatrix, size);
    cout << "\nChar Matrix:\n";
    printMatrix(charMatrix, size);
    char charMin, charMax;
    findMinMaxDiagonal(charMatrix, size, charMin, charMax);
    cout << "Min on diagonal (char): " << charMin << ", Max on diagonal (char): " << charMax << endl;
    sortMatrixRows(charMatrix, size);
    cout << "Sorted Char Matrix:\n";
    printMatrix(charMatrix, size);

    // Очищення пам'яті
    for (int i = 0; i < size; ++i) {
        delete[] intMatrix[i];
        delete[] doubleMatrix[i];
        delete[] charMatrix[i];
    }
    delete[] intMatrix;
    delete[] doubleMatrix;
    delete[] charMatrix;

    return 0;
}
