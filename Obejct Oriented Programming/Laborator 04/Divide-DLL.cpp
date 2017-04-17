#include <Windows.h>
#include <iostream>
using namespace std;

#define DLL_API __declspec(dllexport) 

extern "C" {
	DLL_API int Computation(int a, int b);
	DLL_API char *GetName(void);
}

int Computation(int a, int b)
{
	return a / b;
}

char *GetName(void)
{
	return "Impartirea";
}

