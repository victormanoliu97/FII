#include "Visitor.h"
#include"Fruit.h"


void CVitaminVisitor::visit(Orange &orange)
{
	cout << orange.getCVitamin() << endl;
}

void CVitaminVisitor::visit(Apple &apple)
{
	cout << "Proprietate invalida.Nu este fruct acitric" << endl;
}

void CVitaminVisitor::visit(Lemon &lemon)
{
	cout << "Proprietate invalida.Nu este fruct acitric" << endl;
}

void CVitaminVisitor::visit(Grapefruit &grapefruit)
{
	cout << "Proprietate invalida.Nu este fruct acitric" << endl;
}