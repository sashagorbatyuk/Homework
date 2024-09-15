#include <iostream>
#include <cmath>
using namespace std;

/// <summary>
/// Користувач вводить з клавіатури три сторони трикутника. Порахувати периметр трикутника та площу за формулою Герона
/// </summary>
int main() {
    double a, b, c;

    cout << "Enter the length of side a: ";
    cin >> a;

    cout << "Enter the length of side b: ";
    cin >> b;

    cout << "Enter the length of side c: ";
    cin >> c;

    // Calculate the perimeter
    double perimeter = a + b + c;

    // Calculate the semi-perimeter
    double s = perimeter / 2;

    // Calculate the area using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Output the results
    cout << "The perimeter of the triangle is: " << perimeter << endl;
    cout << "The area of the triangle is: " << area << endl;

    return 0;
}
