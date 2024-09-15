#include <iostream>

#include <cmath>

using namespace std;

/// <summary>
/// Завдання 1.2
/// Користувач вводить з клавіатури діаметр окружності. Порахувати площу і периметр окружності.
/// </summary>
int main() {
    // Input: diameter of the circle
    double diameter;
    cout << "Enter the diameter of the circle: ";
    cin >> diameter;

    // Calculate the radius
    double radius = diameter / 2.0;

    // Constants
    const double PI = 3.141592653589793;

    // Calculate the area and perimeter (circumference) of the circle
    double area = PI * pow(radius, 2);
    double perimeter = 2 * PI * radius;

    // Output the results
    cout << "Area of the circle: " << area << endl;
    cout << "Perimeter (circumference) of the circle: " << perimeter << endl;

    return 0;
}
