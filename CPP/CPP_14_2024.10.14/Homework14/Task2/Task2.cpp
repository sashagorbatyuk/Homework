#include <iostream>
#include <vector>

using namespace std;

// Функція видаляє стовпчик із двовимірного масиву за вказаним номером
void removeColumn(vector<vector<int>>& matrix, int columnIndex) {
    // Перевіряємо, чи вказаний індекс стовпчика є валідним
    if (matrix.empty() || columnIndex < 0 || columnIndex >= matrix[0].size()) {
        cout << "Error: Invalid column index." << endl;
        return;
    }

    // Видаляємо стовпчик з кожного рядка
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].erase(matrix[i].begin() + columnIndex);
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
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Видаляємо стовпчик з індексом 2
    removeColumn(matrix, 2);

    printMatrix(matrix);

    return 0;
}
