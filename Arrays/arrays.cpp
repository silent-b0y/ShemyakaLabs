#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>

int numberOfIdentical(int* arr, int arrSize)
{
	if (arrSize <= 0)
	{
		std::cout << "Размер массива должен быть больше нуля, завершение программы";
		return 0;
	}
	int max = 0;
	int counter = 1;
	for (int i = 1; i <= arrSize - 1; ++i)
	{
		if (arr[i] == arr[i - 1])
		{
			++counter;

		}
		else
		{
			if (counter > max)
			{
				max = counter;
			}
			counter = 1;
		}
	}
	if (counter > max)
	{
		max = counter;
	}
	return max;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int ARRAY_SIZE1 = 7;
	int arr1[ARRAY_SIZE1] { 2, 1, 4, 3, 8, 8, 8 };
	std::cout << numberOfIdentical(arr1, ARRAY_SIZE1) << "\n";
	std::cout << "Введите размер массива: ";
	int arraySize2 = 0;
	std::cin >> arraySize2;
	if (!std::cin)
	{
		std::cout << "Элементы последовательности должны быть заданы целыми числами, завершение программы";
		return 0;
	}
	else if (arraySize2 <= 0)
	{
		std::cout << "Размер массива должен быть больше нуля, завершение программы";
		return 0;
	}
	int* arr2 = new int[arraySize2];
	std::srand(time(0));
	for (int i = 0; i <= arraySize2 - 1; ++i)
	{
		arr2[i] = rand() % 20 - 10;
		std::cout << arr2[i] << " ";
	}
	std::cout << "\n" << numberOfIdentical(arr2, arraySize2) << "\n";
	delete[] arr2;
	std::string filepath = "file.txt";
	std::ifstream file;
	file.open(filepath);
	if (!file)
	{
		std::cout << "Файл не открывается, завершение программы";
		return 0;
	}
	for (int i = 0; i < 3; ++i)
	{
		int arraySize3 = 0;
		file >> arraySize3;
		if (!file)
		{
			std::cout << "Размер массива должен быть задан целыми числами, завершение программы";
			return 0;
		}
		else if (arraySize3 <= 0)
		{
			std::cout << "Размер массива должен быть больше нуля, завершение программы";
			return 0;
		}
		int* arr3 = new int[arraySize3];
		for (int i = 0; i <= arraySize3 - 1; ++i)
		{
			file >> arr3[i];
			if (!file)
			{
				std::cout << "Элементы массива должны быть заданы целыми числами, завершение программы";
				delete[] arr3;
				return 0;
			}
		}
		std::cout << numberOfIdentical(arr3, arraySize3) << "\n";
		delete[] arr3;
	}
	file.close();
	return 0;
}