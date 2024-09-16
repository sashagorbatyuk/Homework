#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2. Написати програму підрахунку вартості розмови для різних мобільних операторів. 
/// Користувач вводить вартість розмови і вибирає, з якого на який оператор він дзвонить. 
/// Вивести вартість на екран.
/// </summary>
int main() {
    // Input: cost per minute of the conversation
    double cost_per_minute;
    int duration;
    int from_operator, to_operator;

    // User inputs the cost per minute and call duration
    cout << "Enter the cost per minute: ";
    cin >> cost_per_minute;

    cout << "Enter the duration of the call in minutes: ";
    cin >> duration;

    // Display the list of operators
    cout << "Choose the 'from' operator (1 - Operator A, 2 - Operator B, 3 - Operator C): ";
    cin >> from_operator;

    cout << "Choose the 'to' operator (1 - Operator A, 2 - Operator B, 3 - Operator C): ";
    cin >> to_operator;

    // Calculate cost
    double total_cost = 0.0;

    // Different rates based on the combination of operators (example rates)
    if (from_operator == 1 && to_operator == 1) {
        total_cost = cost_per_minute * duration * 1.0; // Same operator
    }
    else if (from_operator == 1 && to_operator == 2) {
        total_cost = cost_per_minute * duration * 1.2; // Different operators
    }
    else if (from_operator == 1 && to_operator == 3) {
        total_cost = cost_per_minute * duration * 1.3; // Different operators
    }
    else if (from_operator == 2 && to_operator == 1) {
        total_cost = cost_per_minute * duration * 1.2;
    }
    else if (from_operator == 2 && to_operator == 2) {
        total_cost = cost_per_minute * duration * 1.0;
    }
    else if (from_operator == 2 && to_operator == 3) {
        total_cost = cost_per_minute * duration * 1.4;
    }
    else if (from_operator == 3 && to_operator == 1) {
        total_cost = cost_per_minute * duration * 1.3;
    }
    else if (from_operator == 3 && to_operator == 2) {
        total_cost = cost_per_minute * duration * 1.4;
    }
    else if (from_operator == 3 && to_operator == 3) {
        total_cost = cost_per_minute * duration * 1.0;
    }

    // Output the total cost
    cout << "The total cost of the call is: " << total_cost << " $" << endl;

    return 0;
}
