#include <cstring>
#include <cmath>
#include <iostream>
#include <cstring>

class BigNumber {

private:

	const char Start = '0';

	char Number[256];

	int  CharactersCount;

public:

	BigNumber(); // Constructor implicit (creaza numarul 0 [field-ul Number contine "0", field-ul CharactersCount contine valoarea 1 - un caracter]

	BigNumber(int value);

	BigNumber(const char * number);

	BigNumber(const BigNumber & number);



	void Set(int value);

	void Set(const char * number);

	void Set(const BigNumber & number);

	void Print();

	int Max(int a, int b);



	BigNumber operator+ (const BigNumber & number);

	BigNumber operator* (const BigNumber & number);

	BigNumber operator- (const BigNumber & number);

	BigNumber operator/ (const BigNumber & number);


	friend bool operator == (const BigNumber & n1, const BigNumber & n2)
	{
		if (n1.CharactersCount != n2.CharactersCount)
		{
			return false;
		}
		for (int i = 0; i < n1.CharactersCount; i++)
		{
			if (n1.Number[i] != n2.Number[i])
			{
				return false;
			}

		}

		return true;
	}



	friend bool operator != (const BigNumber & n1, const BigNumber & n2)
	{
		if (n1.CharactersCount == n2.CharactersCount)
		{
			return false;
		}
		for (int i = 0; i < n1.CharactersCount; i++)
		{
			if (n1.Number[i] != n2.Number[i])
			{
				return true;
			}
		}
		return false;
	}

	friend bool operator <  (const BigNumber & n1, const BigNumber & n2)
	{
		if (n1.CharactersCount < n2.CharactersCount)
		{
			return true;
		}
		else if (n1.CharactersCount > n2.CharactersCount)
		{
			return false;
		}
		else
		{
			for (int i = n1.CharactersCount - 1; i >= 0; i--)
			{
				if (n1.Number[i] < n2.Number[i])
				{
					return true;
				}
				else if (n1.Number[i] > n2.Number[i])
				{
					return false;
				}
			}
		}
		return false;
	}



	friend bool operator >  (const BigNumber & n1, const BigNumber & n2)
	{
		if (n1.CharactersCount > n2.CharactersCount)
		{
			return true;
		}
		else if (n1.CharactersCount < n2.CharactersCount)
		{
			return false;
		}
		else
		{
			for (int i = n1.CharactersCount - 1; i >= 0; i--)
			{
				if (n1.Number[i] > n2.Number[i])
				{
					return true;
				}
				else if (n1.Number[i] < n2.Number[i])
				{
					return false;
				}
			}
		}
		return false;
	}

	friend bool operator >= (const BigNumber & n1, const BigNumber & n2)
	{
		if (!(n1 < n2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}



	friend bool operator <= (const BigNumber & n1, const BigNumber & n2)
	{
		if (!(n1 > n2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}



	operator const int()
	{
		int rez = 0;
		for (int i = CharactersCount - 1; i >= 0; i--)
		{
			rez = rez * 10 + Number[i] - '0';
		}
		return rez;
	}


	char operator[] (int index) // returneaza caracterul de pe pozitia index sau \0 in rest
	{
		if (index >= CharactersCount)
		{
			return '\0';
		}
		return Number[CharactersCount - index - 1];
	}


	BigNumber operator() (int start, int end) // returneaza numarul de la caracterul dat de pozitia "start" pana la caracterul dat de pozitia "end" sau "0" daca start/end nu sunt valide.
	{
		if (start > end || start >= CharactersCount || end >= 256)
		{
			BigNumber zero;

			zero.Set(0);

			return zero;
		}

		BigNumber result;

		char rez[256];

		int counter = 0;

		for (int i = end+1; i >= start; i--)
		{
			rez[counter] = Number[i];

			counter++;
		}

		rez[counter] = '\0';

		result.Set(rez);

		return result;
	}
};
