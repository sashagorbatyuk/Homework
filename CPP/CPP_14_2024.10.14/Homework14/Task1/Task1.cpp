#include <iostream>
#include <vector>

using namespace std;

// Функція додає стовпчик до двовимірного масиву в зазначену позицію
void addColumn(vector<vector<int>>& matrix, const vector<int>& newColumn, int position) {
    // Перевіряємо чи розмір нового стовпчика співпадає з кількістю рядків у матриці
    if (matrix.size() != newColumn.size()) {
        cout << "Error: The number of rows in the matrix and the new column must match." << endl;
        return;
    }

    // Додаємо елементи нового стовпчика на відповідні позиції у рядках
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, newColumn[i]);
    }
}

// Функція для виводу матриці на екран
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> newColumn = { 10, 11, 12 };

    addColumn(matrix, newColumn, 1);

    printMatrix(matrix);

    return 0;
}
