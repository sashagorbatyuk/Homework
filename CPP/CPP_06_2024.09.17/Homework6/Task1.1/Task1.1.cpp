#include <iostream>

using namespace std;

/// <summary>
/// �������� 1. �������� ��������, ��� �������� ���� ����� ����� �� � �� 500 (�������� a ��������� � ���������).
/// </summary>
int main() {
    int a;
    int sum = 0;

    cout << "Enter a value for a: ";
    cin >> a;

    for (int i = a; i <= 500; i++) {
        sum += i;
    }

    cout << "The sum of integers from " << a << " to 500 is: " << sum << endl;

    return 0;
}
