#include <iostream>

bool isPalindrome(unsigned int number)
{
	int numberClone = number;
	int sizeOfArray = 0;
	while (numberClone != 0)
	{
		numberClone /= 2;
		++sizeOfArray;
	}
	int *digits = new int[sizeOfArray];
	for (int i = 0; i < sizeOfArray; ++i)
	{
		digits[i] = number % 2;
		number /= 2;
	}
	for (int i = 0; i <= (sizeOfArray + 1) / 2; ++i)
	{
		if (digits[i] != digits[sizeOfArray - 1 - i])
		{
			delete [] digits;
			return false;
		}
	}
	delete [] digits;
	return true;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int number = 0;
	std::cout << "¬ведите число: ";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "ѕараметр функции должен быть задан целым числом, завершение программы";
		return 0;
	}
	std::cout << isPalindrome(number);
	return 0;
}