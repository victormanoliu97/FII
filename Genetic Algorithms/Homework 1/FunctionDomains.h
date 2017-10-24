#ifndef FUNCTIONDOMAINS_H
#define FUNCTIONDOMAINS_H

class FunctionDomains
{
private:
	double lower_bound;
	double upper_bound;
public:
	FunctionDomains(double lb, double ub)
		:lower_bound(lb), upper_bound(ub)
	{}

	double get_lower_bound() const
	{
		return lower_bound;
	}

	double get_upper_bound() const
	{
		return upper_bound;
	}
};

#endif

