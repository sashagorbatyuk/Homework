#include <iostream>

using namespace std;

/// <summary>
/// Завдання 3. Число називається досконалим, якщо сума всіх його дільників дорівнює йому самому. Напишіть функцію пошуку таких чисел у введеному інтервалі.
/// </summary>
bool isPerfect(int num) {
    int sum = 0;

    // Знаходимо всі дільники числа і додаємо їх
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Якщо сума дільників дорівнює самому числу, то це досконале число
    return sum == num;
}

// Функція для пошуку всіх досконалих чисел у діапазоні
void findPerfectNumbersInRange(int start, int end) {
    cout << "Perfect numbers in the range from " << start << " to " << end << " are: " << endl;

    bool found = false;
    for (int i = start; i <= end; ++i) {
        if (isPerfect(i)) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No perfect numbers found in this range." << endl;
    }
}

int main() {
    int start, end;

    // Введення інтервалу
    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;

    // Пошук досконалих чисел у діапазоні
    findPerfectNumbersInRange(start, end);

    return 0;
}
