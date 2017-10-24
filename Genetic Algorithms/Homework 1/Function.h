#include"Punct.h"
#include"FunctionDomains.h"
#include"CandidateSolution.h"

class Function
{
private:
	double(*func)(Punct point);
	FunctionDomains domain;
	unsigned int precission;
	unsigned int args_number;
public:
	Function(double(*f)(Punct point), FunctionDomains d, unsigned int p, unsigned int num)
		: func(f), domain(d), precission(p), args_number(num)
	{
	}

	double eval(CandidateSolution sol)
	{
		std::vector<double> double_sol = sol.to_real();
		Punct p(double_sol);

		return func(p);
	}

	unsigned int get_precission() const
	{
		return precission;
	}

	unsigned int get_args_number() const
	{
		return args_number;
	}

	FunctionDomains get_domain() const
	{
		return domain;
	}

	
};
