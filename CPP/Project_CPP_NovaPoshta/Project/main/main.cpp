#include "ServiceManager.h"
#include <iostream>
using namespace std;

int main() {
    ServiceManager manager;
    int choice;

    do {
        cout << "\n--- Nova Poshta ---\n";
        cout << "1. Display services\n"
            << "2. Add service\n"
            << "3. Edit service\n"
            << "4. Remove service\n"
            << "5. Save services to file\n"
            << "6. Load services from file\n"
            << "7. Add order\n"
            << "8. Process order\n"
            << "9. Display completed orders\n"
            << "10. Save completed orders to file\n"
            << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.displayServices();
            break;
        case 2: {
            string name;
            double price;
            cout << "Enter service name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter service price: ";
            cin >> price;
            manager.addService(name, price);
            break;
        }
        case 3: {
            string name;
            double price;
            cout << "Enter service name to edit: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new price: ";
            cin >> price;
            manager.editService(name, price);
            break;
        }
        case 4: {
            string name;
            cout << "Enter service name to remove: ";
            cin.ignore();
            getline(cin, name);
            manager.removeService(name);
            break;
        }
        case 5: {
            string filename;
            cout << "Enter filename to save services: ";
            cin >> filename;
            manager.saveServices(filename);
            break;
        }
        case 6: {
            string filename;
            cout << "Enter filename to load services: ";
            cin >> filename;
            manager.loadServices(filename);
            break;
        }
        case 7: {
            string sender, receiver, description;
            double payment;
            cout << "Enter sender's name: ";
            cin.ignore();
            getline(cin, sender);
            cout << "Enter receiver's name: ";
            getline(cin, receiver);
            cout << "Enter item description: ";
            getline(cin, description);
            cout << "Enter payment amount: ";
            cin >> payment;
            Order order(sender, receiver, description, payment);
            manager.addOrder(order);
            break;
        }
        case 8:
            manager.processOrder();
            break;
        case 9:
            manager.displayCompletedOrders();
            break;
        case 10: {
            string filename;
            cout << "Enter filename to save completed orders: ";
            cin >> filename;
            manager.saveCompletedOrders(filename);
            break;
        }
        case 11:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 11);

    return 0;
}