#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// �������� 2.3. ���������� ������� ����-��� ���� �����. 
/// ��������� � ����� ������ ����� �������� �� ����� 3 � 6 � ������� ����� �� �����.
/// </summary>
int main() {
    int number;
    string result = "";

    cout << "Enter an integer: ";
    cin >> number;

    string numberStr = to_string(number);

    for (char digit : numberStr) {
        if (digit != '3' && digit != '6') {
            result += digit;
        }
    }

    if (result.empty()) {
        cout << "All digits were removed." << endl;
    }
    else {
        cout << "Number after removing digits 3 and 6: " << result << endl;
    }

    return 0;
}
