#ifndef VISITOR_H__
#define VISITOR_H__

#include<iostream>
#include<string>
#include"Fruit.h"

using namespace std;

class Orange;
class Apple;
class Lemon;
class Grapefruit;

class Visitor
{
public:

	Visitor() {}

	virtual void visit(Orange &orange) = 0;

	virtual void visit(Apple &apple) = 0;

	virtual void visit(Lemon &lemon) = 0;

	virtual void visit(Grapefruit &grapefruit) = 0;
};

class CVitaminVisitor : public Visitor
{

public:

    CVitaminVisitor() {}

	void visit(Orange &orange);

	void visit(Apple &apple);

	void visit(Lemon &lemon);

	void visit(Grapefruit &grapefruit);
};

#endif
