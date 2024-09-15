#include <iostream>
using namespace std;

/// <summary>
/// Користувач вводить з клавіатури ціну за кілограм яблук та кількість кілограмів, яку хоче купити
/// Порахувати загальну вартість покупки, враховуючи знижку 10% на кожен кілограм, якщо загальна вага покупки перевищує 5 кг.
/// </summary>
int main() {
    double pricePerKg, weight;

    cout << "Enter the price per kilogram of apples: ";
    cin >> pricePerKg;

    cout << "Enter the number of kilograms you want to buy: ";
    cin >> weight;

    // Check if the total weight exceeds 5 kg for the discount
    double totalCost;
    if (weight > 5) {
        double discountPricePerKg = pricePerKg * 0.90; // 10% discount
        totalCost = discountPricePerKg * weight;
    }
    else {
        totalCost = pricePerKg * weight;
    }

    // Output the total cost
    cout << "The total cost of the purchase is: " << totalCost << " currency units" << endl;

    return 0;
}
