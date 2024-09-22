#include <iostream>
#include <vector>  // ��� ��������� ������
#include <limits>  // ��� ����������� min � max

using namespace std;

/// <summary>
/// � ������������ �����, �� ���������� � N ������ �����, ���������:
/// - ���� ��'����� ��������;
/// - ������� ��������, �� ���������� �� min � max ����������;
/// - ������� �������� � ������� ��������;
/// - ���� ��������, �� ���������� �� ������ � ������� ��'������ ����������
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

    // 1. ���� ��'����� ��������
    double negativeSum = 0;
    for (double num : array) {
        if (num < 0) {
            negativeSum += num;
        }
    }

    // 2. ������� �������� �� ��������� � ������������ ����������
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; ++i) {
        if (array[i] < array[minIndex]) minIndex = i;
        if (array[i] > array[maxIndex]) maxIndex = i;
    }

    // ��������� ������� �� min � max ����������
    double productBetweenMinMax = 1;
    if (minIndex > maxIndex) swap(minIndex, maxIndex);  // ������������� �������
    for (int i = minIndex + 1; i < maxIndex; ++i) {
        productBetweenMinMax *= array[i];
    }

    // 3. ������� �������� � ������� ��������
    double productEvenIndices = 1;
    for (int i = 0; i < N; i += 2) {  // �������� � ������� ���������: 0, 2, 4, ...
        productEvenIndices *= array[i];
    }

    // 4. ���� �������� �� ������ � ������� ��'������ ����������
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

    // ��������� ����������
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
