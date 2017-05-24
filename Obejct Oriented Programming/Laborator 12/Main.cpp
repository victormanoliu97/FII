#include<iostream>
#include<vector>
#include<string>
#include"Fruit.h"
#include"Visitor.h"

using namespace std;

int main()
{
	vector<Fruit*> fruits
	{
		new Orange("10% C Vitamin"), new Apple(), new Lemon(), new Grapefruit()
	};

	CVitaminVisitor *v = new CVitaminVisitor();

	for (auto it = fruits.begin(); it != fruits.end(); it++)
	{
		(*it)->accept(v);
	}

	return 0;
}