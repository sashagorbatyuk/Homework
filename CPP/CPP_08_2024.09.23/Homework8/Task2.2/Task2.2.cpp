#include <iostream>
using namespace std;

/// <summary>
/// ���������� ������� �������� ����� �� �� (12 ������).���� ���������� ������� �������(���������, 3 � 6 � ����� �� ����� � ������ ������)
/// ��������� ��������� �����, � ����� �������� ��� ������������, � �����, � ����� �������� ��� ���������, � ����������� �������� ��������
/// </summary>
int main() {
    const int MONTHS = 12;
    double profit[MONTHS];
    int startMonth, endMonth;

    // �������� �������� �� 12 ������
    cout << "Enter the profit for each of the 12 months:\n";
    for (int i = 0; i < MONTHS; ++i) {
        cout << "Month " << i + 1 << ": ";
        cin >> profit[i];
    }

    // �������� �������� ������
    cout << "\nEnter the start and end month for the search (1-12): ";
    cin >> startMonth >> endMonth;

    // �������� �� ����������� ��������
    if (startMonth < 1 || endMonth > 12 || startMonth > endMonth) {
        cout << "Invalid range of months!" << endl;
        return 1; // ���������� �������� � ����� �������
    }

    // ����������� ���������� �� ������������� �������
    int minMonth = startMonth - 1;
    int maxMonth = startMonth - 1;
    double minProfit = profit[minMonth];
    double maxProfit = profit[maxMonth];

    // ����� ���������� �� ������������� �������� � �������� �������
    for (int i = startMonth - 1; i < endMonth; ++i) {
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonth = i;
        }
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonth = i;
        }
    }

    // ��������� ����������
    cout << "\nIn the range from month " << startMonth << " to month " << endMonth << ":\n";
    cout << "Month with minimum profit: " << minMonth + 1 << " (Profit: " << minProfit << ")\n";
    cout << "Month with maximum profit: " << maxMonth + 1 << " (Profit: " << maxProfit << ")\n";

    return 0;
}