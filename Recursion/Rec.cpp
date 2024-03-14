#include <iostream>

bool isSign(char* string, int i);
bool isDot(char* string, int i);
bool isExponent(char* string, int i);
bool isDigit(char* string, int i);

bool isEndOfString(char* number, int i)
{
	if (i < strlen(number))
		return false;
	return true;
}

bool isRealNumber(char* string, int i)
{
	return isSign(string, i);
}

bool isUnsignedInt(char* string, int i, int x)
{
	if (x == 1)
	{
		if (isDigit(string, i))
		{
			++i;
			return isUnsignedInt(string, i, x);
		}
		else if (isDigit(string, i - 1) && isDot(string, i))
		{
			++i;
			return isUnsignedInt(string, i, ++x);
		}
		return false;
	}
	if (x == 2)
	{
		if (isDigit(string, i))
		{
			++i;
			return isUnsignedInt(string, i, x);
		}
		else if (isDigit(string, i - 1))
		{
			return isExponent(string, i);
		}
		return false;
	}
	if (x == 3)
	{
		if (isDigit(string, i))
		{
			++i;
			return isUnsignedInt(string, i, 3);
		}
		else if (isDigit(string, i - 1) && isEndOfString(string, i))
		{
			return true;
		}
		return false;
	}
}

bool isSign(char* string, int i)
{
	if (i == 0)
	{
		if (string[i] == '+' || string[i] == '-')
		{
			++i;
			if (isDigit(string, i))
			{
				return isUnsignedInt(string, i, 1);
			}
			else if (isDot(string, i))
			{
				++i;
				return isUnsignedInt(string, i, 2);
			}
			return false;
		}
		else if (isDigit(string, i))
		{
			return isUnsignedInt(string, i, 1);
		}
		else if (isDot(string, i))
		{
			++i;
			return isUnsignedInt(string, i, 2);
		}
		return false;
	}
	else
	{
		if (string[i] == '+' || string[i] == '-')
		{
			++i;
			return isUnsignedInt(string, i, 3);
		}
		return false;
	}
}

bool isDot(char* string, int i)
{
	if (string[i] == '.')
	{
		return true;
	}
	return false;
}

bool isExponent(char* string, int i)
{
	if (string[i] == 'E')
	{
		++i;
		if (isSign(string, i))
		{
			++i;
			return isUnsignedInt(string, i, 3);
		}
		else if (isDigit(string, i))
		{
			return isUnsignedInt(string, i, 3);
		}
		return false;
	}
	return false;
}

bool isDigit(char* string, int i)
{
	if (int(string[i]) <= 57 && int(string[i]) >= 48)
	{
		return true;
	}
	return false;
}

int main()
{
	char* string = new char[256];
	std::cin >> string;
	std::cout << isRealNumber(string, 0);
	delete[] string;
	return 0;
}
// +11.11E+11
// 11.11E+11
// 11.11E11
// +.11E11
//.11E11