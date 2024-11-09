#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

// ������� ��� ��������� ����������� ����� � �������� �������
int getRandomInt(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// ������� ��� ��������� ������� ����������� ����
void simulateTaxiStop(int passengers_interval, int taxi_interval, bool isFinalStop, int N, int num_simulations) {
    vector<int> waitTimes;
    vector<int> taxiArrivals;

    int total_passengers = 0;
    int total_time_spent = 0;

    // ��������� ������ ������ (���������, 100 ���������)
    for (int i = 0; i < num_simulations; ++i) {
        int current_time = 0;
        vector<int> passengers;
        int passengers_on_stop = 0;
        int last_taxi_time = -taxi_interval;

        // ��������� �������� �� ���������
        while (passengers_on_stop <= N) {
            // ��������� ����������� ���� �� ����� ������ ��������
            int next_passenger_time = current_time + getRandomInt(1, passengers_interval);
            if (next_passenger_time > current_time) {
                passengers.push_back(next_passenger_time);
                passengers_on_stop++;
                current_time = next_passenger_time;
            }

            // ��������� ���� �������� ���������
            if (current_time >= last_taxi_time + taxi_interval) {
                int free_seats = getRandomInt(0, 10); // ��������� ������� ������ ����
                if (free_seats > passengers_on_stop) {
                    // ���� � ���� ����, �� �������� ������ ������
                    passengers_on_stop = max(0, passengers_on_stop - free_seats);
                }
                last_taxi_time = current_time;
            }
        }

        // ϳ��������� ��� ����������� ��������
        for (int time : passengers) {
            total_time_spent += current_time - time;
        }
        total_passengers += passengers.size();
    }

    // ������� ��� ����������
    double avg_wait_time = static_cast<double>(total_time_spent) / total_passengers;
    cout << "Average wait time per passenger: " << fixed << setprecision(2) << avg_wait_time << " minutes\n";
}

int main() {
    int passengers_interval, taxi_interval, N, num_simulations;
    bool isFinalStop;

    // �������� ���������
    cout << "Enter average time between passengers (in minutes): ";
    cin >> passengers_interval;
    cout << "Enter average time between taxis (in minutes): ";
    cin >> taxi_interval;
    cout << "Enter whether the stop is final (1 for yes, 0 for no): ";
    cin >> isFinalStop;
    cout << "Enter the maximum number of passengers at the stop: ";
    cin >> N;
    cout << "Enter the number of simulations: ";
    cin >> num_simulations;

    // ���������
    simulateTaxiStop(passengers_interval, taxi_interval, isFinalStop, N, num_simulations);

    return 0;
}