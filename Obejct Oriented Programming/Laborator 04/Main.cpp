#include"Mostenire.h"
#include <iostream>
#include <windows.h>
using namespace std;
typedef int(*Compute)(int, int);
typedef char* (*GetName)(void);
#define PLUGIN_COUNT 4

int main()
{
	Forma *forma[10];


	Dreptunghi d(5, 3);


	Triunghi t(78,91,36,45,58,66);

	Cerc c(30);

	forma[0] = &d;
	forma[1] = &t;
	forma[2] = &c;

	cout << "Aria " << forma[0]->GetName() << " " << forma[0]->ComputeArea() << endl;
	cout << "Aria " << forma[1]->GetName() << " " << forma[1]->ComputeArea() << endl;
	cout << "Aria " << forma[2]->GetName() << " " << forma[2]->ComputeArea() << endl;

	int x, y;

	cout << "Intoduceti X:" << endl;

	cin >> x;

	cout << "Introduceti Y:" << endl;

	cin >> y;


	HINSTANCE f[PLUGIN_COUNT];
	int i;
	string modules[PLUGIN_COUNT] = { "Adunare DLL.dll","Scadere DLL.dll","Inmultire DLL","Impartire DLL" };
	Compute computations[PLUGIN_COUNT];
	GetName getnames[PLUGIN_COUNT];

	//deschidere librarii si incarcare functii
	for (i = 0; i<PLUGIN_COUNT; i++)
	{
		f[i] = LoadLibraryA(modules[i].c_str());

		if (!f[i])
		{
			cout << "Nu am putut incarca DLL-ul specificat!" << endl;
			return 0;
		}

		computations[i] = (Compute)GetProcAddress(f[i], "Computation");
		getnames[i] = (GetName)GetProcAddress(f[i], "GetName");

		if (!computations[i])
		{
			printf("Nu am gasit functia [Compute] in [%s]\n", modules[i].c_str());
			return 0;
		}

		if (!getnames[i])
		{
			printf("Nu am gasit functia [GetName] in [%s]\n", modules[i].c_str());
			return 0;
		}
	}

	//Apel functii
	for (i = 0; i<PLUGIN_COUNT; i++)
		printf("Calcul [%s(%d,%d)]= %d\n", getnames[i](), x, y, computations[i](x, y));

	//inchidere librarii
	for (i = 0; i<PLUGIN_COUNT; i++)
		FreeLibrary(f[i]);


	return 0;

}