#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/// <summary>
/// �������� 3 ���� ������ � ���� �� ���������� �����.ϳ� ��� ���������� ����� ������ ���������� �����, ��������� �� ����� � ������ �� ��������� ����� �������.
/// �������
/// ���������� � ������������� ����� : 3
/// ����������� ����� : ����� �� ��� ���� ������ ����������� �����, �� ����� ���.
/// ���������� ����� : ����� �� ��� ���� ����� ����������� �����, �� ����� ���.
/// ���� ��������� ����. ����������� ����, �������������� ���� ������.��������� �������� � ����� ����.
/// </summary>

// ������� ��� ���������� ������� � ������������� ����� ������
char caesarCipher(char c, int key) {
    // ������� ���� �����
    if (isalpha(c)) {
        char base = islower(c) ? '�' : '�'; // ��������� ������� ������ ��� ���� ��������
        int alphabetSize = 32;
        return base + (c - base + key + alphabetSize) % alphabetSize;
    }
    return c; // �� ������� ���� ������� (������, ������� ����� ����)
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "encrypted.txt";
    int key = 3; // ���� ��� ���������� ������

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
            // ����������� ����� ������ �����
            outFile << caesarCipher(c, key);
        }
        outFile << endl; // ���������� �� ����� ����� ���� ���������� ������� �����
    }

    // ��������� �����
    file.close();
    outFile.close();

    cout << "Text encrypted and written to " << outputFile << endl;

    return 0;
}