#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// ���� ��� ������������� ������
class Person {
    char* name;
    int age;

public:
    // ����������� � �����������
    Person(const char* name, int age) : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name); // ������������� strcpy_s
    }

    // ����������� ���������
    Person(const Person& other) : age(other.age) {
        this->name = new char[strlen(other.name) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name); // ������������� strcpy_s
    }

    // ����������
    ~Person() {
        delete[] name;
    }

    // ���� ���������� ��� ������
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// ���� ��� ������������� ��������
class Apartment {
    vector<Person*> residents; // ������ ��������� � �������

public:
    // ����������� �� �������������
    Apartment() {}

    // ��������� �������� �� ��������
    void addResident(Person* person) {
        residents.push_back(person);
    }

    // ����������� ���������
    Apartment(const Apartment& other) {
        for (auto resident : other.residents) {
            residents.push_back(new Person(*resident));
        }
    }

    // ����������
    ~Apartment() {
        for (auto resident : residents) {
            delete resident;
        }
    }

    // ���� ���������� ��� ��� ���������
    void displayResidents() const {
        for (auto resident : residents) {
            resident->display();
        }
    }
};

// ���� ��� ������������� �������
class House {
    vector<Apartment> apartments; // ����� �������

public:
    // ��������� �������� �� �������
    void addApartment(const Apartment& apartment) {
        apartments.push_back(apartment);
    }

    // ���� ���������� ��� �� �������� �� ���������
    void displayHouseInfo() const {
        for (int i = 0; i < apartments.size(); i++) {
            cout << "Apartment " << i + 1 << " residents:" << endl;
            apartments[i].displayResidents();
        }
    }
};

int main() {
    // ��������� ���������
    Person* person1 = new Person("Alice", 30);
    Person* person2 = new Person("Bob", 45);
    Person* person3 = new Person("Charlie", 25);

    // ��������� ������� � ��������� ���������
    Apartment apt1;
    apt1.addResident(person1);
    apt1.addResident(person2);

    Apartment apt2;
    apt2.addResident(person3);

    // ��������� ������� � ��������� �������
    House house;
    house.addApartment(apt1);
    house.addApartment(apt2);

    // ��������� ���������� ��� �������
    house.displayHouseInfo();

    return 0;
}
