#include <iostream>
#include <stdexcept>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            throw invalid_argument("Invalid month");
        }
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {
        if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y)) {
            throw invalid_argument("Invalid date");
        }
    }

    // Функція для збільшення дня на 1
    void incrementDay() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    // Перевантаження оператора ++ (префіксний)
    Date& operator++() {
        incrementDay();
        return *this;
    }

    // Перевантаження оператора -- (префіксний)
    Date& operator--() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = daysInMonth(month, year);
        }
        return *this;
    }

    // Перевантаження оператора !=
    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    // Перевантаження оператора ==
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Перевантаження оператора >
    bool operator>(const Date& other) const {
        return year > other.year || (year == other.year && (month > other.month || (month == other.month && day > other.day)));
    }

    // Перевантаження оператора <
    bool operator<(const Date& other) const {
        return !(*this >= other);
    }

    // Перевантаження оператора >=
    bool operator>=(const Date& other) const {
        return *this > other || *this == other;
    }

    // Перевантаження оператора <=
    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    // Перевантаження оператора >>
    friend istream& operator>>(istream& in, Date& date) {
        char delimiter;
        in >> date.day >> delimiter >> date.month >> delimiter >> date.year;
        if (in.fail() || date.month < 1 || date.month > 12 || date.day < 1 || date.day > date.daysInMonth(date.month, date.year)) {
            throw invalid_argument("Invalid date input");
        }
        return in;
    }

    // Перевантаження оператора <<
    friend ostream& operator<<(ostream& out, const Date& date) {
        out << date.day << '/' << date.month << '/' << date.year;
        return out;
    }

    // Перевантаження оператора =
    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    // Перевантаження оператора +=
    Date& operator+=(int days) {
        for (int i = 0; i < days; i++) {
            incrementDay();
        }
        return *this;
    }

    // Перевантаження оператора -=
    Date& operator-=(int days) {
        for (int i = 0; i < days; i++) {
            --(*this);
        }
        return *this;
    }

    // Перевантаження оператора ()
    void operator()(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y)) {
            throw invalid_argument("Invalid date");
        }
    }
};

int main() {
    try {
        Date date(03, 11, 2024);
        cout << "Original date: " << date << endl;
        ++date; // Перехід на 4 листопада 2024
        cout << "After increment: " << date << endl;

        date += 5; // Додавання 5 днів
        cout << "After adding 5 days: " << date << endl;

        date -= 10; // Віднімання 10 днів
        cout << "After subtracting 10 days: " << date << endl;

        cout << "Enter a date (dd/mm/yyyy): ";
        cin >> date; // Введення дати з консолі
        cout << "Input date: " << date << endl;

    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}