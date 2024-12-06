#include "Order.h"

// �����������
Order::Order(const string& sender, const string& receiver, const string& description, double pay)
    : senderName(sender), receiverName(receiver), itemDescription(description), payment(pay), isDelivered(false) {}

// ������
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

// ���������� ��������
void Order::markAsDelivered() {
    isDelivered = true;
}

// ���� ���������
void Order::printReceipt() const {
    cout << "\n--- Receipt ---\n";
    cout << "Sender: " << senderName << "\n";
    cout << "Receiver: " << receiverName << "\n";
    cout << "Item: " << itemDescription << "\n";
    cout << "Payment: " << fixed << setprecision(2) << payment << "\n";
    cout << "----------------\n";
}