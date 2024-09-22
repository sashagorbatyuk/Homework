#include <iostream>
using namespace std;

/// <summary>
///  ористувач вводить прибуток ф≥рми за р≥к (12 м≥с€ц≥в).ѕот≥м користувач вводить д≥апазон(наприклад, 3 ≥ 6 Ч пошук м≥ж трет≥м ≥ шостим м≥с€цем)
/// Ќеобх≥дно визначити м≥с€ць, у €кому прибуток був максимальним, ≥ м≥с€ць, у €кому прибуток був м≥н≥мальним, з урахуванн€м обраного д≥апазону
/// </summary>
int main() {
    const int MONTHS = 12;
    double profit[MONTHS];
    int startMonth, endMonth;

    // ¬веденн€ прибутку за 12 м≥с€ц≥в
    cout << "Enter the profit for each of the 12 months:\n";
    for (int i = 0; i < MONTHS; ++i) {
        cout << "Month " << i + 1 << ": ";
        cin >> profit[i];
    }

    // ¬веденн€ д≥апазону м≥с€ц≥в
    cout << "\nEnter the start and end month for the search (1-12): ";
    cin >> startMonth >> endMonth;

    // ѕерев≥рка на правильн≥сть д≥апазону
    if (startMonth < 1 || endMonth > 12 || startMonth > endMonth) {
        cout << "Invalid range of months!" << endl;
        return 1; // «авершенн€ програми з кодом помилки
    }

    // ≤н≥ц≥ал≥зац≥€ м≥н≥мального та максимального значень
    int minMonth = startMonth - 1;
    int maxMonth = startMonth - 1;
    double minProfit = profit[minMonth];
    double maxProfit = profit[maxMonth];

    // ѕошук м≥н≥мального та максимального прибутку в обраному д≥апазон≥
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

    // ¬иведенн€ результат≥в
    cout << "\nIn the range from month " << startMonth << " to month " << endMonth << ":\n";
    cout << "Month with minimum profit: " << minMonth + 1 << " (Profit: " << minProfit << ")\n";
    cout << "Month with maximum profit: " << maxMonth + 1 << " (Profit: " << maxProfit << ")\n";

    return 0;
}