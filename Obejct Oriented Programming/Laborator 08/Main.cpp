#include<iostream>
#include"Laborator 08.h"

using namespace std;

int main()
{
	Array<int> a(4);

	int b1 = 1;
	int b2 = 2;
	int b3 = 3;
	int b4 = 4;

	a += b1;
	a += b2;
	a += b3;
	a += b4;


	cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;

	cout << endl;


	Array<int> c(a);

	c.Insert(0, 9);
	


	Array<int> d(4);

	d += 5;
	d += 6;
	d += 7;
	d += 8;

	a = d;

	cout << a[0] << " " << a[1] << " "<<a[2] << " " << a[3] << endl;

	cout << endl;

	ArrayIterator<int> i = a.GetBeginIterator();
	ArrayIterator<int> j = a.GetEndIterator();

	cout << *(i.GetElement()) << " " << *(j.GetElement()) << endl;

	cout << endl;

	++i;

	--j;

	cout << *(i.GetElement()) << " " << *(j.GetElement()) << endl;

	cout << endl;

	
}