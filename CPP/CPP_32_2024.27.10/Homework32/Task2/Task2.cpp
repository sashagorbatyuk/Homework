#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

// ������� ����-�������
class BaseException : public exception {
protected:
    string message;
public:
    BaseException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// ���� ��� ������� ������������ �������
class MathException : public BaseException {
public:
    MathException(const string& msg) : BaseException("Math Error: " + msg) {}
};

// ���� ��� ������� ������ �� ����
class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero is not allowed.") {}
};

// ���� ��� ������� ������� ������ � �������
class FileException : public BaseException {
public:
    FileException(const string& msg) : BaseException("File Error: " + msg) {}
};

// ���� ��� ������� ������� ���'��
class MemoryException : public BaseException {
public:
    MemoryException() : BaseException("Memory allocation failed.") {}
};

// ������������ ������ � ���������
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
        int* largeArray = new int[1000000000000]; // ������� ���'��
        delete[] largeArray;
    }
    catch (const bad_alloc&) {
        cerr << MemoryException().what() << endl;
    }

    return 0;
}