#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "Order.h"
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

// ���� ��� ��������� �������
class ServiceManager {
private:
    map<string, double> services;    // �������: ����� -> ����
    queue<Order> pendingOrders;      // ����� ���������
    vector<Order> completedOrders;   // ������� ����������

public:
    // ������ ��� ��������� ���������
    void displayServices() const;              // ������� ������� �������
    void addService(const string& name, double price); // ������ �������
    void editService(const string& name, double newPrice); // ���������� �������
    void removeService(const string& name);    // �������� �������
    void saveServices(const string& filename) const;  // �������� ������� � ����
    void loadServices(const string& filename); // ����������� ������� � �����

    // ������ ��� ��������� ������������
    void addOrder(const Order& order);         // ������ ����������
    void processOrder();                       // �������� ����������
    void displayCompletedOrders() const;       // ������� �������� ����������
    void saveCompletedOrders(const string& filename) const; // �������� ������� ����������
};

#endif