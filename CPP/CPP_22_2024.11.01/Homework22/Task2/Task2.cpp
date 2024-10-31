#include <iostream>
using namespace std;

// ���� Complex ��� ������������� ����������� �����
class Complex {
private:
    double real;   // ĳ���� �������
    double imag;   // ����� �������

public:
    // ����������� � �����������
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // �������������� ��������� ���������
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // �������������� ��������� ��������
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // �������������� ��������� ��������
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // �������������� ��������� ������
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }

    // �������������� ��������� ������
    friend ostream& operator<<(ostream& os, const Complex& comp) {
        os << comp.real << (comp.imag >= 0 ? " + " : " - ") << abs(comp.imag) << "i";
        return os;
    }
};

int main() {
    Complex c1(4.0, 3.0); // ����� ���������� �����
    Complex c2(2.0, -1.0); // ����� ���������� �����

    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
    cout << "c1 / c2 = " << (c1 / c2) << endl;
    cout << "c1 = " << c1 << endl; 
    cout << "c2 = " << c2 << endl;
}