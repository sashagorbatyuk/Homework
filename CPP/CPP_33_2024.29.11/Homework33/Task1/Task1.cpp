#include <iostream>
#include <string>
using namespace std;

// ���� ��� ������������� ������� ���������
class Engine {
private:
    int horsepower;  // ��������� ������� � ������� �����
    string engineType;  // ��� ������� (e.g., "Gasoline", "Diesel", "Electric")

public:
    // ����������� ��� ����������� ��������� �������
    Engine(int hp, string type) : horsepower(hp), engineType(type) {}

    // ����� ��� ��������� ���������� ��� ������
    void printEngineInfo() const {
        cout << "Engine Type: " << engineType << ", Horsepower: " << horsepower << " hp" << endl;
    }
};

// ���� ��� ������������� ���� ���������
class Driver {
private:
    string name;  // ��'� ����
    int age;  // ³� ����

public:
    // ����������� ��� ����������� ��������� ����
    Driver(string name, int age) : name(name), age(age) {}

    // ����� ��� ��������� ���������� ��� ����
    void printDriverInfo() const {
        cout << "Driver Name: " << name << ", Age: " << age << " years" << endl;
    }
};

// ���� ��� ������������� ���������, ���� ������ ������ � ����
class Car {
private:
    string brand;  // ����� ��������� (e.g., "Toyota", "BMW")
    string model;  // ������ ��������� (e.g., "Corolla", "X5")
    int year;  // г� �������
    Engine* engine;  // ������ � �������� ��������� (����������)
    Driver* driver;  // ���� ���� ���� ������������ � ���������� (���������)

public:
    // ����������� ��� ����������� ������� ��������� �� ��������� � ��������
    Car(string brand, string model, int year, Engine* eng)
        : brand(brand), model(model), year(year), engine(eng), driver(nullptr) {}

    // ����� ��� ���������� ���� �� ��������� (���������)
    void setDriver(Driver* drv) {
        driver = drv;
    }

    // ����� ��� ��������� ���������� ��� ���������, ������ � ���� (���� �)
    void printCarInfo() const {
        cout << "Car Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
        if (engine != nullptr) {
            engine->printEngineInfo();
        }
        if (driver != nullptr) {
            driver->printDriverInfo();
        }
        else {
            cout << "No driver assigned to this car." << endl;  // ���� ���� �� �����������
        }
    }
};

// ������� �������
int main() {
    // ��������� ��'���� �������
    Engine engine1(150, "Gasoline");
    Engine engine2(200, "Diesel");
    Engine engine3(250, "Electric");

    // ��������� ��'���� ��������� � ���������� ���������
    Car car1("Toyota", "Corolla", 2020, &engine1);
    Car car2("BMW", "X5", 2021, &engine2);
    Car car3("Tesla", "Model 3", 2023, &engine3);

    // ��������� ��'���� ��䳿�
    Driver driver1("John Doe", 35);
    Driver driver2("Jane Smith", 28);

    // ����������� ��䳿� �� ���������
    car1.setDriver(&driver1);
    car2.setDriver(&driver2);

    // ��������� ���������� ��� ��������, ������� �� ��䳿�
    cout << "Car 1 Information:" << endl;
    car1.printCarInfo();
    cout << endl;

    cout << "Car 2 Information:" << endl;
    car2.printCarInfo();
    cout << endl;

    cout << "Car 3 Information:" << endl;
    car3.printCarInfo();
    cout << endl;

    return 0;
}