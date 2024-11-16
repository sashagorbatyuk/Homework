#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Структура для зберігання правопорушення
struct Violation {
    string description; // Опис правопорушення
    double fineAmount;  // Сума штрафу
};

// Структура для вузла дерева
struct Node {
    string carNumber;            // Номер машини (ключ)
    vector<Violation> violations; // Список правопорушень
    Node* left;                  // Лівий нащадок
    Node* right;                 // Правий нащадок

    // Конструктор для створення нового вузла
    Node(string carNumber) : carNumber(carNumber), left(nullptr), right(nullptr) {}
};

// Клас для роботи з деревом
class DAI {
private:
    Node* root; // Корінь дерева

    // Допоміжна функція для додавання правопорушення
    void insertViolation(Node*& node, const string& carNumber, const Violation& violation) {
        if (node == nullptr) {
            node = new Node(carNumber); // Створюємо новий вузол, якщо його немає
            node->violations.push_back(violation); // Додаємо правопорушення
        }
        else if (carNumber < node->carNumber) {
            insertViolation(node->left, carNumber, violation); // Рекурсивно додаємо в ліве піддерево
        }
        else if (carNumber > node->carNumber) {
            insertViolation(node->right, carNumber, violation); // Рекурсивно додаємо в праве піддерево
        }
        else {
            // Якщо номер машини вже існує в дереві, додаємо правопорушення в список
            node->violations.push_back(violation);
        }
    }

    // Допоміжна функція для друку всіх даних дерева
    void printAll(Node* node) const {
        if (node != nullptr) {
            // Спочатку друкуємо ліве піддерево
            printAll(node->left);
            // Друкуємо поточний вузол
            cout << "Car Number: " << node->carNumber << endl;
            for (const auto& violation : node->violations) {
                cout << "Violation: " << violation.description << ", Fine: " << violation.fineAmount << endl;
            }
            // Потім друкуємо праве піддерево
            printAll(node->right);
        }
    }

    // Допоміжна функція для пошуку і друку даних по заданому номеру машини
    void printByCarNumber(Node* node, const string& carNumber) const {
        if (node == nullptr) {
            cout << "No data for car number " << carNumber << endl;
            return;
        }
        if (carNumber < node->carNumber) {
            printByCarNumber(node->left, carNumber); // Шукаємо в лівому піддереві
        }
        else if (carNumber > node->carNumber) {
            printByCarNumber(node->right, carNumber); // Шукаємо в правому піддереві
        }
        else {
            // Якщо знайшли, друкуємо список правопорушень
            cout << "Car Number: " << node->carNumber << endl;
            for (const auto& violation : node->violations) {
                cout << "Violation: " << violation.description << ", Fine: " << violation.fineAmount << endl;
            }
        }
    }

    // Допоміжна функція для друку даних за діапазоном номерів машин
    void printInRange(Node* node, const string& startCarNumber, const string& endCarNumber) const {
        if (node == nullptr) return;

        // Якщо поточний номер в межах діапазону, друкуємо його
        if (node->carNumber >= startCarNumber && node->carNumber <= endCarNumber) {
            cout << "Car Number: " << node->carNumber << endl;
            for (const auto& violation : node->violations) {
                cout << "Violation: " << violation.description << ", Fine: " << violation.fineAmount << endl;
            }
        }

        // Якщо номер машини більший за startCarNumber, перевіряємо ліве піддерево
        if (node->carNumber > startCarNumber) {
            printInRange(node->left, startCarNumber, endCarNumber);
        }

        // Якщо номер машини менший за endCarNumber, перевіряємо праве піддерево
        if (node->carNumber < endCarNumber) {
            printInRange(node->right, startCarNumber, endCarNumber);
        }
    }

public:
    // Конструктор для створення дерева
    DAI() : root(nullptr) {}

    // Функція для додавання нового правопорушення
    void addViolation(const string& carNumber, const Violation& violation) {
        insertViolation(root, carNumber, violation);
    }

    // Функція для друку всіх даних
    void printAll() const {
        printAll(root);
    }

    // Функція для друку даних за заданим номером машини
    void printByCarNumber(const string& carNumber) const {
        printByCarNumber(root, carNumber);
    }

    // Функція для друку даних за діапазоном номерів машин
    void printInRange(const string& startCarNumber, const string& endCarNumber) const {
        printInRange(root, startCarNumber, endCarNumber);
    }
};

int main() {
    DAI database;

    // Додавання правопорушень
    database.addViolation("AA1234BB", { "Speeding", 500.0 });
    database.addViolation("BB5678CC", { "Parking violation", 100.0 });
    database.addViolation("AA1234BB", { "Red light violation", 300.0 });
    database.addViolation("CC9101DD", { "Driving without license", 1000.0 });

    // Повний друк бази даних
    cout << "Full Database:" << endl;
    database.printAll();
    cout << endl;

    // Друк даних за заданим номером машини
    cout << "Data for car number AA1234BB:" << endl;
    database.printByCarNumber("AA1234BB");
    cout << endl;

    // Друк даних за діапазоном номерів
    cout << "Data for car numbers between AA1000AA and BB6000BB:" << endl;
    database.printInRange("AA1000AA", "BB6000BB");

    return 0;
}