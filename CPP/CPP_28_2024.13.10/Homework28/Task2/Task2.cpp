#include <iostream>
using namespace std;

struct Node {
    int data;   // Дані вузла
    Node* next; // Покажчик на наступний вузол

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Конструктор
    LinkedList() : head(nullptr) {}

    // Деструктор
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;  // Видалення вузла
            current = nextNode;
        }
    }

    // Додавання елемента в кінець списку
    void append(int val) {
        Node* newNode = new Node(val);  // Створення нового вузла
        if (!head) {
            head = newNode;  // Якщо список порожній, новий вузол стає головою
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;  // Перехід до останнього вузла
            }
            current->next = newNode;  // Додавання нового вузла в кінець
        }
    }

    // Виведення списку на екран
    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";  // Виведення даних поточного вузла
            current = current->next;      // Перехід до наступного вузла
        }
        cout << endl;
    }

    // Клонування списку
    LinkedList clone() const {
        LinkedList newList;
        Node* current = head;
        while (current) {
            newList.append(current->data);  // Копіювання елементів в новий список
            current = current->next;
        }
        return newList;
    }

    // Перевантаження оператора '+' для об'єднання двох списків
    LinkedList operator+(const LinkedList& other) const {
        LinkedList newList;
        Node* current = head;
        while (current) {
            newList.append(current->data);  // Копіюємо елементи першого списку
            current = current->next;
        }
        current = other.head;
        while (current) {
            newList.append(current->data);  // Копіюємо елементи другого списку
            current = current->next;
        }
        return newList;
    }

    // Перевантаження оператора '*' для перетину двох списків
    LinkedList operator*(const LinkedList& other) const {
        LinkedList intersection;  // Список для зберігання перетину
        Node* current = head;
        while (current) {
            Node* otherCurrent = other.head;
            while (otherCurrent) {
                if (current->data == otherCurrent->data) {  // Якщо елементи співпадають
                    intersection.append(current->data);  // Додаємо елемент у перетин
                    break;  // Переходимо до наступного елемента першого списку
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }
        return intersection;
    }

    // Гетер для голови списку (для тестування)
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

    // Клонування list1
    LinkedList list1Clone = list1.clone();
    cout << "Cloned List 1: ";
    list1Clone.print();

    // Об'єднання list1 та list2
    LinkedList unionList = list1 + list2;
    cout << "Union (List 1 + List 2): ";
    unionList.print();

    // Перетин list1 та list2
    LinkedList intersectionList = list1 * list2;
    cout << "Intersection (List 1 * List 2): ";
    intersectionList.print();

    return 0;
}