#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Reservoir {
private:
    string name;
    double width;
    double length;
    double maxDepth;
    string type;

public:
    // ����������� �� �������������
    Reservoir() : name("Unknown"), width(0), length(0), maxDepth(0), type("Unknown") {}

    // ���������������� �����������
    explicit Reservoir(const string& name, double width, double length, double maxDepth, const string& type)
        : name(name), width(width), length(length), maxDepth(maxDepth), type(type) {}

    // ����������� ���������
    Reservoir(const Reservoir& other)
        : name(other.name), width(other.width), length(other.length), maxDepth(other.maxDepth), type(other.type) {}

    ~Reservoir() {}

    // ����� ��� ���������� ��'��� �������
    double calculateVolume() const {
        return width * length * maxDepth;
    }

    // ����� ��� ���������� ����� ����� �������
    double calculateSurfaceArea() const {
        return width * length;
    }

    // ����� ��� ��������, �� � ������� ������ ����
    bool isSameType(const Reservoir& other) const {
        return type == other.type;
    }

    // ����� ��� ��������� ����� ����� ������� � ������ ������ ����
    bool hasLargerSurfaceAreaThan(const Reservoir& other) const {
        return isSameType(other) && calculateSurfaceArea() > other.calculateSurfaceArea();
    }

    // ������
    void setName(const string& name) { this->name = name; }
    void setWidth(double width) { this->width = width; }
    void setLength(double length) { this->length = length; }
    void setMaxDepth(double maxDepth) { this->maxDepth = maxDepth; }
    void setType(const string& type) { this->type = type; }

    // ������
    string getName() const { return name; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getMaxDepth() const { return maxDepth; }
    string getType() const { return type; }

    // ����� ��� ����������� ���������� ��� �������
    void display() const {
        cout << "Reservoir Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Width: " << width << " meters" << endl;
        cout << "Length: " << length << " meters" << endl;
        cout << "Max Depth: " << maxDepth << " meters" << endl;
        cout << "Surface Area: " << calculateSurfaceArea() << " sq. meters" << endl;
        cout << "Volume: " << calculateVolume() << " cubic meters" << endl;
    }
};

// ���� ��� ��������� ��������� ������� ��'���� Reservoir
class ReservoirManager {
private:
    vector<Reservoir> reservoirs;

public:
    void addReservoir(const Reservoir& reservoir) {
        reservoirs.push_back(reservoir);
    }

    void removeReservoir(int index) {
        if (index >= 0 && index < reservoirs.size()) {
            reservoirs.erase(reservoirs.begin() + index);
        }
        else {
            cout << "Invalid index!" << endl;
        }
    }

    // ����� ��� ����������� ��� ������
    void displayAll() const {
        for (const auto& reservoir : reservoirs) {
            reservoir.display();
            cout << "-----------------" << endl;
        }
    }

    // ����� ��� ���������� ����� ��� ������� � ��������� ����
    void saveToTextFile(const string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& reservoir : reservoirs) {
                outFile << reservoir.getName() << ","
                    << reservoir.getType() << ","
                    << reservoir.getWidth() << ","
                    << reservoir.getLength() << ","
                    << reservoir.getMaxDepth() << endl;
            }
            outFile.close();
            cout << "Data saved to " << filename << endl;
        }
        else {
            cout << "Error opening file!" << endl;
        }
    }

    // ����� ��� ���������� ����� ��� ������� � ������� ����
    void saveToBinaryFile(const string& filename) const {
        ofstream outFile(filename, ios::binary);
        if (outFile.is_open()) {
            for (const auto& reservoir : reservoirs) {
                int nameSize = static_cast<int>(reservoir.getName().size());
                outFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(int));
                outFile.write(reservoir.getName().data(), nameSize);
                /*outFile.write(reinterpret_cast<const char*>(&reservoir.getWidth()), sizeof(double));
                outFile.write(reinterpret_cast<const char*>(&reservoir.getLength()), sizeof(double));
                outFile.write(reinterpret_cast<const char*>(&reservoir.getMaxDepth()), sizeof(double));*/
                int typeSize = static_cast<int>(reservoir.getType().size());
                outFile.write(reinterpret_cast<const char*>(&typeSize), sizeof(int));
                outFile.write(reservoir.getType().data(), typeSize);
            }
            outFile.close();
            cout << "Data saved to " << filename << endl;
        }
        else {
            cout << "Error opening file!" << endl;
        }
    }
};

int main() {
    ReservoirManager manager;

    // ��������� ������ ������
    manager.addReservoir(Reservoir("Lake Michigan", 307, 494, 281, "Lake"));
    manager.addReservoir(Reservoir("Black Sea", 1000, 4000, 2212, "Sea"));
    manager.addReservoir(Reservoir("Swimming Pool", 25, 10, 2, "Pool")); 

    // ³���������� ��� ������
    manager.displayAll();

    // ���������� � ��������� � ������� �����
    manager.saveToTextFile("reservoirs.txt");
    manager.saveToBinaryFile("reservoirs.bin");

    return 0;
}