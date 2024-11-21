#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

// Базовий клас для роботи з файлами
class FileHandler {
public:
    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Error: Cannot open the file!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    virtual ~FileHandler() {}
};

// Клас-нащадок: виводить вміст у вигляді ASCII-кодів
class ASCIIFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Error: Cannot open the file!" << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            cout << static_cast<int>(ch) << " ";
        }
        cout << endl;
        file.close();
    }
};

// Клас-нащадок: виводить вміст у двійковому вигляді
class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Error: Cannot open the file!" << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            cout << bitset<8>(ch) << " ";
        }
        cout << endl;
        file.close();
    }
};

// Головна функція для демонстрації
int main() {
    // Шлях до тестового файлу
    const char* filePath = "example.txt";

    // Використання базового класу
    FileHandler baseHandler;
    cout << "Base handler output:" << endl;
    baseHandler.Display(filePath);

    // Використання ASCII-класу
    ASCIIFileHandler asciiHandler;
    cout << "\nASCII handler output:" << endl;
    asciiHandler.Display(filePath);

    // Використання двійкового класу
    BinaryFileHandler binaryHandler;
    cout << "\nBinary handler output:" << endl;
    binaryHandler.Display(filePath);

    return 0;
}