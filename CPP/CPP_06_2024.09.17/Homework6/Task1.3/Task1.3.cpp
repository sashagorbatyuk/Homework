#include <iostream>

using namespace std;

/// <summary>
/// �������� 3. ������ ������ ����������� ��� ����� ����� �� 1 �� 1000.
/// </summary>
int main() {
    int sum = 0;
    int count = 1000;

    for (int i = 1; i <= 1000; i++) {
        sum += i;
    }

    double average = static_cast<double>(sum) / count;

    cout << "The arithmetic mean of all integers from 1 to 1000 is: " << average << endl;

    return 0;
}
