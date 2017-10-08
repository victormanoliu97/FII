#ifndef FUNCTIONDOMAINS_H
#define FUNCTIONDOMAINS_H

class FunctionDomains
{
private:
	double minimumBound;
	
	double maximumBound;

public:
	FunctionDomains(double lowBound, double upBound)
	{
		minimumBound = lowBound;

		maximumBound = upBound;
	}

	double GetTheLowerBound()
	{
		return minimumBound;
	}

	double GetTheUpperBound()
	{
		return maximumBound;
	}
};

#endif

