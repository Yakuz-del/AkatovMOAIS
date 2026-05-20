#include <iostream>
#include <Windows.h>

using namespace std;

template<typename T>
T** createTriangularMatrix(int n)
{
	T** newMatrix = new T* [n];
	for (int i = 0; i < n; i++)
	{
		newMatrix[i] = new T[i+1];
	}
	return newMatrix;
}

int sumMatrix(int** matrix, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += matrix[i][j];
		}
	}

	return sum;
}

template<typename T>
void delMatrix(T** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите размер треугольной матрицы: ";
	cin >> n;
	int** matrix = createTriangularMatrix<int>(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = i + j;
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << "Строка " << i << ": ";
		for (int j = 0; j <= i; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	cout << "Сумма всех элементов: " << sumMatrix(matrix, n);
	cout << endl;

	delMatrix(matrix, n);
}