#ifndef RAWPOINT_H
#define RAWPOINT_H

#include<vector>

using std::cout;
using std::vector;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::default_random_engine;

class RawPoint
{
private:
	vector<double> vals;
public:
	RawPoint(vector<double> v)
	{
		vals = v;
	}

	vector<double> get_vals() const
	{
		return vals;
	}
};

#endif
