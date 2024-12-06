#include "Order.h"

// Конструктор
Order::Order(const string& sender, const string& receiver, const string& description, double pay)
    : senderName(sender), receiverName(receiver), itemDescription(description), payment(pay), isDelivered(false) {}

// Гетери
string Order::getSenderName() const {
    return senderName;
}

string Order::getReceiverName() const {
    return receiverName;
}

string Order::getItemDescription() const {
    return itemDescription;
}

double Order::getPayment() const {
    return payment;
}

bool Order::getDeliveryStatus() const {
    return isDelivered;
}

// Позначення доставки
void Order::markAsDelivered() {
    isDelivered = true;
}

// Друк квитанції
void Order::printReceipt() const {
    cout << "\n--- Receipt ---\n";
    cout << "Sender: " << senderName << "\n";
    cout << "Receiver: " << receiverName << "\n";
    cout << "Item: " << itemDescription << "\n";
    cout << "Payment: " << fixed << setprecision(2) << payment << "\n";
    cout << "----------------\n";
}