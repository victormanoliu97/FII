#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdexcept>

using namespace std;

class Compare

{

public:

	virtual int CompareElements(void* e1, void* e2) = 0;

};

template<class T>
class Array;

template<class T>
class ArrayIterator

{

private:

	T** Current; 

public:

	ArrayIterator(T** constReference);

	ArrayIterator& operator ++ ();

	ArrayIterator& operator -- ();

	bool operator= (ArrayIterator<T> &);

	bool operator!=(ArrayIterator<T> &);

	T* GetElement();

};

template<class T>

class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

public:

	Array(); // Lista nu e alocata, Capacity si Size = 0

	~Array(); // destructor

	Array(int capacity); // Lista e alocata cu 'capacity' elemente

	Array(const Array<T> &otherArray); // constructor de copiere



	T& operator[] (int index) const; // arunca exceptie daca index este out of range



	const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

	const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie



	bool operator=(const Array<T> &otherArray);



	void Sort(); // sorteaza folosind comparatia intre elementele din T

	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie

	void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie



									// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator



	int Find(const T& elem); // cauta un element in Array

	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator



	int GetSize();

	int GetCapacity();



	ArrayIterator<T> GetBeginIterator();

	ArrayIterator<T> GetEndIterator();

};


template<class T>
class Comp : public Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		T* element1 = (T*)e1;
		T* element2 = (T*)e2;

		if (element1 == element2)
		{
			return 0;
		}

		if (element1 < element2)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
};

template<class T>
ArrayIterator<T>::ArrayIterator(T** baseIt)
{
	Current = baseIt;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
	Current++;

	return *this;    
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
	Current--;

	return *this;      
}

template<class T>
bool ArrayIterator<T>::operator=(ArrayIterator<T> &val)
{
	Current = val.Current;

	return true;       
}

template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T> &compVal)
{
	if (Current == compVal.Current)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
T* ArrayIterator<T>::GetElement()
{
	return *Current;
}

template<class T>
Array<T>::Array()
{
	Size = 0;
	
	Capacity = 0;
}

template<class T>
Array<T>::~Array()
{
	if (Capacity != 0)
	{
		delete[] List;
	}
}

// Lista alocata cu capacity elemente
template<class T>
Array<T>::Array(int my_capacity)
{
	List = new T*[my_capacity];

	Capacity = my_capacity;

	Size = 0;
}


// Constructorul de copiere
template<class T>
Array<T>::Array(const Array<T> &copyArray)
{
	Capacity = copyArray.Capacity;

	List = new T*[Capacity];

	Size = copyArray.Size;

	memcpy(List, copyArray.List, sizeof(T*) * copyArray.Size);
}


// Exceptie daca index este out of range
template<class T>
T& Array<T>::operator[] (int index) const
{
	if (index < 0 || index >= Size)
	{
		throw new range_error("Invalid index");
	}

	return *(List[index]);
}


// Adauga element de tipul T la finalul listei si returneaza this
template<class T>
const Array<T>& Array<T>::operator+=(const T &newElement)
{
	if (Size == Capacity)
	{
		throw new length_error("Not enough space");
	}

	List[Size] = (T *)&newElement;

	Size++;

	return *this;
}


// Adauga un element pe pozitia index si returneaza index iar in caz ca index este invalid arunca o exceptie
template<class T>
const Array<T>& Array<T>::Insert(int index, const T &newElem)
{
	if (index < 0 || index >= Capacity)
	{
		throw new range_error("Invalid index");
	}

	for (int i = Size; i >= index; i--)
	{
		List[i] = List[i - 1];
	}

	List[index] = (T *)&newElem;

	Size++;

	return *this;
}


// Adauga o lista pe pozitia index si returneaza this iar daca index este invalid arunca o exceptie

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	if (index < 0 || index >= Capacity)
	{
		throw new range_error("Invalid index");
	}

	if (Capacity < index + otherArray.Size)
	{
		throw new length_error("Insuficient spatiu");
	}

	for (int i = index + otherArray.Size - 1; i >= index; i--)
	{
		List[i] = List[i - index];
	}

	for (int i = index; i < index + otherArray.Size; i++)
	{
		List[i] = &(otherArray[i - index]);
	}

	Size = Size + otherArray.Size;

	return *this;
}


// Sterge element de pe pozitia index si returneaza index cu sfanta exceptie

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
	if (index < 0 || index >= Size)
	{
		throw new range_error("Invalid index , index-ul nu este in limitele bune");
	}

	for (int i = index; i < Size - 1; i++)
	{
		List[i] = List[i + 1];
	}

	return *this;
}


template<class T>
bool Array<T>::operator=(const Array<T> &otherArray)
{
	if (otherArray.Size > Capacity)
	{
		throw new length_error("Nu este destul spatiu");
	}

	for (int i = 0; i < otherArray.Size; i++)
	{
		List[i] = &otherArray[i];
	}

	Size = otherArray.Size;

	return true;
}

template<class T>
int Array<T>::GetSize()
{
	return Size;
}

template<class T>
int Array<T>::GetCapacity()
{
	return Capacity;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
	return ArrayIterator<T>(List);
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
	return ArrayIterator<T>(List + Size - 1);
}

