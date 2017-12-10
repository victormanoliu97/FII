#ifndef POPULATION_H
#define POPULATION_H

#include<vector>
#include"Point.h"
#include"MathematicalDomain.h"
#include"Function.h"
#include"CandidateSolution.h"

class Population
{
private:
	vector<CandidateSolution> vals;
	size_t pop_size;
	size_t tournament_size;
	Function func;
public:
	Population(size_t p_size, size_t t, Function f)
		: func(f), pop_size(p_size), tournament_size(t)
	{
		for (int i = 0; i < pop_size; ++i)
		{
			CandidateSolution s(f.get_domain(), f.get_args_number(), f.get_precission());
			s.make_random();
			vals.push_back(s);
		}
	}

	void select()
	{
		int i = 0;

		default_random_engine engine;
		uniform_int_distribution<int> distribution(0, pop_size - 2);

		while (i < tournament_size)
		{
			int index1 = distribution(engine);
			int index2 = distribution(engine);

			while (index1 == index2)
			{
				index2 = distribution(engine);
			}

			double fitness1 = func.eval(vals[index1]);
			double fitness2 = func.eval(vals[index2]);

			if (fitness1 > fitness2)
			{
				vals[index2] = vals[index1];
			}
			else
			{
				vals[index1] = vals[index2];
			}

			i++;
		}
	}

	void crossover()
	{
		default_random_engine engine;
		uniform_int_distribution<int> distribution(0, pop_size);
		uniform_int_distribution<int> distribution2(0,
			vals[0].get_sollution_size() * vals[0].get_raw_val()[0].size() - 1);

		for (int i = 0; i < pop_size; i++)
		{
			//while (!func.in_domain(chromozome1) && !func.in_domain(chromozome2))
			//{
			int index1 = distribution(engine);
			int index2 = distribution(engine);

			while (index1 == index2)
			{
				index2 = distribution(engine);
			}

			if (index1 > index2)
			{
				int tmp = index1;
				index1 = index2;
				index2 = tmp;
			}

			int point1 = distribution2(engine);
			int point2 = distribution2(engine);

			while (point1 == point2)
			{
				point2 = distribution2(engine);
			}

			if (point1 > point2)
			{
				int tmp = point1;
				point1 = point2;
				point2 = tmp;
			}


			vector<vector<bool>> tmp = vals[index1].get_raw_val();
			vector<vector<bool>> chromozome2 = vals[index2].get_raw_val();
			vector<vector<bool>> chromozome1 = vals[index1].get_raw_val();

			int counter = 0;
			for (int i = 0; i < chromozome1.size(); ++i)
			{
				for (int j = 0; j < chromozome1[i].size(); ++j)
				{
					if (counter > point1)
					{
						chromozome1[i][j] = chromozome2[i][j];
					}

					counter++;
				}
			}

			counter = 0;

			for (int i = 0; i < chromozome2.size(); ++i)
			{
				for (int j = 0; j < chromozome2[i].size(); ++j)
				{
					if (counter < point2)
					{
						chromozome2[i][j] = tmp[i][j];
					}
					counter++;
				}
			}

			vals[index1].set_vals(chromozome1);
			vals[index2].set_vals(chromozome2);
		}

		// }
		//vals[index1].set_vals(chromozome1);
		//vals[index2].set_vals(chromozome2);
	}

	void mutate()
	{
		default_random_engine engine;
		uniform_int_distribution<int> distribution(0, 1);
		for (int i = 0; i < pop_size; ++i)
		{
			int r = distribution(engine);

			if (r)
			{
				vals[i].mutate();
			}
		}
	}

	CandidateSolution get_fittest()
	{
		double fittest = func.eval(vals[0]);
		CandidateSolution s = vals[0];

		for (int i = 1; i < pop_size; ++i)
		{
			if (func.eval(vals[i]) > fittest)
			{
				fittest = func.eval(vals[i]);
				s = vals[i];
			}
		}

		return s;
	}
};

#endif