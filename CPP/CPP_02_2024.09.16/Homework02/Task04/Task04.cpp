#include <iostream>
using namespace std;

/// <summary>
/// Користувач вводить з клавіатури масу одного товару, їхню кількість і вартість за одиницю
/// Порахувати загальну масу замовлення та його загальну вартість.
/// </summary>
int main() {
    double itemMass, itemCost;
    int quantity;

    cout << "Enter the mass of one item (in kg): ";
    cin >> itemMass;

    cout << "Enter the quantity of items: ";
    cin >> quantity;

    cout << "Enter the cost per item (in currency units): ";
    cin >> itemCost;

    // Calculate the total mass
    double totalMass = itemMass * quantity;

    // Calculate the total cost
    double totalCost = itemCost * quantity;

    // Output the results
    cout << "The total mass of the order is: " << totalMass << " kg" << endl;
    cout << "The total cost of the order is: " << totalCost << " currency units" << endl;

    return 0;
}
