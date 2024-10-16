#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;


/// <summary>
/// Завдання 2
/// Дано текстовий файл.Необхідно створити новий файл і записати в нього таку статистику за вихідним файлом :
/// Кількість символів;
/// Кількість рядків;
/// Кількість голосних букв;
/// Кількість приголосних букв;
/// Кількість цифр.
/// </summary>

// Функція для перевірки, чи є символ голосною буквою
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

// Функція для перевірки, чи є символ приголосною буквою
bool isConsonant(char c) {
    c = tolower(c);
    return isalpha(c) && !isVowel(c);
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "statistics.txt";

    ifstream file(inputFile);
    ofstream outFile(outputFile);

    if (!file.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    if (!outFile.is_open()) {
        cerr << "Failed to open output file." << endl;
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    string line;
    while (getline(file, line)) {
        lineCount++; // Рахуємо рядки
        for (char c : line) {
            if (isalpha(c)) {
                // Рахуємо голосні та приголосні букви
                if (isVowel(c)) {
                    vowelCount++;
                }
                else if (isConsonant(c)) {
                    consonantCount++;
                }
            }
            else if (isdigit(c)) {
                digitCount++; // Рахуємо цифри
            }
            charCount++; // Рахуємо всі символи
        }
        charCount++; // Додаємо символ переходу на новий рядок
    }

    // Записуємо статистику в новий файл
    outFile << "Number of characters: " << charCount << endl;
    outFile << "Number of lines: " << lineCount << endl;
    outFile << "Number of vowels: " << vowelCount << endl;
    outFile << "Number of consonants: " << consonantCount << endl;
    outFile << "Number of digits: " << digitCount << endl;

    // Закриття файлів
    file.close();
    outFile.close();

    cout << "Statistics written to " << outputFile << endl;

    return 0;
}
