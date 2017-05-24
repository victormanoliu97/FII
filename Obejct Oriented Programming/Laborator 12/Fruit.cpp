#include "Fruit.h"
#include"Visitor.h"

Orange::Orange(string prop)
{
	cVitamin = prop;
}

void Orange::accept(Visitor *v)
{
	v->visit(*this);
}

string Orange::getCVitamin() const
{
	return cVitamin;
}

void Apple::accept(Visitor *v)
{
	v->visit(*this);
}

void Lemon::accept(Visitor *v)
{
	v->visit(*this);
}

void Grapefruit::accept(Visitor *v)
{
	v->visit(*this);
}
