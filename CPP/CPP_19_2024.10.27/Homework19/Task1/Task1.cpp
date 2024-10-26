#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// Клас для представлення людини
class Person {
    char* name;
    int age;

public:
    // Конструктор з параметрами
    Person(const char* name, int age) : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name); // Використовуємо strcpy_s
    }

    // Конструктор копіювання
    Person(const Person& other) : age(other.age) {
        this->name = new char[strlen(other.name) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name); // Використовуємо strcpy_s
    }

    // Деструктор
    ~Person() {
        delete[] name;
    }

    // Вивід інформації про людину
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Клас для представлення квартири
class Apartment {
    vector<Person*> residents; // вектор мешканців в квартирі

public:
    // Конструктор за замовчуванням
    Apartment() {}

    // Додавання мешканця до квартири
    void addResident(Person* person) {
        residents.push_back(person);
    }

    // Конструктор копіювання
    Apartment(const Apartment& other) {
        for (auto resident : other.residents) {
            residents.push_back(new Person(*resident));
        }
    }

    // Деструктор
    ~Apartment() {
        for (auto resident : residents) {
            delete resident;
        }
    }

    // Вивід інформації про всіх мешканців
    void displayResidents() const {
        for (auto resident : residents) {
            resident->display();
        }
    }
};

// Клас для представлення будинку
class House {
    vector<Apartment> apartments; // масив квартир

public:
    // Додавання квартири до будинку
    void addApartment(const Apartment& apartment) {
        apartments.push_back(apartment);
    }

    // Вивід інформації про всі квартири та мешканців
    void displayHouseInfo() const {
        for (int i = 0; i < apartments.size(); i++) {
            cout << "Apartment " << i + 1 << " residents:" << endl;
            apartments[i].displayResidents();
        }
    }
};

int main() {
    // Створення мешканців
    Person* person1 = new Person("Alice", 30);
    Person* person2 = new Person("Bob", 45);
    Person* person3 = new Person("Charlie", 25);

    // Створення квартир і додавання мешканців
    Apartment apt1;
    apt1.addResident(person1);
    apt1.addResident(person2);

    Apartment apt2;
    apt2.addResident(person3);

    // Створення будинку і додавання квартир
    House house;
    house.addApartment(apt1);
    house.addApartment(apt2);

    // Виведення інформації про будинок
    house.displayHouseInfo();

    return 0;
}
