#include <iostream>

using namespace std;

/// <summary>
/// �������� 2. �������� �������, ��� ������ � ����� ��������� 2 ����� ����� �� ������� ���� ����� �� �������� �� ����
/// </summary>
int sumInRange(int a, int b) {
    int sum = 0;

    // ��������� �������� � ����������� ��������
    int start = min(a, b);
    int end = max(a, b);

    // ������ �� ����� �� start �� end (�������)
    for (int i = start; i <= end; ++i) {
        sum += i;
    }

    return sum;
}

int main() {
    int num1, num2;

    // �������� ���� ����� �����
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // ���������� ���� ����� � �������
    int result = sumInRange(num1, num2);

    // ��������� ����������
    cout << "Sum of numbers between " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
