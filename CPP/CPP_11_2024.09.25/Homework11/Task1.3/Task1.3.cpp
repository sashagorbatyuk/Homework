#include <iostream>

using namespace std;

/// <summary>
/// �������� 3. ����� ���������� ����������, ���� ���� ��� ���� ������� ������� ���� ������. �������� ������� ������ ����� ����� � ��������� ��������.
/// </summary>
bool isPerfect(int num) {
    int sum = 0;

    // ��������� �� ������� ����� � ������ ��
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // ���� ���� ������� ������� ������ �����, �� �� ��������� �����
    return sum == num;
}

// ������� ��� ������ ��� ���������� ����� � �������
void findPerfectNumbersInRange(int start, int end) {
    cout << "Perfect numbers in the range from " << start << " to " << end << " are: " << endl;

    bool found = false;
    for (int i = start; i <= end; ++i) {
        if (isPerfect(i)) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No perfect numbers found in this range." << endl;
    }
}

int main() {
    int start, end;

    // �������� ���������
    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;

    // ����� ���������� ����� � �������
    findPerfectNumbersInRange(start, end);

    return 0;
}
