#include <iostream>

/// <summary>
/// �������� 1.4. ���������� ������� ��� �����. ���������, �� ��� �� �����, � ���� �, ������� �� �� ����� �� ����������
/// </summary>
int main() {
    int num1, num2;

    // �������� ���� �����
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // �������� �� ������
    if (num1 == num2) {
        std::cout << "The numbers are equal." << std::endl;
    }
    else {
        // ��������� ����� �� ����������
        if (num1 < num2) {
            std::cout << "Numbers in ascending order: " << num1 << ", " << num2 << std::endl;
        }
        else {
            std::cout << "Numbers in ascending order: " << num2 << ", " << num1 << std::endl;
        }
    }

    return 0;
}
