#include <iostream>
using namespace std;

struct Node {
    int data;   // ��� �����
    Node* next; // �������� �� ��������� �����

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // �����������
    LinkedList() : head(nullptr) {}

    // ����������
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;  // ��������� �����
            current = nextNode;
        }
    }

    // ��������� �������� � ����� ������
    void append(int val) {
        Node* newNode = new Node(val);  // ��������� ������ �����
        if (!head) {
            head = newNode;  // ���� ������ �������, ����� ����� ��� �������
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;  // ������� �� ���������� �����
            }
            current->next = newNode;  // ��������� ������ ����� � �����
        }
    }

    // ��������� ������ �� �����
    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";  // ��������� ����� ��������� �����
            current = current->next;      // ������� �� ���������� �����
        }
        cout << endl;
    }

    // ���������� ������
    LinkedList clone() const {
        LinkedList newList;
        Node* current = head;
        while (current) {
            newList.append(current->data);  // ��������� �������� � ����� ������
            current = current->next;
        }
        return newList;
    }

    // �������������� ��������� '+' ��� ��'������� ���� ������
    LinkedList operator+(const LinkedList& other) const {
        LinkedList newList;
        Node* current = head;
        while (current) {
            newList.append(current->data);  // ������� �������� ������� ������
            current = current->next;
        }
        current = other.head;
        while (current) {
            newList.append(current->data);  // ������� �������� ������� ������
            current = current->next;
        }
        return newList;
    }

    // �������������� ��������� '*' ��� �������� ���� ������
    LinkedList operator*(const LinkedList& other) const {
        LinkedList intersection;  // ������ ��� ��������� ��������
        Node* current = head;
        while (current) {
            Node* otherCurrent = other.head;
            while (otherCurrent) {
                if (current->data == otherCurrent->data) {  // ���� �������� ����������
                    intersection.append(current->data);  // ������ ������� � �������
                    break;  // ���������� �� ���������� �������� ������� ������
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }
        return intersection;
    }

    // ����� ��� ������ ������ (��� ����������)
    Node* getHead() const {
        return head;
    }
};

int main() {
    LinkedList list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    LinkedList list2;
    list2.append(2);
    list2.append(3);
    list2.append(4);

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    // ���������� list1
    LinkedList list1Clone = list1.clone();
    cout << "Cloned List 1: ";
    list1Clone.print();

    // ��'������� list1 �� list2
    LinkedList unionList = list1 + list2;
    cout << "Union (List 1 + List 2): ";
    unionList.print();

    // ������� list1 �� list2
    LinkedList intersectionList = list1 * list2;
    cout << "Intersection (List 1 * List 2): ";
    intersectionList.print();

    return 0;
}