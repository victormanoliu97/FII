#include<iostream>
#include<string>
using namespace std;



class RomanNumbers
{
private:
	pair<int, string> number;

public:
	RomanNumbers(string = "")
	{
		number.second = "";
	}

	void SetRoman(string myRoman)
	{
		number.second = myRoman;
	}

	void SetDecimal(int myNumber)
	{
		number.first = myNumber;
	}

	int getDecimalPair()
	{
		return number.first;
	}

	string getRomanPair()
	{
		return number.second;
	}

	bool romanSort(RomanNumbers i, RomanNumbers j)
	{
		return i.getDecimalPair() < j.getDecimalPair();
	}


	int Convert()
	{
		enum romans { I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 };

		string roman = number.second;

		for (int i = 0; i < roman.size(); i++)
		{
			switch (roman[i])
			{

			case 'M': number.first += M; break;
			case 'D': number.first += D; break;
			case 'C': number.first += C; break;
			case 'L': number.first += L; break;
			case 'X': number.first += X; break;
			case 'V': number.first += V; break;

			
			case 'I':
				if (roman[i + 1] != 'I' && i + 1 != roman.size())
				{
					number.first -= 1;
				}
				else
				{
					number.first += 1;
				}
				break;
             
			}
		}

		return number.first;

	}

	
};