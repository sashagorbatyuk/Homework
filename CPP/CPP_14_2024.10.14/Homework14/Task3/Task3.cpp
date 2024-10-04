#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ������� ��� ��������� ����� ����� ��� ��������
void shiftMatrix(vector<vector<int>>& matrix, int steps, const string& direction) {
    int M = matrix.size();
    int N = matrix[0].size();

    // ���� ����� �����/����
    if (direction == "up" || direction == "down") {
        steps = steps % M;
        if (direction == "down") {
            steps = M - steps;
        }

        // ������ �������� ���� �����
        vector<vector<int>> temp(matrix.begin(), matrix.begin() + steps);
        matrix.erase(matrix.begin(), matrix.begin() + steps);
        matrix.insert(matrix.end(), temp.begin(), temp.end());
    }

    // ���� �������� ����/������
    else if (direction == "left" || direction == "right") {
        steps = steps % N;
        if (direction == "right") {
            steps = N - steps;
        }

        for (int i = 0; i < M; ++i) {
            vector<int> temp(matrix[i].begin(), matrix[i].begin() + steps);
            matrix[i].erase(matrix[i].begin(), matrix[i].begin() + steps);
            matrix[i].insert(matrix[i].end(), temp.begin(), temp.end());
        }
    }
}

// ������� ��� ���������� ������� ����������� �������
void fillMatrix(vector<vector<int>>& matrix) {
    srand(time(0));
    for (auto& row : matrix) {
        for (auto& elem : row) {
            elem = rand() % 100;
        }
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
    int M = 4;
    int N = 5;

    vector<vector<int>> matrix(M, vector<int>(N));

    fillMatrix(matrix);

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    shiftMatrix(matrix, 2, "right");

    cout << "\nMatrix after shifting right by 2 steps:" << endl;
    printMatrix(matrix);

    return 0;
}
