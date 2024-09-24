#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// Завдання 4. Написати функцію, що виводить на екран передану їй гральну карту.
/// </summary>
void displayCard(string rank, string suit) {
    cout << "*************" << endl;
    cout << "* " << rank << "        *" << endl;
    cout << "*           *" << endl;
    cout << "*     " << suit << "     *" << endl;
    cout << "*           *" << endl;
    cout << "*        " << rank << " *" << endl;
    cout << "*************" << endl;
}

int main() {
    string rank, suit;

    // Введення номіналу і масті карти
    cout << "Enter the card rank (2-10, J, Q, K, A): ";
    cin >> rank;
    cout << "Enter the card suit (hearts, diamonds, clubs, spades): ";
    cin >> suit;

    // Конвертуємо масть до символу
    if (suit == "hearts") {
        suit = "♥";
    }
    else if (suit == "diamonds") {
        suit = "♦";
    }
    else if (suit == "clubs") {
        suit = "♣";
    }
    else if (suit == "spades") {
        suit = "♠";
    }
    else {
        cout << "Invalid suit!" << endl;
        return 1;
    }

    // Виведення карти на екран
    displayCard(rank, suit);

    return 0;
}
