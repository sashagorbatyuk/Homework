#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;


/// <summary>
/// �������� 2
/// ���� ��������� ����.��������� �������� ����� ���� � �������� � ����� ���� ���������� �� �������� ������ :
/// ʳ������ �������;
/// ʳ������ �����;
/// ʳ������ �������� ����;
/// ʳ������ ����������� ����;
/// ʳ������ ����.
/// </summary>

// ������� ��� ��������, �� � ������ �������� ������
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

// ������� ��� ��������, �� � ������ ����������� ������
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
        lineCount++; // ������ �����
        for (char c : line) {
            if (isalpha(c)) {
                // ������ ������ �� ��������� �����
                if (isVowel(c)) {
                    vowelCount++;
                }
                else if (isConsonant(c)) {
                    consonantCount++;
                }
            }
            else if (isdigit(c)) {
                digitCount++; // ������ �����
            }
            charCount++; // ������ �� �������
        }
        charCount++; // ������ ������ �������� �� ����� �����
    }

    // �������� ���������� � ����� ����
    outFile << "Number of characters: " << charCount << endl;
    outFile << "Number of lines: " << lineCount << endl;
    outFile << "Number of vowels: " << vowelCount << endl;
    outFile << "Number of consonants: " << consonantCount << endl;
    outFile << "Number of digits: " << digitCount << endl;

    // �������� �����
    file.close();
    outFile.close();

    cout << "Statistics written to " << outputFile << endl;

    return 0;
}
