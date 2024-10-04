#include <iostream>
#include <vector>

using namespace std;

// ������� ���� �������� �� ����������� ������ � ��������� �������
void addColumn(vector<vector<int>>& matrix, const vector<int>& newColumn, int position) {
    // ���������� �� ����� ������ ��������� ������� � ������� ����� � �������
    if (matrix.size() != newColumn.size()) {
        cout << "Error: The number of rows in the matrix and the new column must match." << endl;
        return;
    }

    // ������ �������� ������ ��������� �� ������� ������� � ������
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, newColumn[i]);
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> newColumn = { 10, 11, 12 };

    addColumn(matrix, newColumn, 1);

    printMatrix(matrix);

    return 0;
}
