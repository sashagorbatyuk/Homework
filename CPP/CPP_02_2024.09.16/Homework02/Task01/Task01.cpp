#include <iostream>

using namespace std;

/// <summary>
/// Завдання 1
/// Користувач вводить з клавіатури час у хвилинах, що минув з початку тижня.
/// Вивести на екран поточний день, годину, хвилини і секунди.Порахувати, скільки днів, годин, хвилин і секунд залишилося до кінця тижня.
/// </summary>
int main() {
    const int minutesInHour = 60;
    const int hoursInDay = 24;
    const int minutesInDay = hoursInDay * minutesInHour;
    const int daysInWeek = 7;
    const int minutesInWeek = daysInWeek * minutesInDay;

    int totalMinutes;
    cout << "Enter the number of minutes elapsed since the beginning of the week: ";
    cin >> totalMinutes;

    // Ensure totalMinutes is within one week's range
    totalMinutes %= minutesInWeek;

    int currentDay = totalMinutes / minutesInDay;
    int remainingMinutesAfterDays = totalMinutes % minutesInDay;
    int currentHour = remainingMinutesAfterDays / minutesInHour;
    int currentMinute = remainingMinutesAfterDays % minutesInHour;
    int currentSecond = 0; // assuming seconds are 0 as we don't have input for seconds

    cout << "Current time: " << endl;
    cout << "Day: " << currentDay << endl;
    cout << "Hour: " << currentHour << endl;
    cout << "Minute: " << currentMinute << endl;
    cout << "Second: " << currentSecond << endl;

    int minutesLeftInWeek = minutesInWeek - totalMinutes;
    int daysLeft = minutesLeftInWeek / minutesInDay;
    int remainingMinutesAfterDaysLeft = minutesLeftInWeek % minutesInDay;
    int hoursLeft = remainingMinutesAfterDaysLeft / minutesInHour;
    int minutesLeft = remainingMinutesAfterDaysLeft % minutesInHour;
    int secondsLeft = 0; // assuming seconds are 0 as we don't have input for seconds

    cout << "Time left until the end of the week: " << endl;
    cout << "Days: " << daysLeft << endl;
    cout << "Hours: " << hoursLeft << endl;
    cout << "Minutes: " << minutesLeft << endl;
    cout << "Seconds: " << secondsLeft << endl;

    return 0;
}
