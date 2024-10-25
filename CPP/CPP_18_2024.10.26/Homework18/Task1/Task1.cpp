#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Клас Contact для зберігання даних про абонента
class Contact {
private:
    char* name;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    // Конструктор з параметрами
    Contact(const char* name, const string& homePhone, const string& workPhone,
        const string& mobilePhone, const string& additionalInfo)
        : homePhone(homePhone), workPhone(workPhone), mobilePhone(mobilePhone),
        additionalInfo(additionalInfo) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Конструктор копіювання
    Contact(const Contact& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        homePhone = other.homePhone;
        workPhone = other.workPhone;
        mobilePhone = other.mobilePhone;
        additionalInfo = other.additionalInfo;
    }

    ~Contact() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    // Функція для відображення даних абонента
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
        cout << "Additional Info: " << additionalInfo << endl;
    }

    // Оператор присвоєння
    Contact& operator=(const Contact& other) {
        if (this == &other) return *this;

        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        homePhone = other.homePhone;
        workPhone = other.workPhone;
        mobilePhone = other.mobilePhone;
        additionalInfo = other.additionalInfo;

        return *this;
    }

    // Запис контакту в файл
    void save(ofstream& outFile) const {
        size_t nameLength = strlen(name);
        outFile.write((char*)&nameLength, sizeof(nameLength));
        outFile.write(name, nameLength);
        outFile << homePhone << '\n' << workPhone << '\n' << mobilePhone << '\n' << additionalInfo << '\n';
    }

    // Завантаження контакту з файлу
    void load(ifstream& inFile) {
        size_t nameLength;
        inFile.read((char*)&nameLength, sizeof(nameLength));
        delete[] name;
        name = new char[nameLength + 1];
        inFile.read(name, nameLength);
        name[nameLength] = '\0';

        getline(inFile, homePhone);
        getline(inFile, workPhone);
        getline(inFile, mobilePhone);
        getline(inFile, additionalInfo);
    }
};

// Клас PhoneBook для керування контактами
class PhoneBook {
private:
    vector<Contact> contacts;

public:
    // Додавання нового абонента
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    // Видалення абонента за ПІБ
    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (name == it->getName()) {
                contacts.erase(it);
                cout << "Contact deleted successfully." << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    // Пошук абонента за ПІБ
    void searchContact(const string& name) const {
        for (const auto& contact : contacts) {
            if (name == contact.getName()) {
                contact.display();
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    // Відображення всіх абонентів
    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "No contacts to display." << endl;
            return;
        }
        for (const auto& contact : contacts) {
            contact.display();
            cout << "--------------------" << endl;
        }
    }

    // Збереження контактів у файл
    void saveToFile(const string& filename) const {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cout << "Error opening file for saving." << endl;
            return;
        }
        for (const auto& contact : contacts) {
            contact.save(outFile);
        }
        outFile.close();
        cout << "Contacts saved successfully." << endl;
    }

    // Завантаження контактів з файлу
    void loadFromFile(const string& filename) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "Error opening file for loading." << endl;
            return;
        }
        contacts.clear();
        while (inFile.peek() != EOF) {
            Contact contact("", "", "", "", "");
            contact.load(inFile);
            contacts.push_back(contact);
        }
        inFile.close();
        cout << "Contacts loaded successfully." << endl;
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    string name, homePhone, workPhone, mobilePhone, additionalInfo;

    while (true) {
        cout << "\nPhone Book Menu:\n1. Add Contact\n2. Delete Contact\n3. Search Contact\n4. Display All Contacts\n5. Save Contacts to File\n6. Load Contacts from File\n7. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Home Phone: ";
            getline(cin, homePhone);
            cout << "Enter Work Phone: ";
            getline(cin, workPhone);
            cout << "Enter Mobile Phone: ";
            getline(cin, mobilePhone);
            cout << "Enter Additional Info: ";
            getline(cin, additionalInfo);
            phoneBook.addContact(Contact(name.c_str(), homePhone, workPhone, mobilePhone, additionalInfo));
            break;

        case 2:
            cout << "Enter Name to Delete: ";
            getline(cin, name);
            phoneBook.deleteContact(name);
            break;

        case 3:
            cout << "Enter Name to Search: ";
            getline(cin, name);
            phoneBook.searchContact(name);
            break;

        case 4:
            phoneBook.displayAllContacts();
            break;

        case 5:
            phoneBook.saveToFile("contacts.dat");
            break;

        case 6:
            phoneBook.loadFromFile("contacts.dat");
            break;

        case 7:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}
