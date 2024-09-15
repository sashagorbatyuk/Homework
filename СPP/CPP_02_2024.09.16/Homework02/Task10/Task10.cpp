#include <iostream>
using namespace std;

/// <summary>
/// Користувач вводить з клавіатури потужність електроприладу в ватах та кількість годин його роботи за добу
/// Порахувати, скільки кіловат-годин буде спожито за день та за місяць.
/// </summary>
int main() {
    double powerWatts, hoursPerDay;
    const int daysPerMonth = 30; // Assuming an average month has 30 days

    cout << "Enter the power consumption of the device in watts: ";
    cin >> powerWatts;

    cout << "Enter the number of hours the device operates per day: ";
    cin >> hoursPerDay;

    // Calculate energy consumption per day in kilowatt-hours
    double energyPerDayKWh = (powerWatts / 1000.0) * hoursPerDay;

    // Calculate energy consumption per month in kilowatt-hours
    double energyPerMonthKWh = energyPerDayKWh * daysPerMonth;

    // Output the results
    cout << "The energy consumption per day is: " << energyPerDayKWh << " kWh" << endl;
    cout << "The energy consumption per month is: " << energyPerMonthKWh << " kWh" << endl;

    return 0;
}
