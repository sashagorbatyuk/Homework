#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Генерація випадкового чотирицифрового числа
string generateNumber() {
    string num;
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < 4; ++i) {
        num += '0' + rand() % 10; // Додаємо випадкову цифру
    }
    return num;
}

// Функція для підрахунку корів і биків (поміняно місцями)
void countBullsAndCows(const string& secret, const string& guess, int& cows, int& bulls) {
    bulls = 0;
    cows = 0;
    bool used[4] = { false }; // для позначення використаних цифр

    // Підрахунок биків (правильні цифри на правильних місцях)
    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            cows++;
            used[i] = true; // Позначаємо, що цифра використана
        }
    }

    // Підрахунок корів (правильні цифри на неправильних місцях)
    for (int i = 0; i < 4; ++i) {
        if (secret[i] != guess[i]) {
            for (int j = 0; j < 4; ++j) {
                if (!used[j] && guess[i] == secret[j]) {
                    bulls++;
                    used[j] = true; // Позначаємо, що цифра використана
                    break;
                }
            }
        }
    }
}

// Рекурсивна функція для гри "Бики та корови"
void playGame(const string& secret, int& attempts) {
    string guess;
    int bulls = 0, cows = 0;

    // Отримуємо здогад користувача
    cout << "Enter your guess (4 digits): ";
    cin >> guess;

    // Перевіряємо здогад
    countBullsAndCows(secret, guess, cows, bulls);
    attempts++;

    // Якщо гравець вгадав
    if (cows == 4) {
        cout << "Congratulations! You've guessed the number!" << endl;
        cout << "Total attempts: " << attempts << endl;
    }
    else {
        // Виводимо кількість биків і корів
        cout << "Cows: " << cows << ", Bulls: " << bulls << endl;
        // Рекурсивно викликаємо гру знову
        playGame(secret, attempts);
    }
}

int main() {
    // Генеруємо випадкове число
    string secret = generateNumber();

    // Для тестування можна вивести загадане число
    cout << "(Secret number for testing: " << secret << ")\n";

    int attempts = 0;

    // Запуск гри
    playGame(secret, attempts);

    return 0;
}
