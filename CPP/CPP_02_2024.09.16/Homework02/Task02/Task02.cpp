#include <iostream>
using namespace std;

/// <summary>
/// Користувач вводить з клавіатури довжину та ширину прямокутника. Порахувати площу та периметр цього прямокутника
/// </summary>
int main() {
    double length, width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Calculate the area
    double area = length * width;

    // Calculate the perimeter
    double perimeter = 2 * (length + width);

    // Output the results
    cout << "The area of the rectangle is: " << area << endl;
    cout << "The perimeter of the rectangle is: " << perimeter << endl;

    return 0;
}
