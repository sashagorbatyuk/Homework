#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/// <summary>
/// В одновимірному масиві, заповненому випадковими числами, визначити мінімальний і максимальний елементи
/// </summary>
int main() {
    const int SIZE = 10;
    int array[SIZE];

    srand(static_cast<unsigned>(time(0)));

    //init array random values
    for (int i = 0; i < SIZE; i++) {
        array[i] = (rand() % 100);
    }

    //print array
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }

    //find min and max values
    int minValue = array[0];
    int maxValue = array[0];

    for (int i = 1; i < SIZE; i++) {
        if (array[i] < minValue) 
        {
            minValue = array[i];
        }

        if (array[i] > maxValue) 
        {
            maxValue = array[i];
        }
    }

    cout << "\n\nMinimum element : " << minValue << endl;
    cout << "\nMaximum element : " << maxValue << endl;

    return 0;
}
