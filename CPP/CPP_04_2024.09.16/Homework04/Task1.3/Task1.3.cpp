#include <iostream>

/// <summary>
/// �������� 1.3. ���������� ������� �����. ���������, ������� �� �����, ��'���� �� ������� ����
/// </summary>
int main() {
    int number;

    // �������� �����
    std::cout << "Enter a number: ";
    std::cin >> number;

    // �������� �����
    if (number > 0) {
        std::cout << number << " is positive." << std::endl;
    }
    else if (number < 0) {
        std::cout << number << " is negative." << std::endl;
    }
    else {
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}
