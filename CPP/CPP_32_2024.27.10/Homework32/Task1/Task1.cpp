#include <iostream>
#include <stdexcept>

using namespace std;

// ���� ����� �����'������ ������
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// ���� �����'������ ������
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

    // ��������� �������� � ����� ������
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

    // ��������� �������� � ������� ������
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

    // ��������� �������� ������
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

// ������������ ������
int main() {
    DoublyLinkedList list;

    try {
        list.Append(10);
        list.Append(20);
        list.Display();

        list.RemoveFront();
        list.Display();

        list.RemoveFront();
        list.RemoveFront(); // ������ ��������� � ���������� ������
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}