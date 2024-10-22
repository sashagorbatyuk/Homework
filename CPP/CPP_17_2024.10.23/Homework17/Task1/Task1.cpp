#include <iostream>
using namespace std;

// Функція для знаходження найбільшого спільного дільника (НСД) за допомогою алгоритму Евкліда
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Клас для збереження та обробки дробів
class Fraction {
private:
    int numerator;
    int denominator;

    // Функція для спрощення дробу
    void simplify() {
        int gcd_value = gcd(numerator, denominator); // Знаходимо НСД
        numerator /= gcd_value;  // Ділимо чисельник на НСД
        denominator /= gcd_value; // Ділимо знаменник на НСД
        if (denominator < 0) { // Якщо знаменник негативний, переносимо знак у чисельник
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Конструктор за замовчуванням
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        simplify(); // Спрощуємо дріб при створенні
    }

    // Функція для введення значень
    void setValues(int num, int den) {
        numerator = num;
        denominator = den;
        simplify();
    }

    // Функція для виведення дробу
    void print() const {
        cout << numerator << "/" << denominator << endl; // Виведення у форматі чисельник/знаменник
    }

    // Оператор додавання
    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // Оператор віднімання
    Fraction operator-(const Fraction& other) const {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // Оператор множення
    Fraction operator*(const Fraction& other) const {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    // Оператор ділення
    Fraction operator/(const Fraction& other) const {
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Fraction(new_numerator, new_denominator);
    }

    // Оператор порівняння на рівність
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator && denominator == other.denominator); // Порівнюємо чисельники і знаменники
    }
};

int main() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction quotient = frac1 / frac2;

    // Виведення результатів
    cout << "Sum: "; sum.print();
    cout << "Difference: "; difference.print();
    cout << "Product: "; product.print();
    cout << "Quotient: "; quotient.print();

    return 0;
}