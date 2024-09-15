#include <iostream>

/// <summary>
/// �������� 2.1. ���������� � ��������� ������� 5 ������ ��������
/// ���������, �� ��������� ������� �� ������
/// ������� ������ ������, ���� ���� ������� ��� 4 � ����
/// </summary>
int main() {
    const int num_grades = 5;
    int grades[num_grades];
    int sum = 0;

    // �������� 5 ������
    std::cout << "Enter 5 grades: ";
    for (int i = 0; i < num_grades; ++i) {
        std::cin >> grades[i];
        sum += grades[i]; // ���� ������
    }

    // ���������� ���������� ����
    double average = static_cast<double>(sum) / num_grades;

    // ����������, �� ��������� �������
    if (average >= 4.0) {
        std::cout << "Student is allowed to take the exam. Average grade: " << average << std::endl;
    }
    else {
        std::cout << "Student is not allowed to take the exam. Average grade: " << average << std::endl;
    }

    return 0;
}
