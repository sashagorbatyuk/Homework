#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

// Базовий клас-виняток
class BaseException : public exception {
protected:
    string message;
public:
    BaseException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// Клас для обробки математичних помилок
class MathException : public BaseException {
public:
    MathException(const string& msg) : BaseException("Math Error: " + msg) {}
};

// Клас для помилок ділення на нуль
class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero is not allowed.") {}
};

// Клас для обробки помилок роботи з файлами
class FileException : public BaseException {
public:
    FileException(const string& msg) : BaseException("File Error: " + msg) {}
};

// Клас для обробки нестачі пам'яті
class MemoryException : public BaseException {
public:
    MemoryException() : BaseException("Memory allocation failed.") {}
};

// Демонстрація роботи з винятками
double Divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

void ProcessFile(const string& filename) {
    throw FileException("Unable to open file: " + filename);
}

int main() {
    try {
        cout << Divide(10, 0) << endl;
    }
    catch (const BaseException& e) {
        cerr << e.what() << endl;
    }

    try {
        ProcessFile("example.txt");
    }
    catch (const BaseException& e) {
        cerr << e.what() << endl;
    }

    try {
        int* largeArray = new int[1000000000000]; // Нестача пам'яті
        delete[] largeArray;
    }
    catch (const bad_alloc&) {
        cerr << MemoryException().what() << endl;
    }

    return 0;
}