#include <iostream>
#include <vector>

using namespace std;

// ������� ������� �������� �� ����������� ������ �� �������� �������
void removeColumn(vector<vector<int>>& matrix, int columnIndex) {
    // ����������, �� �������� ������ ��������� � �������
    if (matrix.empty() || columnIndex < 0 || columnIndex >= matrix[0].size()) {
        cout << "Error: Invalid column index." << endl;
        return;
    }

    // ��������� �������� � ������� �����
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].erase(matrix[i].begin() + columnIndex);
    }
}

// ������� ��� ������ ������� �� �����
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

    // ��������� �������� � �������� 2
    removeColumn(matrix, 2);

    printMatrix(matrix);

    return 0;
}
