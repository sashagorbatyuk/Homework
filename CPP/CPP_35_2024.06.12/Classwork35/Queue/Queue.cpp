#include <iostream>
#include <queue>
#include <string>
#include <cstdlib> // для rand()
using namespace std;

struct Client {
    string name;
    int serviceTime; // Час обслуговування у хвилинах
};

int main() {
    queue<Client> clientQueue;
    int totalServiceTime = 0;

    int choice;
    do {
        cout << "\n1. Add client \n"
            << "2. Serve client \n"
            << "3. Display total service time \n"
            << "4. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            cout << "Enter client name: ";
            cin >> name;
            int serviceTime = rand() % 10 + 1; // Генеруємо випадковий час (1-10 хвилин)
            clientQueue.push({ name, serviceTime });
            cout << "Client added with service time: " << serviceTime << " minutes.\n";
            break;
        }
        case 2: {
            if (!clientQueue.empty()) {
                Client current = clientQueue.front();
                clientQueue.pop();
                cout << "Serving client: " << current.name << ", Service time: " << current.serviceTime << " minutes.\n";
                totalServiceTime += current.serviceTime;
            }
            else {
                cout << "No clients in queue. \n";
            }
            break;
        }
        case 3:
            cout << "Total service time: " << totalServiceTime;
            break;
        case 4:
            cout << "Exiting... \n";
            break;
        default:
            cout << "Invalid choice. \n";
        }
    } while (choice != 4);

    return 0;
}