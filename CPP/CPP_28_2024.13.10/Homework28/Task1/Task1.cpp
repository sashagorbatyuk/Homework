#include <iostream>
using namespace std;

// ������� ��������� ����� ��� ������'������ ������
struct Node {
    int data;  // ��� �� ����������� � ����
    Node* next;  // �������� �� ��������� ����� � ������

    // ����������� ��� ����������� �����
    Node(int val) : data(val), next(nullptr) {}
};

// ������� ���� Stack (����)
class Stack {
private:
    Node* topNode;  // �������� �� ������ ������� �����
    int size;  // ����� ��� ���������� ������ �����

public:
    // �����������
    Stack() : topNode(nullptr), size(0) {}

    // ���������� ��� �������� ���'��
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // ��������, �� ������� ����
    bool isEmpty() {
        return topNode == nullptr;
    }

    // ��������� ������ �����
    int getSize() {
        return size;
    }

    // ��������� �������� � ����
    void push(int value) {
        // ��������� ����� ����� � ������ ���� ��������
        Node* newNode = new Node(value);

        // ��'����� ����� ����� � �������� ������ ���������
        newNode->next = topNode;
        topNode = newNode;

        // �������� ����� �����
        size++;
    }

    // ��������� ��������� �������� � �����
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop!" << endl;
            return;
        }

        Node* temp = topNode;  // ��������� �������� �������� ������ �������
        topNode = topNode->next;  // ��������� �������� �� ��������� �������
        delete temp;  // ���������� ���'���, ��� ������ ��������� �������

        // �������� ����� �����
        size--;
    }

    // ��������� ��������� �������� ����� ��� ���� ���������
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty, no top element!" << endl;
            return -1;  // ��������� ���������� �������� ��� ���������� �������
        }
        return topNode->data;
    }

    // ��������� ��� �������� �����
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* current = topNode;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // ������ �������� � ����
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack after pushing 10, 20, 30:" << endl;
    stack.print();

    // ���������� ������ �������
    cout << "Top element: " << stack.top() << endl;

    // ��������� ������ �������
    stack.pop();
    cout << "Stack after popping the top element:" << endl;
    stack.print();

    // ��������� ����� ��������
    stack.pop();
    stack.pop();
    cout << "Stack after popping all elements:" << endl;
    stack.print();

    return 0;
}