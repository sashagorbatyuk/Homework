#include "Service.h"

// Конструктор: ініціалізація полів послуги
Service::Service(int id, const string& name, double price)
    : id(id), name(name), price(price) {}

// Повертає унікальний ідентифікатор послуги
int Service::getId() const { return id; }

// Повертає назву послуги
string Service::getName() const { return name; }

// Повертає вартість послуги
double Service::getPrice() const { return price; }

// Встановлює нову назву послуги
void Service::setName(const string& name) { this->name = name; }

// Встановлює нову вартість послуги
void Service::setPrice(double price) { this->price = price; }