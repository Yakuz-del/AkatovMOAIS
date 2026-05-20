#include <iostream>
#include <Windows.h>

using namespace std;

template<typename T>
T** createMatrix(int rows, int cols, T row1[], T row2[])
{
	T** matrix = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
	}

	copy(row1, row1 + cols, matrix[0]);
	copy(row2, row2 + cols, matrix[1]);

	return matrix;
}

template<typename T>
void viewMatrix(T** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>
T** transposeMatrix(T** matrix, int rows, int cols)
{
	T** newMatrix = new T* [cols];
	for (int i = 0; i < cols; i++)
	{
		newMatrix[i] = new T[rows];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newMatrix[j][i] = matrix[i][j];
		}
	}

	return newMatrix;
}

template<typename T>
void delMatrix(T** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int rows = 2;
	int cols = 3;

	// int
	int row1[] = { 1, 2, 3 };
	int row2[] = { 4, 5, 6 };

	int** matrix = createMatrix(rows, cols, row1, row2);
	viewMatrix(matrix, rows, cols);
	int** newMatrix = transposeMatrix(matrix, rows, cols);
	viewMatrix(newMatrix, cols, rows);

	cout << endl;

	// double
	double rowD1[] = { 1.1, 2.2, 3.5 };
	double rowD2[] = { 4.7, 5.3, 6.2 };

	double** matrixD = createMatrix(rows, cols, rowD1, rowD2);
	viewMatrix(matrixD, rows, cols);
	double** newMatrixD = transposeMatrix(matrixD, rows, cols);
	viewMatrix(newMatrixD, cols, rows);

	delMatrix(matrix, rows);
	delMatrix(matrixD, rows);
	delMatrix(newMatrix, rows);
	delMatrix(newMatrixD, rows);
}