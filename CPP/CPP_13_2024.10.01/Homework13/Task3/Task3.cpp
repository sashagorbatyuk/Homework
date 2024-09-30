#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// ��������� ����������� ��������������� �����
string generateNumber() {
    string num;
    srand(time(0)); // ����������� ���������� ���������� �����
    for (int i = 0; i < 4; ++i) {
        num += '0' + rand() % 10; // ������ ��������� �����
    }
    return num;
}

// ������� ��� ��������� ���� � ���� (������� ������)
void countBullsAndCows(const string& secret, const string& guess, int& cows, int& bulls) {
    bulls = 0;
    cows = 0;
    bool used[4] = { false }; // ��� ���������� ������������ ����

    // ϳ�������� ���� (�������� ����� �� ���������� �����)
    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            cows++;
            used[i] = true; // ���������, �� ����� �����������
        }
    }

    // ϳ�������� ���� (�������� ����� �� ������������ �����)
    for (int i = 0; i < 4; ++i) {
        if (secret[i] != guess[i]) {
            for (int j = 0; j < 4; ++j) {
                if (!used[j] && guess[i] == secret[j]) {
                    bulls++;
                    used[j] = true; // ���������, �� ����� �����������
                    break;
                }
            }
        }
    }
}

// ���������� ������� ��� ��� "���� �� ������"
void playGame(const string& secret, int& attempts) {
    string guess;
    int bulls = 0, cows = 0;

    // �������� ������ �����������
    cout << "Enter your guess (4 digits): ";
    cin >> guess;

    // ���������� ������
    countBullsAndCows(secret, guess, cows, bulls);
    attempts++;

    // ���� ������� ������
    if (cows == 4) {
        cout << "Congratulations! You've guessed the number!" << endl;
        cout << "Total attempts: " << attempts << endl;
    }
    else {
        // �������� ������� ���� � ����
        cout << "Cows: " << cows << ", Bulls: " << bulls << endl;
        // ���������� ��������� ��� �����
        playGame(secret, attempts);
    }
}

int main() {
    // �������� ��������� �����
    string secret = generateNumber();

    // ��� ���������� ����� ������� �������� �����
    cout << "(Secret number for testing: " << secret << ")\n";

    int attempts = 0;

    // ������ ���
    playGame(secret, attempts);

    return 0;
}
