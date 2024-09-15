#include <iostream>

using namespace std;

/// <summary>
/// Завдання 2.5.
/// Користувач вводить з клавіатури розмір одного файлу в гігабайтах і швидкість інтернет - з’єднання в бітах на секунду. 
/// Порахувати, за скільки годин, хвилин і секунд завантажиться файл.
/// </summary>

int main() {
    // Input: file size in gigabytes and internet speed in bits per second
    double file_size_gb;
    double internet_speed_bps;

    cout << "Enter the file size (in GB): ";
    cin >> file_size_gb;

    cout << "Enter the internet speed (in bits per second): ";
    cin >> internet_speed_bps;

    // Convert file size from gigabytes to bits (1 GB = 8 * 1024^3 bits)
    double file_size_bits = file_size_gb * 8 * 1024 * 1024 * 1024;

    // Calculate download time in seconds
    double download_time_seconds = file_size_bits / internet_speed_bps;

    // Calculate hours, minutes, and seconds
    int hours = static_cast<int>(download_time_seconds) / 3600;
    int minutes = (static_cast<int>(download_time_seconds) % 3600) / 60;
    int seconds = static_cast<int>(download_time_seconds) % 60;

    // Output the download time
    cout << "Download time: " << hours << " hours, " << minutes
        << " minutes, and " << seconds << " seconds." << endl;

    return 0;
}
