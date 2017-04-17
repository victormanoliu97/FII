#include<iostream>
#include<string.h>
#include<queue>
#include<deque>
#include<functional>
using namespace std;
#define MAX_LENGTH 1024

template <class T>
class Vector
{
	T values[MAX_LENGTH];
	int count;

public:
	Vector() : count(0) {}

	void add(T value)
	{
		values[count] = value;
		count++;
	}


	T get_index(int index)
	{
		return values[index];
	}

	void Remove(int index)
	{
		for (int i = index + 1; i < count; i++)
		{
			values[i - 1] = values[i];
		}

		count--;
	}

	// returneaza cel mai lung cuvant

	T longestWord()
	{
		int maxlength = 0;
		
		int index;

		for (int i = 0; i < count; i++)
		{
			if (values[i].size() > maxlength)
			{
				maxlength = values[i].size();
				
				index = i;
			}
		}

		return values[index];
	}


	// afiseaza cuvintele cu mai mult de 4 vocale

	int atLeast4Vocals()
	{
		int nr = 0;
		
		char vocale[] = { 'a', 'e', 'i', 'o', 'u' };

		for (int i = 0; i < count; i++)
		{
			int vocalecounter = 0;

			for (int j = 0; j < values[i].size(); j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (values[i][j] == vocale[k])
					{
						vocalecounter++;
						break;
					}
				}
				if (vocalecounter >= 4)
				{
					nr++;
					break;
				}
			}
		 }

		return nr;
	}


	// afiseaza cuvintele fara vocale

	deque<T> cuvinteFaraVocale()
	{
		deque<T> newDeque;

		char vocale[] = { 'a','e','i','o','u' };

		for (int i = 0; i < count; i++)
		{
			bool ok = true;

			for (int j = 0; j < values[i].size(); j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (values[i][j] == vocale[k])
					{
						ok = false;
						break;
					}
				}

				if (!ok)
				{
					break;
				}
			}
			if (ok)
			{
				newDeque.push_back(values[i]);
			}
		}

		return newDeque;
	}


	// Elimina cuvintele ce au mai mult de n litere

	void eliminaCuvinteCuMaiMultdeNLitere(int n)
	{
		int my_length = count;

		for (int i = 0; i < my_length; i++)
		{
			if (values[i].size() > n)
			{
				Remove(i);

				my_length--;
			}
		}
	}


	// Crerare de priority queue

	priority_queue<T, vector<T>, greater<T> > sorteazaCuvinteAlfabetic()
	{
		priority_queue<T, vector<T>, greater<T> > newQueue;

		for (int i = 0; i < count; i++)
		{
			newQueue.push(values[i]);
		}

		return newQueue;
	}


	void afis()
	{
		for (int i = 0; i < count; i++)
		{
			cout << values[i] << " ";
		}

		cout << endl;
	}
};
