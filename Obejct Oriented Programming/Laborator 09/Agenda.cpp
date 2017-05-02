#include "Agenda.h"

Contacte& Agenda::findByName(string name)
{
	for (auto it = contacts.begin(); it != contacts.end(); it++)
	{
		if (it->name == name)
		{
			return *it;
		}
	}

	cout << "Contact not found";
}

vector<Contacte> Agenda::getFriendList()
{
	return contacts;
}

void Agenda::deleteFriend(string name)
{
	for (auto it = contacts.begin(); it != contacts.end(); it++)
	{
		if (it->name == name)
		{
			contacts.erase(it);
			return;
		}
	}
}

void Agenda::add(Contacte newContact)
{
	contacts.push_back(newContact);
}