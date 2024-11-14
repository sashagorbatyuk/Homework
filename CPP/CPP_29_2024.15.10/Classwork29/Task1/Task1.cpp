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

    // Конструктор зі списком значень
    List(initializer_list<int> values) : List() {
        for (int value : values) {
            append(value);
        }
    }

    // Додавання елемента в кінець списку
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

    // Оператор [] для доступу до елемента за індексом
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

    // Метод для видалення елемента за значенням
    void deleteByValue(int value) {
        if (size == 0) return;  // Якщо список порожній, нічого не робимо

        Node* current = head;

        // Шукаємо вузол, що містить значення
        while (current) {
            if (current->data == value) {
                // Якщо вузол на початку списку
                if (current->prev == nullptr) {
                    head = current->next;  // Оновлюємо head
                    if (head) head->prev = nullptr;  // Якщо список не порожній, оновлюємо prev для нового head
                }
                // Якщо вузол в кінці списку
                else if (current->next == nullptr) {
                    tail = current->prev;  // Оновлюємо tail
                    if (tail) tail->next = nullptr;  // Якщо список не порожній, оновлюємо next для нового tail
                }
                // Якщо вузол знаходиться між двома іншими вузлами
                else {
                    current->prev->next = current->next;  // Зв'язуємо попередній вузол з наступним
                    current->next->prev = current->prev;  // Зв'язуємо наступний вузол з попереднім
                }
                delete current;  // Видаляємо вузол
                size--;  // Зменшуємо розмір списку
                return;  // Завершуємо операцію
            }
            current = current->next;
        }
    }

    // Метод для виведення списку
    void printList() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Метод для виведення списку у зворотньому порядку
    void printListReverse() const {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Метод для отримання розміру списку
    int getSize() const {
        return size;
    }

    // Деструктор для звільнення пам'яті
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
        // Створюємо список із значень
        List list = { 1, 2, 3, 4, 5 };
        cout << "List: ";
        list.printList();

        // Видаляємо елемент за значенням
        list.deleteByValue(4);
        cout << "After deleting value 4: ";
        list.printList();

        // Видалення елемента на початку списку
        list.deleteByValue(1);
        cout << "After deleting value 1 (head): ";
        list.printList();

        // Видалення елемента в кінці списку
        list.deleteByValue(5);
        cout << "After deleting value 5 (tail): ";
        list.printList();

        // Видалення елемента зі списку, коли він в середині
        list.deleteByValue(3);
        cout << "After deleting value 3 (middle): ";
        list.printList();

        // Додавання ще кількох елементів
        list.append(6);
        list.append(7);
        cout << "After adding 6 and 7: ";
        list.printList();

        // Виведення списку у зворотному порядку
        cout << "List in reverse order: ";
        list.printListReverse();

        // Використання оператора [] для доступу до елемента
        cout << "Element at index 1: " << list[1] << endl;

        // Виведення розміру списку
        cout << "Size of the list: " << list.getSize() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
