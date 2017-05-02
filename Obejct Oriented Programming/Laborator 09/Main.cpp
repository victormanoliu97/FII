#include<iostream>
#include"Agenda.h"
#include"Coleg.h"

using namespace std;

int main()
{
	Agenda myAgenda;

	Coleg newCollegue;

	newCollegue.name = "Andrei";

	myAgenda.add(newCollegue);

	myAgenda.findByName("Vasile");

	vector<Contancte> col = a.getFriendList();

    for (auto it = col.begin(); it != col.end(); it++ )
    {
        cout << (it)->name << endl;
    }

	return 0;
}