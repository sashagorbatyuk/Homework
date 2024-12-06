#pragma once
#ifndef SERVICE_H
#define SERVICE_H

#include <string>
using namespace std; // ������������ �������� ���� std

// ���� Service ��� ����� �������
class Service {
private:
    int id; // ��������� ������������� �������
    string name; // ����� �������
    double price; // ������� �������

public:
    // ����������� ��� ����������� �������
    Service(int id, const string& name, double price);

    // ������� ��� ������� �� ��������� ����
    int getId() const;
    string getName() const;
    double getPrice() const;

    // ������� ��� ��������� ��������� ����
    void setName(const string& name);
    void setPrice(double price);
};

#endif