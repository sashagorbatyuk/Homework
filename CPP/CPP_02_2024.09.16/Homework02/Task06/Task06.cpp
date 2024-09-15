#include <iostream>
#include <cmath>
using namespace std;

/// <summary>
/// Користувач вводить з клавіатури відстань між двома містами та швидкість автомобіля
/// Порахувати, скільки часу займе подорож, та скільки залишиться до кінця дня, якщо виїхати о 8:00 ранку
/// </summary>
int main() {
    double distance, speed;

    cout << "Enter the distance between the two cities (in km): ";
    cin >> distance;

    cout << "Enter the speed of the car (in km/h): ";
    cin >> speed;

    // Calculate travel time in hours
    double travelTime = distance / speed;

    // Calculate the end time of the trip
    double startTime = 8.0; // 8:00 AM
    double endTime = startTime + travelTime;

    // Check if the trip ends on the same day (before 24:00)
    if (endTime > 24.0) {
        cout << "The trip will end after midnight, on the next day." << endl;
    }
    else {
        // Calculate remaining time until the end of the day (24:00)
        double timeRemaining = 24.0 - endTime;

        // Extract hours and minutes
        int remainingHours = static_cast<int>(timeRemaining);
        int remainingMinutes = static_cast<int>((timeRemaining - remainingHours) * 60);

        cout << "The trip will take: " << floor(travelTime) << " hours and "
            << round((travelTime - floor(travelTime)) * 60) << " minutes." << endl;
        cout << "Time remaining until the end of the day: "
            << remainingHours << " hours and "
            << remainingMinutes << " minutes." << endl;
    }

    return 0;
}
