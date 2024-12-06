#include "ServiceManager.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// --- Управління послугами ---

// Виведення доступних послуг
void ServiceManager::displayServices() const {
    if (services.empty()) {
        cout << "No services available.\n";
        return;
    }

    cout << "\n--- Available Services ---\n";
    for (const auto& service : services) {
        cout << service.first << ": " << fixed << setprecision(2) << service.second << " UAH\n";
    }
    cout << "--------------------------\n";
}

// Додавання послуги
void ServiceManager::addService(const string& name, double price) {
    services[name] = price;
    cout << "Service added successfully.\n";
}

// Редагування послуги
void ServiceManager::editService(const string& name, double newPrice) {
    if (services.find(name) != services.end()) {
        services[name] = newPrice;
        cout << "Service updated successfully.\n";
    }
    else {
        cout << "Service not found.\n";
    }
}

// Видалення послуги
void ServiceManager::removeService(const string& name) {
    if (services.erase(name)) {
        cout << "Service removed successfully.\n";
    }
    else {
        cout << "Service not found.\n";
    }
}

// Збереження послуг у файл
void ServiceManager::saveServices(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }

    for (const auto& service : services) {
        outFile << service.first << "," << service.second << "\n";
    }
    cout << "Services saved to file.\n";
}

// Завантаження послуг з файлу
void ServiceManager::loadServices(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Unable to open file for reading.\n";
        return;
    }

    services.clear();
    string name;
    double price;
    while (getline(inFile, name, ',') && inFile >> price) {
        inFile.ignore(); // Пропускаємо символ кінця рядка
        services[name] = price;
    }
    cout << "Services loaded from file.\n";
}

// --- Управління замовленнями (як у попередній версії) ---
void ServiceManager::addOrder(const Order& order) {
    pendingOrders.push(order);
    cout << "Order added successfully.\n";
}

void ServiceManager::processOrder() {
    if (pendingOrders.empty()) {
        cout << "No pending orders.\n";
        return;
    }

    Order currentOrder = pendingOrders.front();
    pendingOrders.pop();

    currentOrder.printReceipt();
    cout << "Order has been registered in the database.\n";
    currentOrder.markAsDelivered();
    completedOrders.push_back(currentOrder);
}

void ServiceManager::displayCompletedOrders() const {
    if (completedOrders.empty()) {
        cout << "No completed orders.\n";
        return;
    }

    cout << "\n--- Completed Orders ---\n";
    for (const auto& order : completedOrders) {
        cout << "Sender: " << order.getSenderName() << ", Receiver: " << order.getReceiverName()
            << ", Item: " << order.getItemDescription() << ", Payment: "
            << fixed << setprecision(2) << order.getPayment() << "\n";
    }
    cout << "-------------------------\n";
}

void ServiceManager::saveCompletedOrders(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }

    for (const auto& order : completedOrders) {
        outFile << order.getSenderName() << "," << order.getReceiverName() << ","
            << order.getItemDescription() << "," << order.getPayment() << ","
            << (order.getDeliveryStatus() ? "Delivered" : "Pending") << "\n";
    }
    cout << "Completed orders saved to file.\n";
}