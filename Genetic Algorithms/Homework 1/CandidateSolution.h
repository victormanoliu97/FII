using std::vector;
using std::pow;
using std::round;


class CandidateSolution
{
private:
	vector<vector<bool>> solution_value;
	FunctionDomains solution_domain;
	unsigned int precission;
	unsigned int solution_args;
	unsigned int solution_size;

	vector<unsigned int> decimal_value()
	{
		vector<unsigned int> dec_val;
		for (int i = 0; i < solution_value.size(); ++i)
		{
			dec_val.push_back(0);
			for (int j = 0; j < solution_size; ++j)
			{
				dec_val[i] += pow(2, j) * solution_value[i][j];
			}
		}
		return dec_val;
	}

	void init_zero()
	{
		solution_size = round(log2((solution_domain.get_upper_bound()
			- solution_domain.get_lower_bound()) * pow(10, precission)));

		for (int i = 0; i < solution_args; ++i)
		{
			solution_value.push_back(vector<bool>());
			for (int j = 0; j < solution_size; ++j)
			{
				solution_value[i].push_back(0);
			}
		}
	}
public:
	CandidateSolution(FunctionDomains d, unsigned int sol_args, unsigned int p)
		: solution_domain(d), precission(p), solution_args(sol_args)
	{
		init_zero();
	}

	vector<double> to_real()
	{
		vector<unsigned int> dec_vals = decimal_value();
		vector<double> real_solution;
		for (int i = 0; i < dec_vals.size(); ++i)
		{
			real_solution.push_back(solution_domain.get_lower_bound() + dec_vals[i]
				* ((solution_domain.get_upper_bound() - solution_domain.get_lower_bound())
					/ (pow(2, solution_size) - 1)));
		}
		return real_solution;
	}

	void flip(unsigned int n)
	{

		for (int i = 0; i < solution_value.size(); ++i)
		{
			solution_value[i][n] = !solution_value[i][n];
		}
		/*
		int index = rand() % solution_value.size();
		solution_value[index][n] = !solution_value[index][n];
		*/
	}

	/**
	* @brief Made for debug purposes.
	*/
	void print() const
	{
		for (int i = 0; i < solution_value.size(); ++i)
		{
			for (int j = 0; j < solution_value[i].size(); ++j)
			{
				std::cout << solution_value[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	/**
	* @brief getter.
	*/
	unsigned int get_sollution_size() const
	{
		return solution_size;
	}
};