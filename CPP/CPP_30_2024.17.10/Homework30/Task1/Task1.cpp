#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ��������� ��� ��������� ��������������
struct Violation {
    string description; // ���� ��������������
    double fineAmount;  // ���� ������
};

// ��������� ��� ����� ������
struct Node {
    string carNumber;            // ����� ������ (����)
    vector<Violation> violations; // ������ �������������
    Node* left;                  // ˳��� �������
    Node* right;                 // ������ �������

    // ����������� ��� ��������� ������ �����
    Node(string carNumber) : carNumber(carNumber), left(nullptr), right(nullptr) {}
};

// ���� ��� ������ � �������
class DAI {
private:
    Node* root; // ����� ������

    // �������� ������� ��� ��������� ��������������
    void insertViolation(Node*& node, const string& carNumber, const Violation& violation) {
        if (node == nullptr) {
            node = new Node(carNumber); // ��������� ����� �����, ���� ���� ����
            node->violations.push_back(violation); // ������ ��������������
        }
        else if (carNumber < node->carNumber) {
            insertViolation(node->left, carNumber, violation); // ���������� ������ � ��� ��������
        }
        else if (carNumber > node->carNumber) {
            insertViolation(node->right, carNumber, violation); // ���������� ������ � ����� ��������
        }
        else {
            // ���� ����� ������ ��� ���� � �����, ������ �������������� � ������
            node->violations.push_back(violation);
        }
    }

    // �������� ������� ��� ����� ��� ����� ������
    void printAll(Node* node) const {
        if (node != nullptr) {
            // �������� ������� ��� ��������
            printAll(node->left);
            // ������� �������� �����
            cout << "Car Number: " << node->carNumber << endl;
            for (const auto& violation : node->violations) {
                cout << "Violation: " << violation.description << ", Fine: " << violation.fineAmount << endl;
            }
            // ���� ������� ����� ��������
            printAll(node->right);
        }
    }

    // �������� ������� ��� ������ � ����� ����� �� �������� ������ ������
    void printByCarNumber(Node* node, const string& carNumber) const {
        if (node == nullptr) {
            cout << "No data for car number " << carNumber << endl;
            return;
        }
        if (carNumber < node->carNumber) {
            printByCarNumber(node->left, carNumber); // ������ � ����� �������
        }
        else if (carNumber > node->carNumber) {
            printByCarNumber(node->right, carNumber); // ������ � ������� �������
        }
        else {
            // ���� �������, ������� ������ �������������
            cout << "Car Number: " << node->carNumber << endl;
            for (const auto& violation : node->violations) {
                cout << "Violation: " << violation.description << ", Fine: " << violation.fineAmount << endl;
            }
        }
    }

    // �������� ������� ��� ����� ����� �� ��������� ������ �����
    void printInRange(Node* node, const string& startCarNumber, const string& endCarNumber) const {
        if (node == nullptr) return;

        // ���� �������� ����� � ����� ��������, ������� ����
        if (node->carNumber >= startCarNumber && node->carNumber <= endCarNumber) {
            cout << "Car Number: " << node->carNumber << endl;
            for (const auto& violation : node->violations) {
                cout << "Violation: " << violation.description << ", Fine: " << violation.fineAmount << endl;
            }
        }

        // ���� ����� ������ ������ �� startCarNumber, ���������� ��� ��������
        if (node->carNumber > startCarNumber) {
            printInRange(node->left, startCarNumber, endCarNumber);
        }

        // ���� ����� ������ ������ �� endCarNumber, ���������� ����� ��������
        if (node->carNumber < endCarNumber) {
            printInRange(node->right, startCarNumber, endCarNumber);
        }
    }

public:
    // ����������� ��� ��������� ������
    DAI() : root(nullptr) {}

    // ������� ��� ��������� ������ ��������������
    void addViolation(const string& carNumber, const Violation& violation) {
        insertViolation(root, carNumber, violation);
    }

    // ������� ��� ����� ��� �����
    void printAll() const {
        printAll(root);
    }

    // ������� ��� ����� ����� �� ������� ������� ������
    void printByCarNumber(const string& carNumber) const {
        printByCarNumber(root, carNumber);
    }

    // ������� ��� ����� ����� �� ��������� ������ �����
    void printInRange(const string& startCarNumber, const string& endCarNumber) const {
        printInRange(root, startCarNumber, endCarNumber);
    }
};

int main() {
    DAI database;

    // ��������� �������������
    database.addViolation("AA1234BB", { "Speeding", 500.0 });
    database.addViolation("BB5678CC", { "Parking violation", 100.0 });
    database.addViolation("AA1234BB", { "Red light violation", 300.0 });
    database.addViolation("CC9101DD", { "Driving without license", 1000.0 });

    // ������ ���� ���� �����
    cout << "Full Database:" << endl;
    database.printAll();
    cout << endl;

    // ���� ����� �� ������� ������� ������
    cout << "Data for car number AA1234BB:" << endl;
    database.printByCarNumber("AA1234BB");
    cout << endl;

    // ���� ����� �� ��������� ������
    cout << "Data for car numbers between AA1000AA and BB6000BB:" << endl;
    database.printInRange("AA1000AA", "BB6000BB");

    return 0;
}