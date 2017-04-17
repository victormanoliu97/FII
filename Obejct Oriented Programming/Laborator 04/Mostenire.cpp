#include "Mostenire.h"
#include <cmath>
#define M_PI 3.14

// Dreptunghi

Dreptunghi::Dreptunghi(int lungime, int latime)
{
	Lungime = lungime;

	Latime = latime;
}

double Dreptunghi::ComputeArea()
{

	return Latime*Lungime;
}

const char * Dreptunghi::GetName()
{
	return "Dreptunghi";
}


// Cerc


double Cerc::ComputeArea()
{
	float raza1 = pow(Raza, 2);

	return 3.14*raza1;
}

const char * Cerc::GetName()
{
	return "Cerc";
}

Cerc::Cerc(int raza)
{
	Raza = raza;
}


// Triunghi

Triunghi::Triunghi(int x1, int y1, int x2, int y2, int x3, int y3)
{
	X1 = x1;

	Y1 = y1;

	X2 = x2;

	Y2 = y2;

	X3 = y3;

	Y3 = y3;

}

double Triunghi::ComputeArea()
{
	return (X1*(Y2 - Y3) + X2*(Y3 - Y1) + X3*(Y1 - Y2)) / 2;
}

const char * Triunghi::GetName()
{
	return "Triunghi";
}
