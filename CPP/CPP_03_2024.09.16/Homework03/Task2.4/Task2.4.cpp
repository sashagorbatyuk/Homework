#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2.4
/// Зарплата менеджера — 100$ + 5% від продажів. 
/// Користувач вводить з клавіатури загальну суму угод менеджера за місяць. 
/// Порахувати підсумкову зарплату менеджера.
/// </summary>
/// <returns></returns>

int main() {
    // Input: total sales amount for the manager
    double total_sales;
    cout << "Enter the total sales amount for the month: ";
    cin >> total_sales;

    // Base salary and commission rate
    const double base_salary = 100.0;
    const double commission_rate = 0.05;  // 5%

    // Calculate commission
    double commission = total_sales * commission_rate;

    // Calculate final salary
    double final_salary = base_salary + commission;

    // Output the final salary
    cout << "The final salary of the manager is: " << final_salary << " $" << endl;

    return 0;
}
