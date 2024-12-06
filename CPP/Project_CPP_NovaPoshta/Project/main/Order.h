#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Клас для роботи із замовленнями
class Order {
private:
    string senderName;     // Ім'я відправника
    string receiverName;   // Ім'я отримувача
    string itemDescription; // Опис товару
    double payment;        // Сума оплати
    bool isDelivered;      // Статус доставки

public:
    // Конструктор
    Order(const string& sender, const string& receiver, const string& description, double pay);

    // Гетери
    string getSenderName() const;
    string getReceiverName() const;
    string getItemDescription() const;
    double getPayment() const;
    bool getDeliveryStatus() const;

    // Функція для позначення доставки
    void markAsDelivered();

    // Друк квитанції
    void printReceipt() const;
};

#endif