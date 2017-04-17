#include <iostream>
using namespace std;

struct Student
{
	int matricola;
	char nume[20];
	char adresa[30];
	char localitate[20];
	char e_mail[20];
	char telefon[15];
	void Afisare()
	{
		cout << "Matricola: " << matricola << endl;
		cout << "Matricola: " << nume << endl;
		cout << "Matricola: " << adresa << endl;
		cout << "Matricola: " << localitate << endl;
		cout << "Matricola: " << e_mail << endl;
		cout << "Matricola: " << telefon << endl;
	}
};

struct NodDate
{
	NodDate *urm;
	Student data;
};


class HashStudent
{
	int size;
	NodDate ** elem;
	
	int HashFunction(int cheie)
	{
		return cheie%size;
	};
	//aloca memorie pentru structura si initializeaza cu null valorile
	void AlocaMemorie()
	{
		elem = new NodDate*[size];
		for (int i = 0; i<size; i++)
			elem[i] = NULL;
	}

	void ElibereazaMemorieLista(NodDate *&);

public:
	HashStudent() :size(101)
	{
		AlocaMemorie();
	}

	~HashStudent();

	HashStudent(int iSize) : size(iSize)
	{
		AlocaMemorie();
	}
	int Insereaza(Student data);
	Student Cauta(int matricola);
	int Sterge(int matricola);
	void HashStudent::Afiseaza();
};

int HashStudent::Insereaza(Student s)
{
	int index = -1;
	if (s.matricola<0)
		return index;
	if (elem != NULL)
	{
		index = HashFunction(s.matricola);
		//prima inregistrare
		NodDate *nod_nou = new NodDate;;
		nod_nou->urm = NULL;
		nod_nou->data = s;
		if (elem[index] == NULL)
		{
			elem[index] = nod_nou;
		}
		else //coliziune
		{
			NodDate *t = elem[index];
			while (t->urm != NULL)
				t = t->urm;
			t->urm = nod_nou;
		}
	}
	return index;
}

Student HashStudent::Cauta(int matricola)
{
	//valoare de retur pentru cazurile in care nu este gasit elementul
	Student s_negasit;
	s_negasit.matricola = -1;
	if (matricola < 0)
	{
		return s_negasit;
	}
		
	if (elem != NULL)
	{
		int index = HashFunction(matricola);

		if (elem[index] == NULL)
		{
			return s_negasit;
		}
		else
		{
			if (elem[index]->data.matricola == matricola)
			{
				return elem[index]->data;
			}	
			else//coliziune
			{
				NodDate *t = elem[index];
				while (t != NULL && t->data.matricola != matricola)
				{
					t = t->urm;
				}
					
				if (t == NULL)
				{
					return s_negasit;
				}
				else
				{
					return t->data;
				}	
			}
		}
	}
	//neinitializat sau nu exista inregistrarea
	return s_negasit;
}
//functie recursiva care eliberaza memoria ocupata de nodurile listei
void HashStudent::ElibereazaMemorieLista(NodDate *&inceput)
{
	if (inceput == NULL)
	{
		return;
	}	
	else
	{
		ElibereazaMemorieLista(inceput->urm);
		cout << "Eliminat nodul cu codul: " << inceput->data.matricola << endl;
		delete inceput;
	}
}
//elibereaza memoria ocupa de tabela de dispesie
HashStudent::~HashStudent()
{
	if (elem != NULL)
	{
		for (int i = 0; i<size; i++)
			ElibereazaMemorieLista(elem[i]);
		delete[] elem;
	}
}

int HashStudent::Sterge(int matricola)
{
	if (matricola < 0)
	{
		return matricola;
	}	
	if (elem != NULL)
	{
		int index = HashFunction(matricola);
		if (elem[index] == NULL)
		{
			return -1;
		}
		else
		{
			//este primul
			if (elem[index]->data.matricola == matricola)
			{
				if (elem[index]->urm == NULL)
				{
					delete elem[index];
					elem[index] = NULL;
				}
				else//mai sint si alte elemente in lista
				{
					NodDate *t = elem[index];
					elem[index] = t->urm;
					delete t;
				}
			}
			else//coliziune, nu este primul, il cautam
			{
				NodDate *t = elem[index];
				while (t->urm != NULL && t->urm->data.matricola != matricola)
				{
					t = t->urm;
				}	
				if (t->urm == NULL)
					return -1;
				else//t->urm.data.matricola == matricola
				{
					NodDate *p = t->urm;
					if (p->urm == NULL)
					{
						t->urm = NULL;
						delete p;
					}
					else
					{
						t->urm = p->urm;
						delete p;
					}
				}
			}
			return index;
		}
		return -1;
	}
}
//Afiseaza continutul tabelei de dispersie
void HashStudent::Afiseaza()
{
	if (elem != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			if (elem[i] != NULL)
			{
				NodDate *t = elem[i];
				while (t != NULL)
				{
					cout << "S-a inserat in pozitia: " << i << " cheia: " << t->data.matricola << endl;
					t = t->urm;
				}
			}
		}
	}
}
