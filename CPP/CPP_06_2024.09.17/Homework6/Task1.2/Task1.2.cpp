#include <iostream>
#include <cmath>  // for the pow() function

using namespace std;

/// <summary>
/// �������� 2. �������� ��������, ��� ������ ��� ����� ����� x � y, 
/// ���� ���� �������� � �������� �������� x � ������ y
/// </summary>
int main() {
    int x, y;

    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (y): ";
    cin >> y;

    double result = pow(x, y);

    cout << x << " raised to the power of " << y << " is: " << result << endl;

    return 0;
}
