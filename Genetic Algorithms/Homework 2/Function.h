#ifndef FUNCTION_H
#define FUNCTION_H

#include"Point.h"
#include"MathematicalDomain.h"
#include"CandidateSolution.h"

class Function
{
private:
	double(*func)(RawPoint point);
	Domain domain;
	unsigned int precission;
	unsigned int args_number;
public:
	Function(double(*f)(RawPoint point), Domain d, unsigned int p, unsigned int num)
		: func(f), domain(d), precission(p), args_number(num)
	{
	}

	double eval(CandidateSolution sol)
	{
		vector<double> double_sol = sol.to_real();
		RawPoint p(double_sol);

		if (func(p) < 0)
		{
			return func(p);
		}
		else
		{
			return -1 * func(p);
		}
	}

	unsigned int get_precission() const
	{
		return precission;
	}

	unsigned int get_args_number() const
	{
		return args_number;
	}

	Domain get_domain() const
	{
		return domain;
	}
};

#endif 