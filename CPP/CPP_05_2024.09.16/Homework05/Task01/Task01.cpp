#include <iostream>
#include <cctype>  // for isalpha, isdigit, ispunct, isspace

using namespace std;

/// <summary>
/// Завдання 1
/// Користувач вводить з клавіатури символ. Визначити, який це символ: літера, цифра, знак пунктуації або інше.
/// </summary>
int main() {
    // Input: a character
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    // Determine the type of character
    if (isalpha(ch)) {
        cout << "This is a letter." << endl;
    }
    else if (isdigit(ch)) {
        cout << "This is a digit." << endl;
    }
    else if (ispunct(ch)) {
        cout << "This is a punctuation mark." << endl;
    }
    else if (isspace(ch)) {
        cout << "This is a whitespace character." << endl;
    }
    else {
        cout << "This is something else." << endl;
    }

    return 0;
}
