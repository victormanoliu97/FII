#include<iostream>
#include<exception>
#include "Agenda.h"

class ContactNotFound : public exception
{
	virtual const char* what() const throw()
	{
		return "Contact not found";
	}
};

Contacte& Agenda::findByName(string name)
{
	ContactNotFound ContactNotFoundMessage;

	try
	{

		for (auto it = contacts.begin(); it != contacts.end(); it++)
		{
			if (it->name != name)
			{
				throw ContactNotFoundMessage;
			}
			else
			{
				return *it;
			}
		}

	}
	catch (exception& e)
	{
		cout << e.what();
	}
}

vector<Contacte> Agenda::getFriendList()
{
	return contacts;
}

void Agenda::deleteFriend(string name)
{

	ContactNotFound ContactNotFoundMessage;

	try
	{
		for (auto it = contacts.begin(); it != contacts.end(); it++)
		{
			if (it->name != name)
			{
				throw ContactNotFoundMessage;
			}
			else
			{
				contacts.erase(it);
				return;
			}
		}
	}
	catch (exception& e)
	{
		cout << e.what();
	}
}

void Agenda::add(Contacte newContact)
{
	contacts.push_back(newContact);
}