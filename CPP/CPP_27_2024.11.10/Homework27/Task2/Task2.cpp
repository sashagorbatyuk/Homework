#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// ��������� ��� �볺���
struct Client {
    string name;
    int priority;
    time_t requestTime;

    // �������� ��������� ��� ���������� ����� (��� ��������� ���������)
    bool operator<(const Client& other) const {
        return priority > other.priority;
    }
};

// ��������� ��� ���������� ����������
struct PrintJob {
    string clientName;
    time_t printTime;
};

// ����� ��� �볺���
priority_queue<Client> printQueue;
// ����� ��� ����������
vector<PrintJob> printStatistics;

// ������� ��� ��������� �����
void printDocument() {
    while (!printQueue.empty()) {
        // �������� ���������� �볺��� � �����
        Client currentClient = printQueue.top();
        printQueue.pop();

        // ��������� ����� ��� ��� �����
        time_t printTime = time(0);
        printStatistics.push_back(PrintJob{ currentClient.name, printTime });

        // ��������� ��� ����� (���������, 2 �������)
        cout << "Printing for client: " << currentClient.name << " (Priority: " << currentClient.priority << ")...\n";
        this_thread::sleep_for(chrono::seconds(2));

        // �������� ����������
        cout << "Printed by: " << currentClient.name << " at " << ctime(&printTime) << endl;
    }
}

// ������� ��� ��������� �볺��� � ����� �����
void addClientToQueue(const string& name, int priority) {
    Client newClient{ name, priority, time(0) };
    printQueue.push(newClient);
    cout << "Client " << name << " with priority " << priority << " added to the print queue.\n";
}

// ������� ��� ��������� ����������
void printStatisticsReport() {
    cout << "\n--- Print Statistics ---\n";
    for (const auto& job : printStatistics) {
        cout << "Client: " << job.clientName << ", Printed at: " << ctime(&job.printTime);
    }
}

int main() {
    // ��������� �볺���
    addClientToQueue("Alice", 3);
    addClientToQueue("Bob", 1);
    addClientToQueue("Charlie", 5);
    addClientToQueue("David", 2);

    thread printThread(printDocument);

    printThread.join();

    printStatisticsReport();

    return 0;
}
