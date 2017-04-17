#include<iostream>
#include"Clasa.h"

using namespace std;

int main()
{
	IntList L;

	L.Add(3);
	
	
	IntList L;

	L.Add(7);

	L.Add(2);

	L.Add(5);

	L.Add(4);

	L.Add(4);

	cout << "Lista Initiala: " << endl;

	L.Afiseaza();

	//cout << L.GetCount() << endl;

	cout << "Test pentru insert: " << endl;

	L.Insert(3, 89);

	L.Afiseaza();


	cout << "Test pentru delete: " << endl;

	L.Delete(2);

	L.Afiseaza();


	// Test pentru clear

	//L.Clear();


	cout << "Test pentru duplicate: " << endl;

	L.RemoveDuplicates();

	L.Afiseaza();


	cout << "Test pentru Sort: " << endl;

	L.Sort();

	L.Afiseaza();



	cout << "Test pentru Reverse: " << endl;

	L.Reverse();

	L.Afiseaza();



	cout <<"Test pentru Get: " << endl;

	cout << L.Get(3) << endl;



	cout << "Test pentru getCount: " << endl;

	cout << L.GetCount() << endl;




	cout << "Test pentru intersectie: " << endl;


	IntList L2;
	IntList L3;

	IntList L1;

	L1.Add(2);
	L1.Add(1);

	L2.Add(2);
	L2.Add(3);

	L1.Intersection(&L2, &L3);

	for (int i = 0; i < L3.GetCount(); i++)
	{
		cout << L3.Get(i) << " ";
	}

	cout << endl;






	cout << "Test pentru reuniune: " << endl;

	IntList L4;
	IntList L5;
	IntList L6;

	L4.Add(0);
	L4.Add(1);
	L4.Add(2);

	L5.Add(2);

	L4.Reunion(&L5, &L6);

	for (int i = 0; i < L6.GetCount(); i++)
	{
		cout << L6.Get(i) << " ";
	}

	cout << endl;


	cout << "Test pentru sortare pe reuniune: " << endl;

	L6.Sort();

	L6.Afiseaza();

	

	//cout << endl;

	


	return 0;
}