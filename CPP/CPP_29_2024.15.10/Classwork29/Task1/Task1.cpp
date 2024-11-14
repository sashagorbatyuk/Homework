#include <iostream>
#include <stdexcept>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    // ����������� � ������� �������
    List(initializer_list<int> values) : List() {
        for (int value : values) {
            append(value);
        }
    }

    // ��������� �������� � ����� ������
    void append(int value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
        size++;
    }

    // �������� [] ��� ������� �� �������� �� ��������
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // ����� ��� ��������� �������� �� ���������
    void deleteByValue(int value) {
        if (size == 0) return;  // ���� ������ �������, ����� �� ������

        Node* current = head;

        // ������ �����, �� ������ ��������
        while (current) {
            if (current->data == value) {
                // ���� ����� �� ������� ������
                if (current->prev == nullptr) {
                    head = current->next;  // ��������� head
                    if (head) head->prev = nullptr;  // ���� ������ �� �������, ��������� prev ��� ������ head
                }
                // ���� ����� � ���� ������
                else if (current->next == nullptr) {
                    tail = current->prev;  // ��������� tail
                    if (tail) tail->next = nullptr;  // ���� ������ �� �������, ��������� next ��� ������ tail
                }
                // ���� ����� ����������� �� ����� ������ �������
                else {
                    current->prev->next = current->next;  // ��'����� ��������� ����� � ���������
                    current->next->prev = current->prev;  // ��'����� ��������� ����� � ���������
                }
                delete current;  // ��������� �����
                size--;  // �������� ����� ������
                return;  // ��������� ��������
            }
            current = current->next;
        }
    }

    // ����� ��� ��������� ������
    void printList() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // ����� ��� ��������� ������ � ����������� �������
    void printListReverse() const {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // ����� ��� ��������� ������ ������
    int getSize() const {
        return size;
    }

    // ���������� ��� ��������� ���'��
    ~List() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    try {
        // ��������� ������ �� �������
        List list = { 1, 2, 3, 4, 5 };
        cout << "List: ";
        list.printList();

        // ��������� ������� �� ���������
        list.deleteByValue(4);
        cout << "After deleting value 4: ";
        list.printList();

        // ��������� �������� �� ������� ������
        list.deleteByValue(1);
        cout << "After deleting value 1 (head): ";
        list.printList();

        // ��������� �������� � ���� ������
        list.deleteByValue(5);
        cout << "After deleting value 5 (tail): ";
        list.printList();

        // ��������� �������� � ������, ���� �� � �������
        list.deleteByValue(3);
        cout << "After deleting value 3 (middle): ";
        list.printList();

        // ��������� �� ������ ��������
        list.append(6);
        list.append(7);
        cout << "After adding 6 and 7: ";
        list.printList();

        // ��������� ������ � ���������� �������
        cout << "List in reverse order: ";
        list.printListReverse();

        // ������������ ��������� [] ��� ������� �� ��������
        cout << "Element at index 1: " << list[1] << endl;

        // ��������� ������ ������
        cout << "Size of the list: " << list.getSize() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
