#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

// ������� ���� ��� ������ � �������
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

// ����-�������: �������� ���� � ������ ASCII-����
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

// ����-�������: �������� ���� � ��������� ������
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

// ������� ������� ��� ������������
int main() {
    // ���� �� ��������� �����
    const char* filePath = "example.txt";

    // ������������ �������� �����
    FileHandler baseHandler;
    cout << "Base handler output:" << endl;
    baseHandler.Display(filePath);

    // ������������ ASCII-�����
    ASCIIFileHandler asciiHandler;
    cout << "\nASCII handler output:" << endl;
    asciiHandler.Display(filePath);

    // ������������ ��������� �����
    BinaryFileHandler binaryHandler;
    cout << "\nBinary handler output:" << endl;
    binaryHandler.Display(filePath);

    return 0;
}