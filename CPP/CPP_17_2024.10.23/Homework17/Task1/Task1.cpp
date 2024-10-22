#include <iostream>
using namespace std;

// ������� ��� ����������� ���������� �������� ������� (���) �� ��������� ��������� ������
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ���� ��� ���������� �� ������� �����
class Fraction {
private:
    int numerator;
    int denominator;

    // ������� ��� ��������� �����
    void simplify() {
        int gcd_value = gcd(numerator, denominator); // ��������� ���
        numerator /= gcd_value;  // ĳ���� ��������� �� ���
        denominator /= gcd_value; // ĳ���� ��������� �� ���
        if (denominator < 0) { // ���� ��������� ����������, ���������� ���� � ���������
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // ����������� �� �������������
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        simplify(); // �������� ��� ��� ��������
    }

    // ������� ��� �������� �������
    void setValues(int num, int den) {
        numerator = num;
        denominator = den;
        simplify();
    }

    // ������� ��� ��������� �����
    void print() const {
        cout << numerator << "/" << denominator << endl; // ��������� � ������ ���������/���������
    }

    // �������� ���������
    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // �������� ��������
    Fraction operator-(const Fraction& other) const {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // �������� ��������
    Fraction operator*(const Fraction& other) const {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // �������� ������
    Fraction operator/(const Fraction& other) const {
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Fraction(new_numerator, new_denominator);
    }

    // �������� ��������� �� ������
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator && denominator == other.denominator); // ��������� ���������� � ����������
    }
};

int main() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction quotient = frac1 / frac2;

    // ��������� ����������
    cout << "Sum: "; sum.print();
    cout << "Difference: "; difference.print();
    cout << "Product: "; product.print();
    cout << "Quotient: "; quotient.print();

    return 0;
}