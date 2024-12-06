#pragma once
#ifndef SERVICE_H
#define SERVICE_H

#include <string>
using namespace std; // Використання простору імен std

// Клас Service для опису послуги
class Service {
private:
    int id; // Унікальний ідентифікатор послуги
    string name; // Назва послуги
    double price; // Вартість послуги

public:
    // Конструктор для ініціалізації послуги
    Service(int id, const string& name, double price);

    // Геттери для доступу до приватних полів
    int getId() const;
    string getName() const;
    double getPrice() const;

    // Сеттери для оновлення приватних полів
    void setName(const string& name);
    void setPrice(double price);
};

#endif