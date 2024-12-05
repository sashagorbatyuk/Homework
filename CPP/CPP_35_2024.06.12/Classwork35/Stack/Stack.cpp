#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(const string& binary) {
    int start = 0, end = binary.size() - 1;
    while (start < end) {
        if (binary[start] != binary[end]) return false;
        ++start;
        --end;
    }
    return true;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    stack<int> binaryStack;
    int temp = number;
    while (temp > 0) {
        binaryStack.push(temp % 2);
        temp /= 2;
    }

    string binary = "";
    while (!binaryStack.empty()) {
        binary += to_string(binaryStack.top());
        binaryStack.pop();
    }

    cout << "Binary representation: " << binary << "\n";

    if (isPalindrome(binary)) {
        cout << "The binary number is a palindrome. \n";
    }
    else {
        cout << "The binary number is not a palindrome. \n";
    }

    return 0;
}