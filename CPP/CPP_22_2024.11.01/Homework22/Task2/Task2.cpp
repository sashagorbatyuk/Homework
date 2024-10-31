#include <iostream>
using namespace std;

// Клас Complex для представлення комплексних чисел
class Complex {
private:
    double real;   // Дійсна частина
    double imag;   // Уявна частина

public:
    // Конструктор з параметрами
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Перевантаження оператора додавання
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Перевантаження оператора віднімання
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Перевантаження оператора множення
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // Перевантаження оператора ділення
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }

    // Перевантаження оператора виводу
    friend ostream& operator<<(ostream& os, const Complex& comp) {
        os << comp.real << (comp.imag >= 0 ? " + " : " - ") << abs(comp.imag) << "i";
        return os;
    }
};

int main() {
    Complex c1(4.0, 3.0); // Перше комплексне число
    Complex c2(2.0, -1.0); // Друге комплексне число

    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
    cout << "c1 / c2 = " << (c1 / c2) << endl;
    cout << "c1 = " << c1 << endl; 
    cout << "c2 = " << c2 << endl;
}