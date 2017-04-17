#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include"TemplateVector.h"
using namespace std;

ifstream f("input.txt");

/*

int main()
{
	Vector<string> cuvinte;

	int n;

	while (!f.eof())
	{
		char aux[100];
		f >> aux;

		cuvinte.add(aux);
	}

	cuvinte.afis();

	cout << "Cuvinte ce contin cel putin 4 vocale: " << cuvinte.atLeast4Vocals() << endl;

	cout << "Cel mai lung cuvant: " << cuvinte.longestWord() << endl;

	deque<string> aux_deque = cuvinte.cuvinteFaraVocale();

	cout << "Cuvintele ce nu contin vocale: ";
	
	for (int i = 0; i < aux_deque.size(); i++)
	{
		cout << aux_deque[i] << " ";
	}

	cout << endl;

	cout << "Cuvintele sortate in ordine alfabetica: ";

	priority_queue<string, vector<string>, greater<string> > aux_priority_queue = cuvinte.sorteazaCuvinteAlfabetic();

	while (!aux_priority_queue.empty())
	{
		string aux_string = aux_priority_queue.top();

		aux_priority_queue.pop();

		cout << aux_string << " ";
	}

	cout << endl;

	cout << "Introduceti n: ";

	cin >> n;

	cuvinte.eliminaCuvinteCuMaiMultdeNLitere(n);

	cuvinte.afis();

	return 0;
}
*/

int GlobalValue = 0;

class Integer
{
	int value;
	
public:
	Integer(int val) : value(val) {};

	void* operator new(size_t, int value);
};

void* Integer::operator new(size_t, int value)
{
	return &GlobalValue;
}

int main()
{
	Integer *n1 = new(2)Integer(3);

	cout << n1;

	return 0;


}