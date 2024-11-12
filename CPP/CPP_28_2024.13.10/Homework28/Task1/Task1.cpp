#include <iostream>
using namespace std;

// Описуємо структуру вузла для однозв'язного списку
struct Node {
    int data;  // Дані які зберігаються у вузлі
    Node* next;  // Вказівник на наступний вузол у списку

    // Конструктор для ініціалізації вузла
    Node(int val) : data(val), next(nullptr) {}
};

// Описуємо клас Stack (Стек)
class Stack {
private:
    Node* topNode;  // Вказівник на верхній елемент стека
    int size;  // Змінна для відстеження розміру стека

public:
    // Конструктор
    Stack() : topNode(nullptr), size(0) {}

    // Деструктор для очищення пам'яті
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Перевірка, чи порожній стек
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Отримання розміру стека
    int getSize() {
        return size;
    }

    // Додавання елемента в стек
    void push(int value) {
        // Створюємо новий вузол і задаємо йому значення
        Node* newNode = new Node(value);

        // Зв'язуємо новий вузол з поточним верхнім елементом
        newNode->next = topNode;
        topNode = newNode;

        // Збільшуємо розмір стека
        size++;
    }

    // Видалення верхнього елемента зі стека
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop!" << endl;
            return;
        }

        Node* temp = topNode;  // Тимчасово зберігаємо поточний верхній елемент
        topNode = topNode->next;  // Переміщаємо вказівник на наступний елемент
        delete temp;  // Вивільняємо пам'ять, яку займав видалений елемент

        // Зменшуємо розмір стека
        size--;
    }

    // Отримання верхнього елемента стека без його видалення
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty, no top element!" << endl;
            return -1;  // Повертаємо некоректне значення для позначення помилки
        }
        return topNode->data;
    }

    // Виведення всіх елементів стека
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

    // Додаємо елементи в стек
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack after pushing 10, 20, 30:" << endl;
    stack.print();

    // Перевіряємо верхній елемент
    cout << "Top element: " << stack.top() << endl;

    // Видаляємо верхній елемент
    stack.pop();
    cout << "Stack after popping the top element:" << endl;
    stack.print();

    // Видаляємо решту елементів
    stack.pop();
    stack.pop();
    cout << "Stack after popping all elements:" << endl;
    stack.print();

    return 0;
}