#include <iostream>
#include "rectangle.h"
#include "parallelogram.h"
#include "compositeShape.h"
#include "fstream"
#include <ctime>

void sortFigures(Shape** figures, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (*figures[j + 1] < *figures[j])
			{
				Shape* temp = figures[j];
				figures[j] = figures[j + 1];
				figures[j + 1] = temp;
			}
		}
	}
}

int main()
{
	std::ifstream in;
	in.open("in.txt");
	if (!in)
	{
		std::cerr << "File doesn't exist";
		return 0;
	}
	Shape** figures = new Shape*[256];
	int amount = 0;
	std::string meaning = "";
	double parametr1 = 0.0;
	double parametr2 = 0.0;
	double parametr3 = 0.0;
	double parametr4 = 0.0;
	double parametr5 = 0.0;
	double parametr6 = 0.0;
	int complexN = 0;
	double x = 0.0;
	double y = 0.0;
	double coefficient = 0.0;
	in >> meaning;
	while (!in.eof())
	{
		if (meaning == "RECTANGLE")
		{
			in >> parametr1 >> parametr2 >> parametr3 >> parametr4;
			try
			{
				if (!in)
					throw std::invalid_argument("Wrong parameters");
				Rectangle rect(parametr1, parametr2, parametr3, parametr4);
				std::cout << rect << std::endl;
				figures[amount] = rect.clone();
				++amount;
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
				in.clear();
			}
			in >> meaning;
		}
		else if (meaning == "PARALLELOGRAM")
		{
			in >> parametr1 >> parametr2 >> parametr3 >> parametr4 >> parametr5 >> parametr6;
			try
			{
				if (!in)
					throw std::invalid_argument("Wrong parameters");
				Parallelogram par(parametr1, parametr2, parametr3, parametr4, parametr5, parametr6);
				std::cout << par << std::endl;
				figures[amount] = par.clone();
				++amount;
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
				in.clear();
			}
			in >> meaning;
		}
		else if (meaning == "COMPLEX")
		{
			in >> complexN;
			CompositeShape compShape(complexN);
			while (meaning != "COMPLEXEND")
			{
				if (meaning == "RECTANGLE")
				{
					in >> parametr1 >> parametr2 >> parametr3 >> parametr4;
					try
					{
						if (!in)
							throw std::invalid_argument("Wrong parameters");
						Rectangle rect(parametr1, parametr2, parametr3, parametr4);
						try
						{
							if (complexN <= compShape.getReal())
								throw std::out_of_range("No place");
							compShape.addNew(rect.clone());
						}
						catch (const std::out_of_range& e)
						{
							std::cout << e.what() << std::endl;
						}
					}
					catch (const std::invalid_argument& e)
					{
						std::cout << e.what() << std::endl;
						in.clear();
					}
					in >> meaning;
				}
				else if (meaning == "PARALLELOGRAM")
				{
					in >> parametr1 >> parametr2 >> parametr3 >> parametr4 >> parametr5 >> parametr6;
					try
					{
						if (!in)
							throw std::invalid_argument("Wrong parameters");
						Parallelogram par(parametr1, parametr2, parametr3, parametr4, parametr5, parametr6);
						try
						{
							if (complexN <= compShape.getReal())
								throw std::out_of_range("No place");
							compShape.addNew(par.clone());
						}
						catch (const std::out_of_range& e)
						{
							std::cout << e.what() << std::endl;
						}
					}
					catch (const std::invalid_argument& e)
					{
						std::cout << e.what() << std::endl;
						in.clear();
					}
					in >> meaning;
				}
				else
					in >> meaning;
			}
			std::cout << compShape << std::endl;
			figures[amount] = compShape.clone();
			++amount;
		}
		else if (meaning == "MOVE")
		{
			in >> x >> y;
			try
			{
				if (!in)
					throw std::invalid_argument("Wrong parameters");
				std::cout << "\nAFTER MOVE:" << std::endl << std::endl;
				for (int i = 0; i < amount; ++i)
				{
					figures[i]->move(x, y);
					std::cout << *figures[i] << std::endl;
				}
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
				in.clear();
			}
			in >> meaning;
		}
		else if (meaning == "SCALE")
		{
			in >> x >> y >> coefficient;
			try
			{
				if (!in)
					throw std::invalid_argument("Wrong parameters");
				std::cout << "\nAFTERSCALE:\n\n";
				for (int i = 0; i < amount; ++i)
				{
					figures[i]->scale(x, y, coefficient);
					std::cout << *figures[i] << std::endl;
				}
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
				in.clear();
			}
			in >> meaning;
		}
		else
			in >> meaning;
	}
	sortFigures(figures, 256 - (256 - amount));
	std::cout << "\nAFTER SORTING:\n\n";
	for (int i = 0; i < amount; ++i)
	{
		std::cout << *figures[i] << std::endl;
	}
	for (int i = 0; i < amount; ++i)
	{
		delete[] figures[i];
	}
	delete[] figures;
	CompositeShape* complex = new CompositeShape(3);
	Rectangle a(1, 1, 3, 3);
	complex->addNew(a.clone());
	Parallelogram b(-1, -1, -2, -1, -3, -3);
	complex->addNew(b.clone());
	std::cout << "\nTEST:\n";
	std::cout << '\n' << *complex << std::endl;
	std::cout << "\nMOVE:\n";
	complex->move(1, 2);
	std::cout << '\n' << *complex << std::endl;
	std::cout << "\nMOVE CENTER:\n";
	complex->move({0, 0});
	std::cout << '\n' << *complex << std::endl;
	std::cout << "\nCLONE:\n";
	Shape* clone = complex->clone();
	std::cout << '\n' << *clone << std::endl;
	delete clone;
	delete complex;
	return 0;
}