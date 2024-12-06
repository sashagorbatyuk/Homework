#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// ���� ��� ������ �� ������������
class Order {
private:
    string senderName;     // ��'� ����������
    string receiverName;   // ��'� ����������
    string itemDescription; // ���� ������
    double payment;        // ���� ������
    bool isDelivered;      // ������ ��������

public:
    // �����������
    Order(const string& sender, const string& receiver, const string& description, double pay);

    // ������
    string getSenderName() const;
    string getReceiverName() const;
    string getItemDescription() const;
    double getPayment() const;
    bool getDeliveryStatus() const;

    // ������� ��� ���������� ��������
    void markAsDelivered();

    // ���� ���������
    void printReceipt() const;
};

#endif