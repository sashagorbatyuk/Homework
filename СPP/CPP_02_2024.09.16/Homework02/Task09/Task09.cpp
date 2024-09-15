#include <iostream>
using namespace std;

/// <summary>
/// ���������� ������� � ��������� ������� ����� � ���� �� �������� ������ �� ���� � ���������� �� �������
/// ����������, ������ ���� ����� ����� ����� ����� �� ����.
/// </summary>
int main() {
    long long fileSizeBytes;
    double writeSpeedMBps;

    cout << "Enter the file size in bytes: ";
    cin >> fileSizeBytes;

    cout << "Enter the write speed in megabytes per second (MB/s): ";
    cin >> writeSpeedMBps;

    // Convert file size from bytes to megabytes (1 MB = 1,048,576 bytes)
    double fileSizeMB = static_cast<double>(fileSizeBytes) / (1024 * 1024);

    // Calculate the time to write the file to disk
    double writeTimeSeconds = fileSizeMB / writeSpeedMBps;

    // Output the results
    cout << "The time to write the file to disk is: " << writeTimeSeconds << " seconds" << endl;

    return 0;
}
