#include <iostream>

using namespace std;

void printChessBoard(int cellSize, int boardSize) {
    for (int row = 0; row < boardSize; ++row) {
        for (int i = 0; i < cellSize; ++i) {
            for (int col = 0; col < boardSize; ++col) {
                if ((row + col) % 2 == 0) {
                    for (int j = 0; j < cellSize; ++j) {
                        cout << "*";
                    }
                }
                else {
                    for (int j = 0; j < cellSize; ++j) {
                        cout << "-";
                    }
                }
            }
            cout << endl;
        }
    }
}

int main() {
    int cellSize, boardSize;

    cout << "Enter the cell size (eg 3) : ";
    cin >> cellSize;
    cout << "Enter the number of cells in a row/column (eg 8) : ";
    cin >> boardSize;

    printChessBoard(cellSize, boardSize);

    return 0;
}