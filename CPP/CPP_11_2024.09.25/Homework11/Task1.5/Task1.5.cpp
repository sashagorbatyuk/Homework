#include <iostream>

using namespace std;

/// <summary>
/// �������� 5. �������� �������, �� �������, �� � ��������� ����������� �����.
/// </summary>
bool isLuckyNumber(int number) {
    // ����������, �� ����� �����������
    if (number < 100000 || number > 999999) {
        cout << "The number is not six digits." << endl;
        return false;
    }

    // �������� ����� �����
    int firstHalfSum = 0, secondHalfSum = 0;
    int digits[6];

    // ��������� ����� �� ����� �����
    for (int i = 5; i >= 0; --i) {
        digits[i] = number % 10;
        number /= 10;
    }

    // ���������� ���� ������ ����� � ������� ����� ����
    for (int i = 0; i < 3; ++i) {
        firstHalfSum += digits[i];
        secondHalfSum += digits[i + 3];
    }

    // ��������� ����
    return firstHalfSum == secondHalfSum;
}

int main() {
    int number;

    // �������� �����
    cout << "Enter a six-digit number: ";
    cin >> number;

    // ��������, �� � ����� ��������
    if (isLuckyNumber(number)) {
        cout << "The number is lucky!" << endl;
    }
    else {
        cout << "The number is not lucky." << endl;
    }

    return 0;
}
