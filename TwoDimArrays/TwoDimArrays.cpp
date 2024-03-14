#include <iostream>
#include <iomanip>
#include <fstream>

const int N_ROWS = 4;
const int N_COLUMNS = 4;

int nPositColumns(const int matrix[][N_COLUMNS], int nRows, int nColumns)
{
	int nPositiveColumns = 0;
	for (int j = 0; j < nRows; ++j)
	{
		int nPositiveNumbers = 0;
		for (int i = 0; i < nColumns; ++i)
		{
			if (matrix[i][j] > 0)
			{
				++nPositiveNumbers;
			}
		}
		if (nPositiveNumbers == nColumns)
		{
			++nPositiveColumns;
		}
	}
	return nPositiveColumns;
}

void inSpiralMatrix(int** matrix, int nRows, int nColumns)
{
	int amount = nRows * nColumns;
	int rowDirection = 1;
	int columnDirection = 1;
	int number = 1;
	int I = -1;
	int J = 0;
	while (number != (amount + 1))
	{
		if (nColumns == nRows)
		{
			int counter1 = 0;
			while (counter1 != nColumns)
			{
				I += columnDirection;
				matrix[I][J] = number;
				++number;
				++counter1;
			}
			--nRows;
			columnDirection *= -1;
		}
		else
		{
			int counter2 = 0;
			while (counter2 != nRows)
			{
				J += rowDirection;
				matrix[I][J] = number;
				++number;
				++counter2;
			}
			--nColumns;
			rowDirection *= -1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int matrix1[N_ROWS][N_COLUMNS] { {1, 0, -1, 1},
									 {2, 0, -2, 2},
									 {3, 0, -3, 0},
									 {4, 0, -4, -4} };
	std::ofstream out;
	out.open("out.txt");
	if (!out)
	{
		std::cout << "Файл не открывается, завершение программы";
		return 0;
	}
	out << "Количество столбцов, содержащих только положительные элементы: " << nPositColumns(matrix1, N_ROWS, N_COLUMNS) << "\n";
	std::ifstream in;
	in.open("in.txt");
	if (!in)
	{
		std::cout << "Файл не открывается, завершение программы";
		return 0;
	}
	int sizeOfMatrix = 0;
	in >> sizeOfMatrix;
	if (sizeOfMatrix <= 0 || !in)
	{
		std::cout << "Размер квадратной матрицы должен быть задан целым положительным числом, завершение программы";
		return 0;
	}
	int** matrix2 = new int* [sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; ++i)
	{
		matrix2[i] = new int[sizeOfMatrix];
	}
	inSpiralMatrix(matrix2, sizeOfMatrix, sizeOfMatrix);
	for (int i = 0; i < sizeOfMatrix; ++i)
	{
		for (int j = 0; j < sizeOfMatrix; ++j)
		{
			out << std::setw(3) << matrix2[i][j];
		}
		out << "\n";
	}
	for (int i = 0; i < sizeOfMatrix; ++i)
	{
		delete[] matrix2[i];
	}
	delete[] matrix2;
	in.close();
	out.close();
	return 0;
}