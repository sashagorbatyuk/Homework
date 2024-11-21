#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Абстрактний базовий клас
class Equation {
public:
    virtual void Solve() = 0; // Чиста віртуальна функція для обчислення коренів
    virtual ~Equation() {}    // Віртуальний деструктор
};

// Клас для лінійних рівнянь
class LinearEquation : public Equation {
private:
    double a, b; // a * x + b = 0
public:
    LinearEquation(double coeffA, double coeffB) : a(coeffA), b(coeffB) {}

    void Solve() override {
        if (a == 0) {
            if (b == 0) {
                cout << "Infinite solutions (identity equation)." << endl;
            }
            else {
                cout << "No solution (inconsistent equation)." << endl;
            }
        }
        else {
            double x = -b / a;
            cout << "Solution: x = " << x << endl;
        }
    }
};

// Клас для квадратних рівнянь
class QuadraticEquation : public Equation {
private:
    double a, b, c; // a * x^2 + b * x + c = 0
public:
    QuadraticEquation(double coeffA, double coeffB, double coeffC)
        : a(coeffA), b(coeffB), c(coeffC) {}

    void Solve() override {
        if (a == 0) {
            // Якщо a = 0, рівняння стає лінійним
            LinearEquation linear(b, c);
            linear.Solve();
            return;
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Two real solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "One real solution: x = " << x << endl;
        }
        else {
            double realPart = -b / (2 * a);
            double imagPart = sqrt(-discriminant) / (2 * a);
            cout << "Two complex solutions: x1 = " << realPart << " + " << imagPart << "i"
                << ", x2 = " << realPart << " - " << imagPart << "i" << endl;
        }
    }
};

// Головна функція
int main() {
    cout << "Linear Equation Example: 2x + 4 = 0" << endl;
    LinearEquation linear(2, 4);
    linear.Solve();

    cout << "\nQuadratic Equation Example: x^2 - 5x + 6 = 0" << endl;
    QuadraticEquation quadratic(1, -5, 6);
    quadratic.Solve();

    cout << "\nQuadratic Equation with Complex Roots: x^2 + x + 1 = 0" << endl;
    QuadraticEquation complexQuadratic(1, 1, 1);
    complexQuadratic.Solve();

    return 0;
}