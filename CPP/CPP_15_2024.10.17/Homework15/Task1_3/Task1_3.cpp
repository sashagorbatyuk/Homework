#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/// <summary>
/// Завдання 3 Шифр Цезаря — один із найдавніших шифрів.Під час шифрування кожен символ замінюється іншим, віддаленим від нього в алфавіті на фіксоване число позицій.
/// Приклад
/// Шифрування з використанням ключа : 3
/// Оригінальний текст : Съешь же ещё этих мягких французских булок, да выпей чаю.
/// Шифрований текст : Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб.
/// Дано текстовий файл. Зашифрувати його, використовуючи шифр Цезаря.Результат записати в інший файл.
/// </summary>

// Функція для шифрування символу з використанням шифру Цезаря
char caesarCipher(char c, int key) {
    // Шифруємо лише літери
    if (isalpha(c)) {
        char base = islower(c) ? 'а' : 'А'; // Визначаємо базовий символ для літер кирилиці
        int alphabetSize = 32;
        return base + (c - base + key + alphabetSize) % alphabetSize;
    }
    return c; // Не шифруємо інші символи (пробіли, розділові знаки тощо)
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "encrypted.txt";
    int key = 3; // Ключ для шифрування Цезаря

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

    string line;
    while (getline(file, line)) {
        for (char& c : line) {
            // Зашифровуємо кожен символ рядка
            outFile << caesarCipher(c, key);
        }
        outFile << endl; // Переходимо на новий рядок після шифрування кожного рядка
    }

    // Закриваємо файли
    file.close();
    outFile.close();

    cout << "Text encrypted and written to " << outputFile << endl;

    return 0;
}