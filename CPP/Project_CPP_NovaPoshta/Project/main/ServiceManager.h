#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "Order.h"
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

// Клас для управління сервісом
class ServiceManager {
private:
    map<string, double> services;    // Послуги: назва -> ціна
    queue<Order> pendingOrders;      // Черга замовлень
    vector<Order> completedOrders;   // Виконані замовлення

public:
    // Методи для управління послугами
    void displayServices() const;              // Вивести доступні послуги
    void addService(const string& name, double price); // Додати послугу
    void editService(const string& name, double newPrice); // Редагувати послугу
    void removeService(const string& name);    // Видалити послугу
    void saveServices(const string& filename) const;  // Зберегти послуги у файл
    void loadServices(const string& filename); // Завантажити послуги з файлу

    // Методи для управління замовленнями
    void addOrder(const Order& order);         // Додати замовлення
    void processOrder();                       // Обробити замовлення
    void displayCompletedOrders() const;       // Вивести завершені замовлення
    void saveCompletedOrders(const string& filename) const; // Зберегти виконані замовлення
};

#endif