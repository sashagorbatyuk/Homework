#include <iostream>

/// <summary>
/// �������� 2.2 ���������� ������� � ��������� �����.���� ���� �����, ��������� ���� �� ���, ������ � ������� �� ���. ��������� ������� �� �����
/// </summary>
int main() {
    int number;

    // �������� �����
    std::cout << "Enter a number: ";
    std::cin >> number;

    // ��������, �� � ����� ������ ��� ��������
    if (number % 2 == 0) {
        // ���� �����, ��������� �� ���
        number *= 3;
        std::cout << "The number is even. After multiplying by 3: " << number << std::endl;
    }
    else {
        // ���� �������, ������� �� ���
        number /= 2;
        std::cout << "The number is odd. After dividing by 2: " << number << std::endl;
    }

    return 0;
}
