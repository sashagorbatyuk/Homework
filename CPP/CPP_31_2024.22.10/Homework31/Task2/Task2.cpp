#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

// ����������� ���� ��� �����
class Shape {
public:
    virtual void Show() const = 0;  // ���� ���������� ��� ������
    virtual void Save(ofstream& out) const = 0; // ���������� ������ � ����
    virtual void Load(ifstream& in) = 0;        // ������������ ������ � �����
    virtual ~Shape() {}
};

// ���� ��� ��������
class Square : public Shape {
private:
    double x, y; // ���������� ��������� ����� ����
    double side; // ������� �������
public:
    Square(double x = 0, double y = 0, double side = 0) : x(x), y(y), side(side) {}

    void Show() const override {
        cout << "Square: Top-left (" << x << ", " << y << "), Side = " << side << endl;
    }

    void Save(ofstream& out) const override {
        out << "Square " << x << " " << y << " " << side << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> side;
    }
};

// ���� ��� ������������
class Rectangle : public Shape {
private:
    double x, y; // ���������� ��������� ����� ����
    double width, height; // ������ ������������
public:
    Rectangle(double x = 0, double y = 0, double width = 0, double height = 0)
        : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        cout << "Rectangle: Top-left (" << x << ", " << y << "), Width = " << width << ", Height = " << height << endl;
    }

    void Save(ofstream& out) const override {
        out << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> width >> height;
    }
};

// ���� ��� ��
class Circle : public Shape {
private:
    double cx, cy; // ���������� ������
    double radius; // �����
public:
    Circle(double cx = 0, double cy = 0, double radius = 0) : cx(cx), cy(cy), radius(radius) {}

    void Show() const override {
        cout << "Circle: Center (" << cx << ", " << cy << "), Radius = " << radius << endl;
    }

    void Save(ofstream& out) const override {
        out << "Circle " << cx << " " << cy << " " << radius << endl;
    }

    void Load(ifstream& in) override {
        in >> cx >> cy >> radius;
    }
};

// ���� ��� �����
class Ellipse : public Shape {
private:
    double x, y; // ���������� ��������� ����� ���� ��������� ������������
    double width, height; // ������ ��������� ������������
public:
    Ellipse(double x = 0, double y = 0, double width = 0, double height = 0)
        : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        cout << "Ellipse: Bounding box top-left (" << x << ", " << y << "), Width = " << width << ", Height = " << height << endl;
    }

    void Save(ofstream& out) const override {
        out << "Ellipse " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> width >> height;
    }
};

// ������� �������
int main() {
    // ����� �����
    vector<shared_ptr<Shape>> shapes;
    shapes.push_back(make_shared<Square>(1, 2, 5));
    shapes.push_back(make_shared<Rectangle>(3, 4, 6, 7));
    shapes.push_back(make_shared<Circle>(5, 5, 3));
    shapes.push_back(make_shared<Ellipse>(2, 3, 8, 6));

    // ���������� ����� � ����
    ofstream outFile("shapes.txt");
    for (const auto& shape : shapes) {
        shape->Save(outFile);
    }
    outFile.close();

    // ������������ ����� � �����
    vector<shared_ptr<Shape>> loadedShapes;
    ifstream inFile("shapes.txt");
    string shapeType;
    while (inFile >> shapeType) {
        if (shapeType == "Square") {
            auto square = make_shared<Square>();
            square->Load(inFile);
            loadedShapes.push_back(square);
        }
        else if (shapeType == "Rectangle") {
            auto rectangle = make_shared<Rectangle>();
            rectangle->Load(inFile);
            loadedShapes.push_back(rectangle);
        }
        else if (shapeType == "Circle") {
            auto circle = make_shared<Circle>();
            circle->Load(inFile);
            loadedShapes.push_back(circle);
        }
        else if (shapeType == "Ellipse") {
            auto ellipse = make_shared<Ellipse>();
            ellipse->Load(inFile);
            loadedShapes.push_back(ellipse);
        }
    }
    inFile.close();

    // ��������� ������������ �����
    cout << "Loaded Shapes:" << endl;
    for (const auto& shape : loadedShapes) {
        shape->Show();
    }

    return 0;
}