#include <iostream>
#include <cmath>
#include <tgmath.h>
#include <iomanip>

void taylorSeries(double absError, int numberMax, double x)
{
	if (x <= -1 || x >= 1)
		throw ("x не попадает в заданный интервал");
	if (std::abs(x) <= 1e-15)
	{
		x = 0;
	}
	double numerator = x;
	int denominator = 1;
	double result = 0;
	int i = 0;
	while (i < numberMax && abs((numerator / denominator)) > absError)
	{
		result += numerator / denominator;
		numerator *= x * x;
		denominator += 2;
		++i;
	}
	if (abs(numerator / denominator) > absError || abs(atanh(x) - result) > absError)
		throw ("точность не достигнута");
	std::cout << std::setw(15) << x << std::setw(15) << result << std::setw(15) << atanh(x) << '\n';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double absError = 0;
	std::cout << "¬ведите точность вычислений: ";
	std::cin >> absError;
	if (!std::cin || absError <= 0)
	{
		std::cout << "Ќеверна€ абсолютна€ погрешность, завершение программы";
		return 0;
	}
	int numberMax = 0;
	std::cout << "¬ведите максимальное число слагаемых: ";
	std::cin >> numberMax;
	if (!std::cin || numberMax <= 0)
	{
		std::cout << "Ќеверное максимальное число слагаемых, завершение программы";
		return 0;
	}
	double step = 0;
	std::cout << "¬ведите шаг интервала: ";
	std::cin >> step;
	if (!std::cin || step <= 0)
	{
		std::cout << "Ќеверный шаг интервала, завершение программы";
		return 0;
	}
	for (double x = -1.0 + step; x < 1.0; x += step)
	{
		try
		{
			taylorSeries(absError, numberMax, x);
		}
		catch (const char * message)
		{
			std::cout << std::setw(15) << x << " " << std::setw(15) << message << '\n';
		}
	}
	return 0;
}