#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x, y, z;
	cout << "Введите размеры X Y Z: ";
	cin >> x >> y >> z;

	int*** matrix = new int** [x];
	for (int i = 0; i < x; i++)
	{
		matrix[i] = new int* [y];

	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			matrix[i][j] = new int [z];
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				matrix[i][j][k] = i * 100 + j * 10 + k;
			}
		}
	}

	for (int k = 0; k < z; k++)
	{
		cout << "Срез Z = " << k << endl;
		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i < x; i++)
			{
				cout << "[" << i << "][" << j << "][" << k << "] = " << matrix[i][j][k] << endl;
			}
			cout << endl;
		}
	}

	int max = matrix[0][0][0];
	int ind1 = 0, ind2 = 0, ind3 = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				if (max < matrix[i][j][k]) {
					max = matrix[i][j][k];
					ind1 = i;
					ind2 = j;
					ind3 = k;
				}				
			}
		}
	}

	cout << "Максимальный элемент: " << max;
	cout << "\nНайден на позиции: [" << ind1 << "][" << ind2 << "][" << ind3 << "]";

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			delete[] matrix[i][j];
		}
		delete[] matrix[i];
	}
	delete[] matrix;
}