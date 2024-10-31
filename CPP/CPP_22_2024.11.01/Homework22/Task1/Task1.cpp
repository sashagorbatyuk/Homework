#include <iostream>
using namespace std;

// Клас Fraction для представлення дробів
class Fraction {
private:
    int numerator;   // Чисельник
    int denominator; // Знаменник

    // Метод для спрощення дробу
    void simplify() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }

    // Метод для знаходження найбільшого спільного дільника (НСД)
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    // Конструктор з параметрами
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    // Перевантаження оператора додавання
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Перевантаження оператора віднімання
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Перевантаження оператора множення
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Перевантаження оператора ділення
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    // Перевантаження оператора виводу
    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

int main() {
    try {
        Fraction f1(3, 4);
        Fraction f2(2, 5);

        cout << "f1 : " << f1 << endl;
        cout << "f2 : " << f2 << endl;

        cout << "f1 + f2 = " << (f1 + f2) << endl;
        cout << "f1 - f2 = " << (f1 - f2) << endl;
        cout << "f1 * f2 = " << (f1 * f2) << endl;
        cout << "f1 / f2 = " << (f1 / f2) << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
}