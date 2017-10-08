#include"Punct.h"
#include"FunctionDomains.h"
#include<vector>
#include<stdarg.h>

class MathematicalFunction
{
private:
	double(*function)(Punct&);
	std::vector<FunctionDomains> domains;
	int variables;

public:

	void setFunction(double(*funct)(Punct&))
	{
		function = funct;
	}

	void setVariables(int myVar)
	{
		variables = myVar;
	}

	void setDomains(std::vector<FunctionDomains> myDomain)
	{
		domains = myDomain;
	}

	double operator() (double x, ...)
	{
		std::vector<double> vals;

		vals.push_back(x);

		va_list argumentList;

		va_start(argumentList, x);

		for (int i = 0; i < variables - 1; i++)
		{
			double tmp = va_arg(argumentList, double);

			vals.push_back(tmp);
		}

		va_end(argumentList);

		return (*function)(Punct(vals));
	}

	double operator() (Punct &punct)
	{
		return (*function)(punct);
	}

	std::vector<FunctionDomains> getDomains()
	{
		return domains;
	}

	int getVariables()
	{
		return variables;
	}
};

