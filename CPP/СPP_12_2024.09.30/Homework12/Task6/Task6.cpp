#include <iostream>
using namespace std;

/// <summary>
/// Шаблон для піднесення до степеня: Реалізуйте шаблон функції, що підносить число до цілого степеня. Не використовуйте рекурсію. Перевірте для цілих і дійсних чисел.
/// </summary>

template <typename T>
T power(T base, int exponent) {
    T result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    // Перевірка для цілих чисел
    int baseInt = 2;
    int expInt = 5;
    int resultInt = power(baseInt, expInt);
    cout << baseInt << "^" << expInt << " = " << resultInt << endl;

    // Перевірка для дійсних чисел
    double baseDouble = 1.5;
    int expDouble = 3;
    double resultDouble = power(baseDouble, expDouble);
    cout << baseDouble << "^" << expDouble << " = " << resultDouble << endl;

    return 0;
}
