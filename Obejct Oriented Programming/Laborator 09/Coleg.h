#include<iostream>
#include<string>
#include"Contacte.h"

using namespace std;

class Coleg : public Contacte
{
public:
	int phoneNumber;
	string company;
	string address;
};