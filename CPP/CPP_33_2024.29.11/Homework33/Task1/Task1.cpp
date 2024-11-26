#include <iostream>
#include <string>
using namespace std;

// Клас для представлення двигуна автомобіля
class Engine {
private:
    int horsepower;  // Потужність двигуна в кінських силах
    string engineType;  // Тип двигуна (e.g., "Gasoline", "Diesel", "Electric")

public:
    // Конструктор для ініціалізації параметрів двигуна
    Engine(int hp, string type) : horsepower(hp), engineType(type) {}

    // Метод для виведення інформації про двигун
    void printEngineInfo() const {
        cout << "Engine Type: " << engineType << ", Horsepower: " << horsepower << " hp" << endl;
    }
};

// Клас для представлення водія автомобіля
class Driver {
private:
    string name;  // Ім'я водія
    int age;  // Вік водія

public:
    // Конструктор для ініціалізації параметрів водія
    Driver(string name, int age) : name(name), age(age) {}

    // Метод для виведення інформації про водія
    void printDriverInfo() const {
        cout << "Driver Name: " << name << ", Age: " << age << " years" << endl;
    }
};

// Клас для представлення автомобіля, який агрегує двигун і водія
class Car {
private:
    string brand;  // Марка автомобіля (e.g., "Toyota", "BMW")
    string model;  // Модель автомобіля (e.g., "Corolla", "X5")
    int year;  // Рік випуску
    Engine* engine;  // Двигун є частиною автомобіля (композиція)
    Driver* driver;  // Водій може бути асоційований з автомобілем (агрегація)

public:
    // Конструктор для ініціалізації деталей автомобіля та асоціації з двигуном
    Car(string brand, string model, int year, Engine* eng)
        : brand(brand), model(model), year(year), engine(eng), driver(nullptr) {}

    // Метод для підключення водія до автомобіля (агрегація)
    void setDriver(Driver* drv) {
        driver = drv;
    }

    // Метод для виведення інформації про автомобіль, двигун і водія (якщо є)
    void printCarInfo() const {
        cout << "Car Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
        if (engine != nullptr) {
            engine->printEngineInfo();
        }
        if (driver != nullptr) {
            driver->printDriverInfo();
        }
        else {
            cout << "No driver assigned to this car." << endl;  // Якщо водій не призначений
        }
    }
};

// Головна функція
int main() {
    // Створення об'єктів двигунів
    Engine engine1(150, "Gasoline");
    Engine engine2(200, "Diesel");
    Engine engine3(250, "Electric");

    // Створення об'єктів автомобілів з відповідними двигунами
    Car car1("Toyota", "Corolla", 2020, &engine1);
    Car car2("BMW", "X5", 2021, &engine2);
    Car car3("Tesla", "Model 3", 2023, &engine3);

    // Створення об'єктів водіїв
    Driver driver1("John Doe", 35);
    Driver driver2("Jane Smith", 28);

    // Призначення водіїв до автомобілів
    car1.setDriver(&driver1);
    car2.setDriver(&driver2);

    // Виведення інформації про автомобілі, двигуни та водіїв
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