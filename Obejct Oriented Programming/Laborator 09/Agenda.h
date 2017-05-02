#include<iostream>
#include<vector>
#include<string>
#include"Contacte.h"

using namespace std;

class Agenda
{
private:
	vector<Contacte> contacts;

public:
	Contacte& findByName(string name);

	vector<Contacte> getFriendList();

	void deleteFriend(string name);

	void add(Contacte newContact);
};