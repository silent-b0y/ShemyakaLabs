#include <iostream>
#include <fstream>

char* returnNewString(char* destination, const char* source)
{
	int j = 0;
	int AsciiArray[128]{ 0 };
	for (int i = 0; source[i] != '\0'; i++)
	{
		++AsciiArray[static_cast<int>(source[i])];
	}
	for (int i = 0; i < 128; ++i)
	{
		if (AsciiArray[i] > 1)
		{
			*(destination + j) = static_cast<char>(i);
			++j;
		}
	}
	*(destination + j) = '\0';
	return destination;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream in;
	in.open("file.txt");
	if (!in)
	{
		std::cout << "Файл не открывается, завершение программы";
		return 0;
	}
	std::ofstream out;
	out.open("out.txt");
	if (!out)
	{
		std::cout << "Файл не открывается, завершение программы";
		return 0;
	}
	int sizeOfSource = 0;
	in >> sizeOfSource;
	if ((sizeOfSource < 0) || (!in))
	{
		std::cout << "Размер массива должен быть задан целым положительным числом, завершение программы";
		return 0;
	}
	in.ignore();
	int nString = 0;
	while (!in.eof()) {
		int sizeOfString = 0;
		char* source = new char[sizeOfSource + 1];
		char* destination = new char[sizeOfSource + 1];
		char element;
		in.get(element);
		++sizeOfString;
		for (int i = 0; ((i < sizeOfSource) && (element != '\n')); ++i) 
		{
			source[i] = element;
			in.get(element);
			++sizeOfString;
		}
		if ((sizeOfString > (sizeOfSource)) && (element != '\n'))
		{
			std::cout << "Длина строки превышает размер массива, завершение программы";
			return 0;
		}
		source[sizeOfString - 1] = '\0';
		++nString;
		out << "Новая строка " << nString << ": " << returnNewString(destination, source) << '\n';
		in >> sizeOfSource;
		if (in.eof())
		{
			return 0;
		}
		if ((sizeOfSource < 0) || (!in))
		{
			std::cout << "Размер массива должен быть задан целым положительным числом, завершение программы";
			return 0;
		}
		in.ignore();
		delete[] source;
		delete[] destination;
	}
	return 0;
}