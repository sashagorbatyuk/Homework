#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// �������� 2. �������� �������, �� ������ �������� �������� ������ �������� ����� � ������������ �����
/// </summary>
int binarySearch(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;

    // ���� ������� �� �����������
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    // ���� ���� �� ��������
    return -1;
}

int main() {
    int size, key;

    // �������� ������ ������
    cout << "Enter the size of the array: ";
    cin >> size;

    // ��������� ������� �������� ������
    vector<int> arr(size);

    // �������� ������������ �������� �������
    cout << "Enter the sorted elements of the array: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // �������� ����� ��� ������
    cout << "Enter the key to search: ";
    cin >> key;

    // ������ ������� �������� ������
    int result = binarySearch(arr, key);

    // ��������� ����������
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
