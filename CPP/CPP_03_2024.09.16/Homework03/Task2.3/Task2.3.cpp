#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2.3
/// Користувач вводить з клавіатури вартість одного ноутбука, їхню кількість і відсоток знижки.
/// Порахувати загальну суму замовлення.
/// </summary>

int main() {
    // Input: price of one laptop, quantity, and discount percentage
    double price_per_laptop, discount_percentage;
    int quantity;

    cout << "Enter the price of one laptop: ";
    cin >> price_per_laptop;

    cout << "Enter the quantity of laptops: ";
    cin >> quantity;

    cout << "Enter the discount percentage: ";
    cin >> discount_percentage;

    // Calculate total price without discount
    double total_price = price_per_laptop * quantity;

    // Calculate discount amount
    double discount = (total_price * discount_percentage) / 100.0;

    // Calculate final total price after applying the discount
    double final_price = total_price - discount;

    // Output the final total price
    cout << "The total order amount after discount is: " << final_price << endl;

    return 0;
}
