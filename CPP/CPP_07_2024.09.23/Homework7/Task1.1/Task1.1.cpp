#include <iostream>
using namespace std;

void figureA();
void figureB();
void figureC();
void figureD();
void figureE();
void figureF();
void figureG();
void figureH();
void figureI();
void figureJ();

int main() {
    int choice;

    do {
        cout << "Select a figure to display:\n";
        cout << "1. Figure A\n";
        cout << "2. Figure B\n";
        cout << "3. Figure C\n";
        cout << "4. Figure D\n";
        cout << "5. Figure E\n";
        cout << "6. Figure F\n";
        cout << "7. Figure G\n";
        cout << "8. Figure H\n";
        cout << "9. Figure I\n";
        cout << "10. Figure J\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: figureA(); break;
        case 2: figureB(); break;
        case 3: figureC(); break;
        case 4: figureD(); break;
        case 5: figureE(); break;
        case 6: figureF(); break;
        case 7: figureG(); break;
        case 8: figureH(); break;
        case 9: figureI(); break;
        case 10: figureJ(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice, try again.\n"; break;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}

void figureA() {
    cout << "Figure A:\n";
    cout << "*****\n";
    cout << " ****\n";
    cout << "  ***\n";
    cout << "   **\n";
    cout << "    *\n";
}

void figureB() {
    cout << "Figure B:\n";
    cout << "*    \n";
    cout << "**   \n";
    cout << "***  \n";
    cout << "**** \n";
    cout << "*****\n";
}

void figureC() {
    cout << "Figure C:\n";
    cout << "*****\n";
    cout << " *** \n";
    cout << "  *  \n";
    cout << "     \n";
    cout << "     \n";
}

void figureD() {
    cout << "Figure D:\n";
    cout << "     \n";
    cout << "     \n";
    cout << "  *  \n";
    cout << " *** \n";
    cout << "*****\n";
}

void figureE() {
    cout << "Figure E:\n";
    cout << "*****\n";
    cout << " *** \n";
    cout << "  *  \n";
    cout << " *** \n";
    cout << "*****\n";
}

void figureF() {
    cout << "Figure F:\n";
    cout << "*   *\n";
    cout << "** **\n";
    cout << "*****\n";
    cout << "** **\n";
    cout << "*   *\n";
}

void figureG() {
    cout << "Figure G:\n";
    cout << "*    \n";
    cout << "**   \n";
    cout << "***  \n";
    cout << "**   \n";
    cout << "*    \n";
}

void figureH() {
    cout << "Figure H:\n";
    cout << "    *\n";
    cout << "   **\n";
    cout << "  ***\n";
    cout << "   **\n";
    cout << "    *\n";
}

void figureI() {
    cout << "Figure I:\n";
    cout << "*****\n";
    cout << "**** \n";
    cout << "***  \n";
    cout << "**   \n";
    cout << "*    \n";
}

void figureJ() {
    cout << "Figure J:\n";
    cout << "    *\n";
    cout << "   **\n";
    cout << "  ***\n";
    cout << " ****\n";
    cout << "*****\n";
}
