#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/// <summary>
/// Завдання 1. Дано два текстові файли. З'ясувати, чи збігаються їхні рядки. Якщо ні, то вивести рядок, що не збігається, з кожного файлу.
/// </summary>

// Функція для читання рядків з файлу
vector<string> readLines(const string& filename) {
    ifstream file(filename);
    vector<string> lines;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        cerr << "Failed to open file: " << filename << endl;
    }
    return lines;
}

int main() {
    string file1 = "file1.txt";
    string file2 = "file2.txt";

    // Читання рядків з обох файлів
    vector<string> lines1 = readLines(file1);
    vector<string> lines2 = readLines(file2);

    // Перевірка, чи однакова кількість рядків у файлах
    size_t maxLines = max(lines1.size(), lines2.size());

    bool areEqual = true;

    for (size_t i = 0; i < maxLines; i++) {
        string line1 = i < lines1.size() ? lines1[i] : "";
        string line2 = i < lines2.size() ? lines2[i] : "";

        if (line1 != line2) {
            areEqual = false;
            cout << "Line " << i + 1 << " does not match:\n";
            cout << "File 1: " << (line1.empty() ? "<empty>" : line1) << endl;
            cout << "File 2: " << (line2.empty() ? "<empty>" : line2) << endl;
        }
    }

    if (areEqual) {
        cout << "The lines in both files match!" << endl;
    }

    return 0;
}
