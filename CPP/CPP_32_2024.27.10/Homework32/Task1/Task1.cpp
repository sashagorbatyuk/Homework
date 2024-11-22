#include <iostream>
#include <stdexcept>

using namespace std;

// Клас вузла двозв'язного списку
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Клас двозв'язного списку
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Додавання елемента в кінець списку
    void Append(int value) {
        try {
            Node* newNode = new Node(value);
            if (!head) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        catch (const bad_alloc& e) {
            throw runtime_error("Memory allocation failed while appending.");
        }
    }

    // Видалення елемента з початку списку
    void RemoveFront() {
        if (!head) {
            throw runtime_error("Attempt to remove from an empty list.");
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    // Виведення елементів списку
    void Display() const {
        if (!head) {
            throw runtime_error("List is empty.");
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Демонстрація роботи
int main() {
    DoublyLinkedList list;

    try {
        list.Append(10);
        list.Append(20);
        list.Display();

        list.RemoveFront();
        list.Display();

        list.RemoveFront();
        list.RemoveFront(); // Спроба видалення з порожнього списку
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}