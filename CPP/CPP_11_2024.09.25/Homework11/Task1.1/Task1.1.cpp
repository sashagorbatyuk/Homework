#include <iostream>
using namespace std;

/// <summary>
/// �������� 1. �������� �������, ��� ������ ��� ���������: ������ ������� � �������� �������, �� �������� ������ ����� �� ����� ��������� �����.
/// </summary>
double power(double base, int exponent) {
    double result = 1;  // ���������� ��������� �� 1
    for (int i = 0; i < abs(exponent); ++i) {
        result *= base;  // ������� ��������� �� ������ exponent ����
    }

    // ���� �������� ������� ��'�����, ��������� ��������� ���������
    if (exponent < 0) {
        return 1 / result;
    }

    return result;
}

int main() {
    double base;
    int exponent;

    // �������� ������ � ��������� �������
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    // ���������� � ��������� ����������
    double result = power(base, exponent);
    cout << base << " raised to the power of " << exponent << " is: " << result << endl;

    return 0;
}
