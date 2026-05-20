#include <iostream>

using namespace std;


int** createMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; 
    }
    delete[] matrix;
}

int main() {
    int rows, cols;
    cout << "string and stolbec: ";
    cin >> rows >> cols;

    int** matrix = createMatrix(rows, cols);

    for (int i = 0; i < rows; i++) { //заполняем номер строки умноженная на номер столбца
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * j;
        }
    }


    cout << "Matrix " << rows << "x" << cols << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";  //выравниваем
        }
        cout << endl;
    }

    deleteMatrix(matrix, rows);

    return 0;
}