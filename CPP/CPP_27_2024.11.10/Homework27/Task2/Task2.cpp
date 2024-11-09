#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Структура для клієнта
struct Client {
    string name;
    int priority;
    time_t requestTime;

    // Оператор порівняння для пріоритетної черги (для порівняння пріоритетів)
    bool operator<(const Client& other) const {
        return priority > other.priority;
    }
};

// Структура для збереження статистики
struct PrintJob {
    string clientName;
    time_t printTime;
};

// Черга для клієнтів
priority_queue<Client> printQueue;
// Черга для статистики
vector<PrintJob> printStatistics;

// Функція для симуляції друку
void printDocument() {
    while (!printQueue.empty()) {
        // Отримуємо наступного клієнта з черги
        Client currentClient = printQueue.top();
        printQueue.pop();

        // Створюємо запис про час друку
        time_t printTime = time(0);
        printStatistics.push_back(PrintJob{ currentClient.name, printTime });

        // Симулюємо час друку (наприклад, 2 секунди)
        cout << "Printing for client: " << currentClient.name << " (Priority: " << currentClient.priority << ")...\n";
        this_thread::sleep_for(chrono::seconds(2));

        // Виводимо статистику
        cout << "Printed by: " << currentClient.name << " at " << ctime(&printTime) << endl;
    }
}

// Функція для додавання клієнта в чергу друку
void addClientToQueue(const string& name, int priority) {
    Client newClient{ name, priority, time(0) };
    printQueue.push(newClient);
    cout << "Client " << name << " with priority " << priority << " added to the print queue.\n";
}

// Функція для виведення статистики
void printStatisticsReport() {
    cout << "\n--- Print Statistics ---\n";
    for (const auto& job : printStatistics) {
        cout << "Client: " << job.clientName << ", Printed at: " << ctime(&job.printTime);
    }
}

int main() {
    // Додавання клієнтів
    addClientToQueue("Alice", 3);
    addClientToQueue("Bob", 1);
    addClientToQueue("Charlie", 5);
    addClientToQueue("David", 2);

    thread printThread(printDocument);

    printThread.join();

    printStatisticsReport();

    return 0;
}
