#include <iostream>
using namespace std;

/// <summary>
/// �������� 1. �������� �������, �� ������ �������� ������� ������ �������� ����� � ������������ �����.
/// </summary>
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;  // ��������� ������ ���������� �����
        }
    }
    return -1;  // ���� ���� �� ��������
}

int main() {
    int size, key;

    // �������� ������ ������
    cout << "Enter the size of the array: ";
    cin >> size;

    // �������� �������� ���'�� ��� ������
    int* arr = new int[size];

    // �������� �������� ������
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // �������� ����� ��� ������
    cout << "Enter the key to search: ";
    cin >> key;

    // ������ ������� ������� ������
    int result = linearSearch(arr, size, key);

    // ��������� ����������
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }

    // ��������� ���'��
    delete[] arr;

    return 0;
}
