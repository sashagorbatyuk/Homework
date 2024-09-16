#include <iostream>

using namespace std;

/// <summary>
/// Завдання 3. Вася працює програмістом та отримує 50$ за кожні 100 рядків коду.
/// За кожне третє запізнення Васю штрафують на 20$.Реалізувати меню :
/// - користувач вводить бажаний дохід Васі та кількість запізнень, порахувати, скільки рядків коду йому треба написати;
/// - користувач вводить кількість рядків коду, написані Васею та бажаний обсяг зарплати.
/// Порахувати, скільки разів Вася може запізнитися;
/// - користувач вводить кількість рядків коду та кількість запізнень, визначити, скільки грошей заплатять Васі і чи заплатять взагалі.
/// </summary>
/// <returns></returns>

int main() {
    int choice;
    const double pay_per_100_lines = 50.0;
    const double penalty_per_third_lateness = 20.0;

    do {
        // Display menu
        cout << "\n--- Menu ---\n";
        cout << "1. Calculate how many lines Vasya needs to write for a desired income with a given number of lateness.\n";
        cout << "2. Calculate how many times Vasya can be late for a given number of lines and desired income.\n";
        cout << "3. Calculate how much Vasya will earn based on lines written and number of lateness.\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Option 1: Calculate how many lines Vasya needs to write for a desired income
        if (choice == 1) {
            double desired_income;
            int lateness;
            cout << "Enter desired income (in $): ";
            cin >> desired_income;
            cout << "Enter the number of lateness: ";
            cin >> lateness;

            // Calculate total penalty
            int total_penalty = (lateness / 3) * penalty_per_third_lateness;

            // Calculate required income without penalty
            double required_income = desired_income + total_penalty;

            // Calculate lines needed
            int lines_needed = static_cast<int>((required_income / pay_per_100_lines) * 100);
            cout << "Vasya needs to write " << lines_needed << " lines of code to earn " << desired_income << " after " << lateness << " lateness." << endl;

        }
        // Option 2: Calculate how many times Vasya can be late for a given number of lines and desired income
        else if (choice == 2) {
            int lines_written;
            double desired_income;
            cout << "Enter number of lines written: ";
            cin >> lines_written;
            cout << "Enter desired income (in $): ";
            cin >> desired_income;

            // Calculate income based on lines written
            double earned_income = (lines_written / 100.0) * pay_per_100_lines;

            // Check if desired income is achievable
            if (earned_income < desired_income) {
                cout << "Vasya cannot achieve the desired income with the given number of lines." << endl;
            }
            else {
                // Calculate how many lateness are allowed
                int max_lateness = static_cast<int>((earned_income - desired_income) / penalty_per_third_lateness) * 3;
                cout << "Vasya can be late up to " << max_lateness << " times to still achieve the desired income." << endl;
            }

        }
        // Option 3: Calculate how much Vasya will earn based on lines written and number of lateness
        else if (choice == 3) {
            int lines_written, lateness;
            cout << "Enter number of lines written: ";
            cin >> lines_written;
            cout << "Enter number of lateness: ";
            cin >> lateness;

            // Calculate earnings
            double earned_income = (lines_written / 100.0) * pay_per_100_lines;

            // Calculate total penalty
            int total_penalty = (lateness / 3) * penalty_per_third_lateness;

            // Final income
            double final_income = earned_income - total_penalty;

            if (final_income > 0) {
                cout << "Vasya will earn " << final_income << " $ after penalties." << endl;
            }
            else {
                cout << "Vasya will not earn any money after penalties." << endl;
            }

        }
        else if (choice == 4) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
