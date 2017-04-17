#include<iostream>
#include "BigNumber.h"
using namespace std;

int main()
{
	BigNumber a, b, c, d, e, f, a1, b1;

	BigNumber x, y, z;

	


	a.Set("12345");
	b.Set("69");

	a1.Set("70");
	b1.Set("70");

	c.Set(a + b);
	d.Set(a*b);
	e.Set(a - b);
	f.Set(a / b);

	cout << "Afisarea normala: ";
	a.Print();
	b.Print();
	a1.Print();
	b1.Print();
	

	cout << "Test pentru +: ";
	c.Print();

	cout << "Test pentru *: ";
	d.Print();


	cout << "Test pentru -: ";
	e.Print();


	cout << "Test pentru impartire : ";
	f.Print();



	cout << "Test pentru >: ";
	if (a > b)
	{
		a.Print();
	}
	else
	{
		b.Print();
	}


	cout << "Test pentru <: ";
	if (a < b)
	{
		a.Print();
	}
	else
	{
		b.Print();
	}


	cout << "Test pentru ==: ";
	if (a1 == b1)
	{
		cout << "Sunt egale 70 si 70";
	}
	else
	{
		cout << "Nu sunt egale";
	}

	cout << endl;


	cout << "Test pentru !=: ";
	if (a != b)
	{
		cout << "Nu sunt egale";
	}
	else
	{
		cout << "Sunt egale";
	}

	cout << endl;




	BigNumber z17;

	z17.Set("987654");

	cout << "Test pentru index: ";

	cout << a.operator[] (3);

	cout << endl;

	cout << "Test pentru returnarea numarului de la pozitia start la end: ";

	cout<<a.operator() (1, 4);

	cout << endl;


	cout << "Test cast la int: ";

	cout << a.operator const int();

	cout << endl;


	a.Set(12345);

	b.Set(69);

	c.Set(a/b);

	c.Print();



	return 0;
}