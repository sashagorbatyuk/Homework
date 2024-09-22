#include <iostream>
#include <cstdlib>  // для функції rand()
#include <ctime>    // для функції time() для генерації випадкових чисел
#include <iomanip>  // для налаштування форматування виводу

using namespace std;

// Функція для кидка кубиків
int rollDice() {
    return rand() % 6 + 1; // Випадкове число від 1 до 6
}

// Функція для виводу результату кидка
void printDice(int playerRoll1, int playerRoll2, int computerRoll1, int computerRoll2) {
    cout << "+--------------------------+\n";
    cout << "| Player roll:   " << playerRoll1 << " + " << playerRoll2 << " = " << playerRoll1 + playerRoll2 << " |\n";
    cout << "| Computer roll: " << computerRoll1 << " + " << computerRoll2 << " = " << computerRoll1 + computerRoll2 << " |\n";
    cout << "+--------------------------+\n";
}

// Функція для гри
void playGame() {
    int playerTotal = 0;
    int computerTotal = 0;

    cout << "=============================\n";
    cout << "      Welcome to Dice Game!   \n";
    cout << "=============================\n\n";

    for (int round = 1; round <= 3; ++round) {
        cout << "----- Round " << round << " -----\n";

        // Кидки гравця
        int playerRoll1 = rollDice();
        int playerRoll2 = rollDice();
        int playerSum = playerRoll1 + playerRoll2;
        playerTotal += playerSum;

        // Кидки комп'ютера
        int computerRoll1 = rollDice();
        int computerRoll2 = rollDice();
        int computerSum = computerRoll1 + computerRoll2;
        computerTotal += computerSum;

        // Виведення результатів
        printDice(playerRoll1, playerRoll2, computerRoll1, computerRoll2);

        cout << "Current total: Player = " << playerTotal << ", Computer = " << computerTotal << "\n\n";
    }

    // Визначення переможця
    cout << "Final total: Player = " << playerTotal << ", Computer = " << computerTotal << "\n";

    if (playerTotal > computerTotal) {
        cout << "\n*** Player wins! ***\n";
    }
    else if (playerTotal < computerTotal) {
        cout << "\n*** Computer wins! ***\n";
    }
    else {
        cout << "\n*** It's a tie! ***\n";
    }

    cout << "=============================\n";
    cout << "        Game Over!            \n";
    cout << "=============================\n";
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Ініціалізація генератора випадкових чисел

    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << "\n";
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
