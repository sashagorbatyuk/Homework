#include <iostream>

using namespace std;

/// <summary>
/// �������� 2.1. ϳ��������� ������� ����� ����� � ������� �� 100 �� 999, �� ����� �� ������� �����
/// </summary>
int main() {
    int count = 0;

    for (int num = 100; num <= 999; num++) {
        int hundreds = num / 100; // First digit (hundreds)
        int tens = (num / 10) % 10; // Second digit (tens)
        int ones = num % 10; // Third digit (ones)

        if (hundreds == tens || hundreds == ones || tens == ones) {
            count++;
        }
    }

    cout << "The number of integers between 100 and 999 with two identical digits is: " << count << endl;

    return 0;
}
