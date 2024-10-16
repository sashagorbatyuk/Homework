#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Розробіть програму "Бібліотека". Створіть структуру "Книга" (назва, автор, видавництво, жанр). Створіть масив із 10 книг. Реалізуйте для нього такі можливості:
//Редагувати книгу;
//Друк усіх книг;
//Пошук книги за автором;
//Пошук книги за назвою;
//Сортування масиву за назвою книг;
//Сортування масиву за автором;
//Сортування масиву за видавництвом.

// Структура для зберігання інформації про книгу
struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

// Функція для друку інформації про одну книгу
void printBook(const Book& book) {
    cout << "Title: " << book.title << "\nAuthor: " << book.author
        << "\nPublisher: " << book.publisher << "\nGenre: " << book.genre << endl;
}

// Функція для редагування книги
void editBook(Book& book) {
    cout << "Enter new title: ";
    getline(cin, book.title);
    cout << "Enter new author: ";
    getline(cin, book.author);
    cout << "Enter new publisher: ";
    getline(cin, book.publisher);
    cout << "Enter new genre: ";
    getline(cin, book.genre);
}

// Функція для друку всіх книг
void printAllBooks(const Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nBook " << i + 1 << ":\n";
        printBook(books[i]);
        cout << endl;
    }
}

// Функція для пошуку книги за автором
void searchByAuthor(const Book books[], int size, const string& author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by author: " << author << endl;
    }
}

// Функція для пошуку книги за назвою
void searchByTitle(const Book books[], int size, const string& title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found with title: " << title << endl;
    }
}

// Сортування за назвою книги
void sortByTitle(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
    cout << "Books sorted by title." << endl;
}

// Сортування за автором
void sortByAuthor(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
    cout << "Books sorted by author." << endl;
}

// Сортування за видавництвом
void sortByPublisher(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
    cout << "Books sorted by publisher." << endl;
}

int main() {
    const int size = 10;
    Book books[size] = {
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", "Fiction"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopia"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Fiction"},
        {"Moby Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"},
        {"Crime and Punishment", "Fyodor Dostoevsky", "The Russian Messenger", "Psychological"},
        {"Brave New World", "Aldous Huxley", "Chatto & Windus", "Dystopia"},
        {"The Odyssey", "Homer", "Penguin Classics", "Epic"}
    };

    int choice;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Edit book\n";
        cout << "2. Print all books\n";
        cout << "3. Search book by author\n";
        cout << "4. Search book by title\n";
        cout << "5. Sort books by title\n";
        cout << "6. Sort books by author\n";
        cout << "7. Sort books by publisher\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            int bookNumber;
            cout << "Enter book number to edit (1-" << size << "): ";
            cin >> bookNumber;
            cin.ignore();
            if (bookNumber >= 1 && bookNumber <= size) {
                editBook(books[bookNumber - 1]);
            }
            else {
                cout << "Invalid book number!" << endl;
            }
            break;
        }
        case 2:
            printAllBooks(books, size);
            break;
        case 3: {
            string author;
            cout << "Enter author name: ";
            getline(cin, author);
            searchByAuthor(books, size, author);
            break;
        }
        case 4: {
            string title;
            cout << "Enter book title: ";
            getline(cin, title);
            searchByTitle(books, size, title);
            break;
        }
        case 5:
            sortByTitle(books, size);
            break;
        case 6:
            sortByAuthor(books, size);
            break;
        case 7:
            sortByPublisher(books, size);
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
