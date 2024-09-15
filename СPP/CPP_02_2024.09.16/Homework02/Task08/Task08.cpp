#include <iostream>
using namespace std;

/// <summary>
/// ���������� ������� � ��������� ����� ���� � �����, �� ��������������� �� �����, �� ������� ������ �������� ����� ����. ���������� �������� ������� ���� �� �����.
/// </summary>
int main() {
    double waterVolumeLiters, costPerCubicMeter;

    cout << "Enter the volume of water used in liters per month: ";
    cin >> waterVolumeLiters;

    cout << "Enter the cost of one cubic meter of water: ";
    cin >> costPerCubicMeter;

    // Convert liters to cubic meters (1 cubic meter = 1000 liters)
    double waterVolumeCubicMeters = waterVolumeLiters / 1000.0;

    // Calculate the total cost
    double totalCost = waterVolumeCubicMeters * costPerCubicMeter;

    // Output the results
    cout << "The total cost of water for the month is: " << totalCost << " currency units" << endl;

    return 0;
}
