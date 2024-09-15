#include <iostream>

using namespace std;

/// <summary>
/// Завдання 1.1
/// Користувач вводить з клавіатури час у секундах, що минув з початку дня
/// Вивести на екран поточний час у годинах, хвилинах і секундах
/// Порахувати, скільки годин, хвилин і секунд залишилося до півночі
/// </summary>

int main() {
    // Input: time in seconds since the beginning of the day
    int seconds_since_midnight;
    cout << "Enter the number of seconds since the beginning of the day: ";
    cin >> seconds_since_midnight;

    // Calculate hours, minutes, and seconds
    int hours = seconds_since_midnight / 3600;
    int minutes = (seconds_since_midnight % 3600) / 60;
    int seconds = seconds_since_midnight % 60;

    // Output current time
    cout << "Current time is: " << hours << " hours, "
        << minutes << " minutes, and " << seconds << " seconds." << endl;

    // Calculate remaining time until midnight
    int remaining_seconds = 86400 - seconds_since_midnight;
    int remaining_hours = remaining_seconds / 3600;
    int remaining_minutes = (remaining_seconds % 3600) / 60;
    int remaining_sec = remaining_seconds % 60;

    // Output remaining time
    cout << "Time left until midnight: " << remaining_hours << " hours, "
        << remaining_minutes << " minutes, and " << remaining_sec << " seconds." << endl;

    return 0;
}
