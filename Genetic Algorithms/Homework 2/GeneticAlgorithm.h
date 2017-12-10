#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include"Population.h"

class GeneticAlgorithm
{
	Population population;
	size_t iterations;

public:
	GeneticAlgorithm(Population p, int it)
		: population(p), iterations(it)
	{
	}

	RawPoint run()
	{
		int i = 0;
		while (i < iterations)
		{
			population.select();
			population.crossover();
			population.mutate();

			++i;
		}

		return population.get_fittest().to_real();
	}

};

#endif // !GENETICALGORITHM_H