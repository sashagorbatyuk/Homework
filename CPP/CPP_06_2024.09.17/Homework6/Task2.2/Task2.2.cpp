#include <iostream>

using namespace std;

/// <summary>
/// �������� 2.2. ϳ��������� ������� ����� ����� � ������� �� 100 �� 999, � ���� �� ����� ���.
/// </summary>
int main() {
    int count = 0;

    for (int num = 100; num <= 999; num++) {
        int hundreds = num / 100;
        int tens = (num / 10) % 10;
        int ones = num % 10;

        if (hundreds != tens && hundreds != ones && tens != ones) {
            count++;
        }
    }

    cout << "The number of integers between 100 and 999 with all distinct digits is: " << count << endl;

    return 0;
}
