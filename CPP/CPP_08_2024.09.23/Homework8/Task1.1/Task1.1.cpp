#include <iostream>
#include <thread> // для використання sleep_for функції
#include <chrono> // щоб відложувати друкування

using namespace std;

void printHorizontalLine(char symbol, int length, int delay);
void printVerticalLine(char symbol, int length, int delay);
int selectSpeed();

/// <summary>
/// Написати програму, яка виводить на екран лінію заданим символом, вертикальну або горизонтальну, 
/// причому лінія може виводитися швидко, нормально і повільно.Спілкування з користувачем організувати через меню
/// </summary>
int main() {
    int choice;
    char symbol;
    int length;
    int delay;

    do {
        cout << "Choose an action:\n";
        cout << "1. Print horizontal line\n";
        cout << "2. Print vertical line\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice != 0) {
            cout << "Enter the symbol for the line: ";
            cin >> symbol;
            cout << "Enter the length of the line: ";
            cin >> length;

            delay = selectSpeed();
        }

        switch (choice) {
        case 1:
            printHorizontalLine(symbol, length, delay);
            break;
        case 2:
            printVerticalLine(symbol, length, delay);
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}

/// <summary>
/// Функція що виводить горизонтальну лінію
/// </summary>
void printHorizontalLine(char symbol, int length, int delay) {
    for (int i = 0; i < length; ++i) {
        cout << symbol;
        this_thread::sleep_for(chrono::milliseconds(delay)); // відложування
    }
    cout << endl;
}

/// <summary>
/// Функція що виводить вертикальну лінію
/// </summary>
void printVerticalLine(char symbol, int length, int delay) {
    for (int i = 0; i < length; ++i) {
        cout << symbol << endl;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

/// <summary>
/// 
/// </summary>
int selectSpeed() {
    int speedChoice;
    cout << "Choose speed:\n";
    cout << "1. Fast\n";
    cout << "2. Normal\n";
    cout << "3. Slow\n";
    cout << "Your choice: ";
    cin >> speedChoice;

    switch (speedChoice) {
    case 1: return 50;    // 50 ms відлік для швидкого друку
    case 2: return 200;   // 200 ms відлік для нормального друку
    case 3: return 500;   // 500 ms відлік для повільного друку
    default:
        cout << "Invalid choice, normal speed selected.\n";
        return 200;
    }
}