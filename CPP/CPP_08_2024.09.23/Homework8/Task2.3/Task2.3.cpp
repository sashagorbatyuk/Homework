#include <iostream>
#include <vector>  // Для зберігання масиву
#include <limits>  // Для ініціалізації min і max

using namespace std;

/// <summary>
/// В одновимірному масиві, що складається з N дійсних чисел, обчислити:
/// - Суму від'ємних елементів;
/// - Добуток елементів, що розташовані між min і max елементами;
/// - Добуток елементів з парними номерами;
/// - Суму елементів, що розташовані між першим і останнім від'ємними елементами
/// </summary>
int main() {
    int N;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    vector<double> array(N);
    cout << "Enter " << N << " real numbers:\n";
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    // 1. Сума від'ємних елементів
    double negativeSum = 0;
    for (double num : array) {
        if (num < 0) {
            negativeSum += num;
        }
    }

    // 2. Добуток елементів між мінімальним і максимальним елементами
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; ++i) {
        if (array[i] < array[minIndex]) minIndex = i;
        if (array[i] > array[maxIndex]) maxIndex = i;
    }

    // Знаходимо добуток між min і max елементами
    double productBetweenMinMax = 1;
    if (minIndex > maxIndex) swap(minIndex, maxIndex);  // Переставляємо індекси
    for (int i = minIndex + 1; i < maxIndex; ++i) {
        productBetweenMinMax *= array[i];
    }

    // 3. Добуток елементів з парними номерами
    double productEvenIndices = 1;
    for (int i = 0; i < N; i += 2) {  // елементи з парними індексами: 0, 2, 4, ...
        productEvenIndices *= array[i];
    }

    // 4. Сума елементів між першим і останнім від'ємними елементами
    int firstNegativeIndex = -1, lastNegativeIndex = -1;
    for (int i = 0; i < N; ++i) {
        if (array[i] < 0) {
            if (firstNegativeIndex == -1) firstNegativeIndex = i;
            lastNegativeIndex = i;
        }
    }

    double sumBetweenNegatives = 0;
    if (firstNegativeIndex != -1 && lastNegativeIndex != -1 && firstNegativeIndex != lastNegativeIndex) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            sumBetweenNegatives += array[i];
        }
    }

    // Виведення результатів
    cout << "\nSum of negative elements: " << negativeSum << endl;
    if (minIndex + 1 == maxIndex) {
        cout << "No elements between min and max." << endl;
    }
    else {
        cout << "Product of elements between min and max: " << productBetweenMinMax << endl;
    }
    cout << "Product of elements with even indices: " << productEvenIndices << endl;
    if (firstNegativeIndex != -1 && lastNegativeIndex != -1 && firstNegativeIndex != lastNegativeIndex) {
        cout << "Sum of elements between first and last negative elements: " << sumBetweenNegatives << endl;
    }
    else {
        cout << "No negative elements or not enough negative elements to calculate sum." << endl;
    }

    return 0;
}
