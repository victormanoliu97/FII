#include<iostream>
using namespace std;

class IntList {

private:

	int Elemente[1000];

	int Count;

public:

	IntList(); // Constructor implicit

	~IntList(); // Destructor implicit

	bool Add(int element); // returneaza false daca lista este plina (s-au adaugat 1000 de elemente)

	bool Insert(int index, int element);

	bool Delete(int index);

	void Clear();

	int  IndexOf(int valoare, int startPosition); // indexul pozitiei unei valori sau "-1" in caz contrar

	void RemoveDuplicates();

	void Intersection(IntList* withList, IntList * resultList);

	void Reunion(IntList* withList, IntList * resultList);

	void Sort();

	void Reverse();

	int  Get(int index); // returneaza elementul de pe pozitia index sau -1 in caz contrar

	int  GetCount();

	void Afiseaza();    // pentru afisare

};

IntList::IntList()
{
	cout << "Obiectul a fost creat" << endl;
	Count = 0;
}

IntList::~IntList()
{
	cout << "Obiectul a fost luat de pe stiva" << endl;
}

bool IntList::Add(int element)
{
	if (Count >= 1000)
	{
		return false;
	}
	else
	{
		Elemente[Count++] = element;
	}

}


bool IntList::Insert(int index, int element)
{

	if (index >= Count || index < 0)
	{
		return false;
	}

	Count++;

	for (int i = Count; i > index; i--)
	{
		Elemente[i] = Elemente[i - 1];

	}

	Elemente[index] = element;

}


bool IntList::Delete(int index)
{
	if (index < 0 || index >= Count)
	{
		return false;
	}

	for (int i = index; i < Count; i++)
	{
		Elemente[i] = Elemente[i+1];
	}

	Count--;
}


void IntList::Clear()
{
	Count = 0;
}

int IntList::IndexOf(int valoare, int startPosition)
{
	for (int i = startPosition; i < Count; i++)
	{
		if (Elemente[i] == valoare)
		{
			return i;
		}
	}

	return -1;
}


void IntList::RemoveDuplicates()
{
	for (int i = 0; i < Count; i++)
	{
		for (int j = i + 1; j < Count; j++)
		{
			if (Elemente[i] == Elemente[j])
			{
				bool ok = this->Delete(i);
				j--;
			}
		}
	}
}

void IntList::Intersection(IntList* withList, IntList * resultList)
{
	resultList->Count = 0;
	for (int i = 0; i < this->Count; ++i)
		for (int j = 0; j < withList->Count; j++)
			if (Elemente[i] == withList->Elemente[j])
			{
				//resultList->Count++;
				resultList->Elemente[resultList->Count] = Elemente[i];
				resultList->Count++;
			}
}

void IntList::Reunion(IntList* withList, IntList * resultList)
{
	resultList->Count = 0;
	for (int i = 0; i < this->Count; ++i)
	{
		resultList->Elemente[resultList->Count] = Elemente[i];
		resultList->Count++;
	}

	for (int i = 0; i < withList->Count; ++i)
	{
		resultList->Elemente[resultList->Count] = Elemente[i];
		resultList->Count++;
	}

	resultList->RemoveDuplicates();

		
			
}


void IntList::Sort()
{
	
	int aux;

	for (int i = 0; i < Count-1; i++)
	{
		for (int j = i + 1; j < Count; j++)
		{
			if (Elemente[i] > Elemente[j])
			{
				swap(Elemente[i], Elemente[j]);
			}
		}
	}

	

	
}

void IntList::Reverse()
{
	int aux;

	for (int i = 0; i < Count / 2; i++)
	{
		aux = Elemente[i];

		Elemente[i] = Elemente[Count - i - 1];

		Elemente[Count - i - 1] = aux;
	}

}



// returneaza elementul de pe pozitia index sau -1 in caz contrar

int IntList::Get(int index)
{
	if (index > Count)
	{
		return -1;
	}

	if (index < 0)
	{
		return -1;
	}

	return Elemente[index];
}


int IntList::GetCount()
{
	int counter = 0;

	for (int i = 0; i < Count; i++)
	{
		counter++;
	}

	return counter;
}


void IntList::Afiseaza()
{
	for (int i = 0; i < Count; i++)
	{
		cout << Elemente[i] << " ";
	}

	cout << endl;
}


