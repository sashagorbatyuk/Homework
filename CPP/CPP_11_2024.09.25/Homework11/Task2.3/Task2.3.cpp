#include <iostream>
#include <cmath>
using namespace std;

/// <summary>
/// �������� 3. �������� ������� ��� ����������� �����,���������� � ��������� ������, � ��������� �������.
/// </summary>
int binaryToDecimal(long long binary) {
    int decimal = 0, i = 0;

    // ������ ����� ����� ��������� �����
    while (binary != 0) {
        // ������ ������� ����� ����� (0 ��� 1)
        int remainder = binary % 10;
        // ������ �� ����������� ����� �������� �������� ����� ��������� �����, ��������� �� 2^i
        decimal += remainder * pow(2, i);
        // ���������� �� �������� �����
        binary /= 10;
        i++;
    }

    return decimal;
}

int main() {
    long long binary;

    // �������� ��������� �����
    cout << "Enter a binary number: ";
    cin >> binary;

    // ������ ������� ��� ����������� � ��������� �������
    int decimal = binaryToDecimal(binary);

    // ��������� ����������
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}
