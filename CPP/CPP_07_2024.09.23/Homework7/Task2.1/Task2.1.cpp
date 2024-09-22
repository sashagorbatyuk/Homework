#include <iostream>
#include <cmath>
using namespace std;

void countDigits(int number);
void calculateSumAndAverage(int number);
void countZeros(int number);

int main() {
    int choice;
    int number;

    do {
        cout << "Choose an option:\n";
        cout << "1. Enter a number\n";
        cout << "2. Count the digits in the number\n";
        cout << "3. Calculate the sum of digits and arithmetic mean\n";
        cout << "4. Count the number of zeros in the number\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the number: ";
            cin >> number;
            break;
        case 2:
            countDigits(number);
            break;
        case 3:
            calculateSumAndAverage(number);
            break;
        case 4:
            countZeros(number);
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}

void countDigits(int number) {
    int count = 0;
    number = fabs(number);

    if (number == 0) {
        count = 1;
    }
    else {
        while (number > 0) {
            number /= 10;
            count++;
        }
    }

    cout << "Number of digits: " << count << endl;
}

void calculateSumAndAverage(int number) {
    int sum = 0, count = 0;
    double average;
    number = fabs(number);

    if (number == 0) {
        sum = 0;
        count = 1;
    }
    else {
        while (number > 0) {
            sum += number % 10;
            number /= 10;
            count++;
        }
    }

    average = static_cast<double>(sum) / count;
    cout << "Sum of digits: " << sum << endl;
    cout << "Arithmetic mean: " << average << endl;
}

void countZeros(int number) {
    int zeros = 0;
    number = fabs(number);

    if (number == 0) {
        zeros = 1;
    }
    else {
        while (number > 0) {
            if (number % 10 == 0) {
                zeros++;
            }
            number /= 10;
        }
    }

    cout << "Number of zeros: " << zeros << endl;
}