#include <iostream>

using namespace std;

/// <summary>
/// �������� 2.6. ���������� ������� ���� �����. 
/// ��������� ������� �� ��� �����, �� �� ������ ����� ������� ��� �������
/// </summary>
int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    cout << "The divisors of " << number << " are: ";

    for (int i = 1; i <= abs(number); i++) {
        if (number % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
