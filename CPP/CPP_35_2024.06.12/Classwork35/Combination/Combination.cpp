#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Car {
    string licensePlate;
    Car(string plate) : licensePlate(plate) {}
};

int main() {
    queue<Car> carQueue; // Черга автомобілів
    stack<Car> parkingLot; // Парковка
    const int maxParkingSize = 5; // Максимальна кількість місць на парковці
    int choice;

    do {
        cout << "\n1. Add car to queue \n"
            << "2. Park car \n"
            << "3. Remove car from parking \n"
            << "4. Display parking lot and queue \n"
            << "5. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string licensePlate;
            cout << "Enter car license plate: ";
            cin >> licensePlate;
            carQueue.push(Car(licensePlate));
            cout << "Car added to queue. \n";
            break;
        }
        case 2: {
            if (!carQueue.empty() && parkingLot.size() < maxParkingSize) {
                parkingLot.push(carQueue.front());
                carQueue.pop();
                cout << "Car parked. \n";
            }
            else if (parkingLot.size() >= maxParkingSize) {
                cout << "Parking lot is full. \n";
            }
            else {
                cout << "No cars in queue. \n";
            }
            break;
        }
        case 3: {
            if (!parkingLot.empty()) {
                string targetCar = parkingLot.top().licensePlate;
                parkingLot.pop();
                cout << "Car with license plate " << targetCar << " has left the parking. \n";
            }
            else {
                cout << "Parking lot is empty. \n";
            }
            break;
        }
        case 4: {
            cout << "\nParking lot: \n";
            stack<Car> temp = parkingLot;
            while (!temp.empty()) {
                cout << temp.top().licensePlate << "\n";
                temp.pop();
            }
            cout << "\nQueue: \n";
            queue<Car> tempQueue = carQueue;
            while (!tempQueue.empty()) {
                cout << tempQueue.front().licensePlate << "\n";
                tempQueue.pop();
            }
            break;
        }
        case 5:
            cout << "Exiting... \n";
            break;
        default:
            cout << "Invalid choice. \n";
        }
    } while (choice != 5);

    return 0;
}