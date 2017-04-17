#include "BigNumber.h"
#include <iostream>
using namespace std;


BigNumber::BigNumber()
{
	for (int i = 0; i < 256; i++)
	{
		Number[i] = '0';
	}
	CharactersCount = 1;
}


BigNumber::BigNumber(int value)
{
	Set(value);
}
BigNumber::BigNumber(const char * number)
{
	Set(number);
}
BigNumber::BigNumber(const BigNumber & number)
{
	Set(number);
}

void BigNumber::Set(int value)
{
	CharactersCount = 0;
	while (value != 0)
	{
		Number[CharactersCount] = value % 10 + Start;
		value = value / 10;
		CharactersCount++;
	}
	if (CharactersCount == 0)
	{
		CharactersCount++;
	}
}
void BigNumber::Set(const char * number)
{
	CharactersCount = 0;
	while (number[0] < '1' || number[0] > '9')
	{
		number = number + 1;
	}
	for (int i = strlen(number) - 1; i >= 0; i--)
	{
		Number[i] = number[strlen(number) - 1 - i];
		CharactersCount++;
	}
}

void BigNumber::Set(const BigNumber & number)
{
	CharactersCount = 0;
	for (int i = 0; i < number.CharactersCount; i++)
	{
		Number[i] = number.Number[i];
		CharactersCount++;
	}
}

void BigNumber::Print()
{
	for (int i = CharactersCount - 1; i >= 0; i--)
	{
		cout << Number[i];
	}
	cout << endl;
}

BigNumber BigNumber::operator+(const BigNumber & number)
{
	BigNumber result;

	result.Set(0);

	int over = 0;

	char res[256];

	for (int i = 0; i < Max(CharactersCount, number.CharactersCount); i++)
	{
		int a = number.Number[i] - Start;
		int b = Number[i] - Start;
		a = a + b + over;
		if (a >= 10)
		{
			a = a % 10;
			over = 1;
		}
		else
		{
			over = 0;
		}
		res[i] = a + Start;
	}
	if (over == 1)
	{
		res[Max(CharactersCount, number.CharactersCount)] = '1';
		res[Max(CharactersCount, number.CharactersCount) + 1] = '\0';
	}
	else
	{
		res[Max(CharactersCount, number.CharactersCount)] = '\0';
	}
	result.Set(strrev(res));
	return result;
}


BigNumber BigNumber::operator-(const BigNumber & number)
{
	if (*this == number)
	{
		BigNumber zero;
		zero.Set(0);
		return zero;
	}
	BigNumber result;
	result.Set(0);
	int over = 0;
	char res[256];
	for (int i = 0; i < Max(CharactersCount, number.CharactersCount); i++)
	{
		int b = number.Number[i] - Start;
		int a = Number[i] - Start;
		a = a - b - over;
		if (a < 0)
		{
			a = (a + 10) % 10;
			over = 1;
		}
		else
		{
			over = 0;
		}
		res[i] = a + Start;
	}
	if (over == 1)
	{
		res[Max(CharactersCount, number.CharactersCount)] = '0';
		res[Max(CharactersCount, number.CharactersCount) + 1] = '\0';
	}
	else
	{
		res[Max(CharactersCount, number.CharactersCount)] = '\0';
	}
	result.Set(strrev(res));
	return result;
}



BigNumber BigNumber::operator*(const BigNumber & number)
{
	if (Number[CharactersCount - 1] == '0' || number.Number[number.CharactersCount - 1] == '0')
	{
		BigNumber zero;
		zero.Set(0);
		return zero;
	}
	BigNumber result;
	result.Set(0);

	
	int a, b;
	for (int i = 0; i < CharactersCount; i++)
	{
		char res[256];
		a = Number[i] - Start;
		for (int j = 0; j < i; j++)
		{
			res[j] = '0';
		}
		int over = 0;
		for (int j = 0; j < number.CharactersCount; j++)
		{
			b = number.Number[j] - Start;
			b = a * b + over;
			if (b >= 10)
			{
				over = b / 10;
				b = b % 10;
			}
			else
			{
				over = 0;
			}
			res[j + i] = b + Start;
		}
		if (over >= 1)
		{
			res[number.CharactersCount + i] = Start + over;
			res[number.CharactersCount + i + 1] = '\0';
		}
		else
		{
			res[number.CharactersCount + i] = '\0';
		}
		BigNumber aux;
		aux.Set(strrev(res));
		result.Set(result + aux);
	}
	return result;
    

	return result;
}


BigNumber BigNumber::operator/(const BigNumber & number)
{
	BigNumber result;
	result.Set(0);
	char dreapta[2];
	char rez[256];
	BigNumber rest;
	rest.Set(0);
	BigNumber zece;
	zece.Set(10);
	for (int i = 0; i < CharactersCount; i++)
	{
		dreapta[0] = Number[CharactersCount - i - 1];
		dreapta[1] = '\0';
		BigNumber aux;
		aux.Set(strrev(dreapta));
		rest.Set(rest * zece + aux);
		int counter = 0;
		while (rest >= number)
		{
			rest.Set(rest - number);
			counter++;
		}
		rez[i] = counter + Start;
	}
	rez[CharactersCount] = '\0';
	result.Set(rez);
	return result;
}


int BigNumber::Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
