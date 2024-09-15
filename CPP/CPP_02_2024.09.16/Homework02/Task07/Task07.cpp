#include <iostream>
using namespace std;

/// <summary>
/// Користувач вводить з клавіатури вартість однієї книги, кількість книг та податок на додану вартість (ПДВ)
/// Порахувати підсумкову вартість покупки, включаючи податок.
/// </summary>
int main() {
    double bookPrice, vatRate;
    int quantity;

    cout << "Enter the price of one book: ";
    cin >> bookPrice;

    cout << "Enter the quantity of books: ";
    cin >> quantity;

    cout << "Enter the VAT rate (as a percentage): ";
    cin >> vatRate;

    // Calculate the total cost before tax
    double totalCostBeforeTax = bookPrice * quantity;

    // Calculate the VAT amount
    double vatAmount = (totalCostBeforeTax * vatRate) / 100.0;

    // Calculate the total cost including VAT
    double totalCostWithTax = totalCostBeforeTax + vatAmount;

    // Output the results
    cout << "The total cost of the purchase including VAT is: " << totalCostWithTax << " currency units" << endl;

    return 0;
}
