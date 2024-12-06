#include "Service.h"

// �����������: ����������� ���� �������
Service::Service(int id, const string& name, double price)
    : id(id), name(name), price(price) {}

// ������� ��������� ������������� �������
int Service::getId() const { return id; }

// ������� ����� �������
string Service::getName() const { return name; }

// ������� ������� �������
double Service::getPrice() const { return price; }

// ���������� ���� ����� �������
void Service::setName(const string& name) { this->name = name; }

// ���������� ���� ������� �������
void Service::setPrice(double price) { this->price = price; }