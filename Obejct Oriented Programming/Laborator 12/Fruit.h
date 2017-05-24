#ifndef FRUIT_H__
#define FRUIT_H__

#include"Visitor.h"
#include<string>

using namespace std;

class Fruit
{
private:
	string color;

	int size;

	string taste;

public:

	virtual void accept(class Visitor *ov) = 0;
};

class Orange : public Fruit
{
private:
	string cVitamin;

public:

	Orange(string prop);

	string getCVitamin() const;

	void accept(Visitor *v);
};

class Apple : public Fruit
{
public:

	void accept(Visitor *v);
};

class Lemon : public Fruit
{
public:

	void accept(Visitor *v);
};

class Grapefruit : public Fruit
{
public:

	void accept(Visitor *v);
};

#endif