#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/// <summary>
/// �������� 3. ������� ���������� �����. �������� ���� ����������� ������� � ������� �� �����.
/// ���������� ������ ������� ������� � ���������(����, ������, �����, ����).�������� �������� ������ � �������� �� ����� ��������� ���������.�������� �������.
/// </summary>
void printArray(const vector<vector<int>>& array) {
    for (const auto& row : array) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ��������� �������� ������ ����
void shiftLeft(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int s = 0; s < shifts; ++s) {
            int first = array[i][0];  // �����'������� ������ �������
            for (int j = 0; j < cols - 1; ++j) {
                array[i][j] = array[i][j + 1];  // ������ ����
            }
            array[i][cols - 1] = first;  // ������� ������� ������ ����� ��������
        }
    }
}

// ������� ��� ��������� �������� ������ ������
void shiftRight(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int s = 0; s < shifts; ++s) {
            int last = array[i][cols - 1];  // �����'������� ������� �������
            for (int j = cols - 1; j > 0; --j) {
                array[i][j] = array[i][j - 1];  // ������ ������
            }
            array[i][0] = last;  // ������ ������� ������ ������ ��������
        }
    }
}

// ������� ��� ��������� �������� ������ �����
void shiftUp(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int s = 0; s < shifts; ++s) {
        vector<int> firstRow = array[0];  // �����'������� ������ �����
        for (int i = 0; i < rows - 1; ++i) {
            array[i] = array[i + 1];  // ������ �����
        }
        array[rows - 1] = firstRow;  // ������� ����� ������ ������ �����
    }
}

// ������� ��� ��������� �������� ������ ����
void shiftDown(vector<vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    for (int s = 0; s < shifts; ++s) {
        vector<int> lastRow = array[rows - 1];  // �����'������� ������� �����
        for (int i = rows - 1; i > 0; --i) {
            array[i] = array[i - 1];  // ������ ����
        }
        array[0] = lastRow;  // ������ ����� ������ ������� �����
    }
}

int main() {
    srand(time(0));  // ����������� ���������� ���������� �����

    // �������� ������ ������
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // ��������� � ���������� ������ ����������� �������
    vector<vector<int>> array(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 10;  // �������� ����� � ������� [0, 9]
        }
    }

    // ��������� ����������� ������
    cout << "Initial array:" << endl;
    printArray(array);

    // ���� ������� ������� � �������
    int shifts;
    string direction;
    cout << "Enter the number of shifts: ";
    cin >> shifts;
    cout << "Enter the direction (left, right, up, down): ";
    cin >> direction;

    // ��������� ��������� ��������
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

    // ��������� ���������� ���� ��������
    cout << "Array after shift:" << endl;
    printArray(array);

    return 0;
}
