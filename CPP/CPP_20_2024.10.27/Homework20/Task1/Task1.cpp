#include <iostream>
using namespace std;

// Клас Vagon
class Vagon {
    int number;
    int totalPlaces;
    int passengers;

public:
    // Дефолтний конструктор
    Vagon() : number(0), totalPlaces(0), passengers(0) {}

    // Перезавантажений конструктор
    Vagon(int num, int places) : number(num), totalPlaces(places), passengers(0) {}

    // Метод для додавання пасажира
    bool AddPassenger() {
        if (passengers < totalPlaces) {
            ++passengers;
            return true;
        }
        return false;
    }

    // Метод для відображення інформації про вагон
    void Show() const {
        cout << "Vagon Number: " << number << ", Total Places: " << totalPlaces
            << ", Passengers: " << passengers << endl;
    }
};

// Клас Train
class Train {
    string model;
    int vagonCount;
    Vagon* wagons;

public:
    // Дефолтний конструктор
    Train() : model("No Model"), vagonCount(0), wagons(nullptr) {}

    // Перезавантажений конструктор
    Train(string mod) : model(mod), vagonCount(0), wagons(nullptr) {}

    // Конструктор копіювання
    Train(const Train& other) : model(other.model), vagonCount(other.vagonCount) {
        if (other.wagons != nullptr) {
            wagons = new Vagon[vagonCount];
            for (int i = 0; i < vagonCount; i++) {
                wagons[i] = other.wagons[i];
            }
        }
        else {
            wagons = nullptr;
        }
    }

    // Деструктор
    ~Train() {
        delete[] wagons;
    }

    // Метод для додавання нового вагона
    void AddVagon(int number, int places) {
        Vagon* newWagons = new Vagon[vagonCount + 1];
        for (int i = 0; i < vagonCount; i++) {
            newWagons[i] = wagons[i];
        }
        newWagons[vagonCount] = Vagon(number, places);
        delete[] wagons;
        wagons = newWagons;
        ++vagonCount;
    }

    // Метод для доступу до конкретного вагона
    Vagon& GetVagon(int index) {
        if (index >= 0 && index < vagonCount) {
            return wagons[index];
        }
        throw out_of_range("Index out of range");
    }

    // Метод для відображення інформації про потяг
    void Show() const {
        cout << "Train Model: " << model << endl;
        cout << "Number of Wagons: " << vagonCount << endl;
        for (int i = 0; i < vagonCount; i++) {
            wagons[i].Show();
        }
    }
};

// Основна функція
int main() {
    Train train("Express");

    train.AddVagon(1, 50);
    train.AddVagon(2, 60);
    train.AddVagon(3, 30);

    // Додавання пасажирів у вагон 1
    try {
        train.GetVagon(0).AddPassenger();
        train.GetVagon(0).AddPassenger();
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    train.Show();

    return 0;
}