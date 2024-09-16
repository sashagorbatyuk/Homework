#include <iostream>
#include <cmath>

using namespace std;

/// <summary>
/// �������� 2.4. ���������� ������� ����-��� ���� ����� �.
/// ��������� ������� �� ��� ����� �, ��� ���� � ������� ��� ������� �� �*� � �� ������� ��� ������� �� �*�*�.
/// </summary>
int main() {
    int A;

    cout << "Enter an integer A: ";
    cin >> A;

    // ���������� �� ������ �������� B
    for (int B = 1; B <= sqrt(A); B++) {
        if (A % (B * B) == 0 && A % (B * B * B) != 0) {
            cout << B << " is a valid number where A is divisible by B^2 but not by B^3." << endl;
        }
    }

    return 0;
}
