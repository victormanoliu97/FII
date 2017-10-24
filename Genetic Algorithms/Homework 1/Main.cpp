#include<iostream>
#include<cmath>
#include<stdio.h>

// auxiliary classes for defining a point in the dimension and declaring as variable the specified functions

#include"Punct.h"
#include"FunctionDomains.h"
#include"Function.h"

#define M_PI 3.14

// constants for the simulated annealing algorithm

#define MINIMUM_TEMPERATURE 0.00001
#define ITERATIONS 100
#define ALPHA 0.9
#define INITIAL_TEMPERATURE 1.0
#define MAX_TEMPERATURE 0.99

using namespace std;

CandidateSolution random_candidate_sollution(Function func)
{
	CandidateSolution rand_sol(func.get_domain(), func.get_args_number(), func.get_precission());
	for (int i = 0; i < rand_sol.get_sollution_size(); ++i)
	{
		if (rand() % 2)
		{
			rand_sol.flip(i);
		}
	}

	// rand_sol.print();
	return rand_sol;
}

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

Punct simmulated_annealing(Function func, int max_iterations, double temp_step)
{
	double temperature = MAX_TEMPERATURE;
	CandidateSolution max_hilltop = random_candidate_sollution(func);
	double max_hilltop_fitness = func.eval(max_hilltop);

	while (temperature > 0)
	{
		// for debug purposes
		//	std::cout << max_hilltop.to_real()[0] << std::endl;

		for (int i = 0; i < max_iterations; ++i)
		{
			unsigned int bit_pos = rand() % max_hilltop.get_sollution_size();
			CandidateSolution hilltop = max_hilltop;
			hilltop.flip(bit_pos);
			double fitness = func.eval(hilltop);

			if (fitness < max_hilltop_fitness)
			{
				max_hilltop = hilltop;
				max_hilltop_fitness = fitness;
			}
			else
			{
				double probability = fRand(0.0, 0.99);
				double acceptance_probability = exp(-1 * fabs(max_hilltop_fitness - fitness) / temperature);

				if (probability < acceptance_probability)
				{
					max_hilltop = hilltop;
					max_hilltop_fitness = fitness;
				}
			}
		}
		temperature *= temp_step;
	}

	return Punct(max_hilltop.to_real());
}

Punct hil_climbing(Function func, int max_number_of_iterations)
{
	CandidateSolution max_hilltop = random_candidate_sollution(func);
	double max_fitness = func.eval(max_hilltop);

	for (int i = 0; i < max_number_of_iterations; ++i)
	{
		unsigned int bit_position = rand() % max_hilltop.get_sollution_size();
		CandidateSolution hilltop = max_hilltop;
		hilltop.flip(bit_position);
		double fitness = func.eval(hilltop);

		if (fitness <= max_fitness)
		{
			max_fitness = fitness;
			max_hilltop = hilltop;
		}
	}

	return Punct(max_hilltop.to_real());
}


/**
* Raw hard-coded expression of the ackley function.
*/
double ackley_function(Punct p)
{
	double a = 20;;
	double b = 0.2;
	double c = 2 * M_PI;

	vector<double> vals = p.get_vals();

	double sum_pows = 0.0;
	double sum_cos = 0.0;
	for (auto it = vals.begin(); it != vals.end(); ++it)
	{
		sum_pows += pow(*it, 2.0);
		sum_cos += cos(c * (*it));
	}

	return -a * exp(-b * sqrt((1.0 / vals.size()) * sum_pows))
		- exp((1.0 / vals.size()) * sum_cos) + a + exp(1);
}

/**
* Raw hard-coded expression of the de jong's function.
*/
double de_jong_function(Punct p)
{
	double sum = 0.0;

	for (int i = 0; i < p.get_vals().size(); ++i)
	{
		sum += pow(p.get_vals()[i], 2.0);
	}

	return sum;
}


/**
* Raw hard-coded expression of the Schwefel's function.
*/
double schwefel_function(Punct p)
{
	double sum = 0.0;
	for (int i = 0; i < p.get_vals().size(); ++i)
	{
		sum += p.get_vals()[i] * sin(sqrt(fabs(p.get_vals()[i])));
	}

	return sum;
}


/**
* @brief hard-coded expression for the six hump...
*/
double six_hump_function(Punct p)
{
	double x1 = p.get_vals()[0];
	double x2 = p.get_vals()[1];

	return (4 - 2.1 * pow(x1, 2.0) + pow(x1, 4.0 / 3.0)) * pow(x1, 2.0) +
		x1 * x2 + (-4 + 4 * pow(x2, 2.0)) * pow(x2, 2.0);
}



int main()
{
	FunctionDomains ackley_domain(-32.768, 32.768);
	Function func(ackley_function, ackley_domain, 3, 2);
	Punct computed_sol_annealing = simmulated_annealing(func, ITERATIONS, MINIMUM_TEMPERATURE);
	Punct computed_sol = hil_climbing(func, ITERATIONS);

	std::cout << "Computed solution for Ackley Function using the Hill Climbing: " <<" "<< ackley_function(computed_sol) << std::endl;
	std::cout << "The maximum and the minimum values found are: " << std::endl;
	std::cout << computed_sol.get_vals()[0] << " "
		<< computed_sol.get_vals()[1] << std::endl;

	std::cout << endl;

	std::cout << "Computed solution for Ackley Function using the Simulated Anealing: " << " " << ackley_function(computed_sol_annealing) << std::endl;
	std::cout << "The maximum and the minimum values found are: " << std::endl;
	std::cout << computed_sol_annealing.get_vals()[0] << " "
		<< computed_sol_annealing.get_vals()[1] << std::endl;

	std::cout << endl;

	FunctionDomains de_jong_domain(-5.12, 5.12);
	Function de_jong(de_jong_function, de_jong_domain, 3, 5);
	Punct computed_sol_climbing = hil_climbing(de_jong, ITERATIONS);
	Punct computed_sol_annealing_jong = simmulated_annealing(func, ITERATIONS, MINIMUM_TEMPERATURE);
	std::cout << "Computed solution for deJong function using the hill climbing is :  "<<de_jong_function(computed_sol_climbing)<<std::endl;

	std::cout << "The maximum and the minimum values found are: " << std::endl;
	std::cout << computed_sol_climbing.get_vals()[0] << " "
		<< computed_sol_climbing.get_vals()[1] << std::endl;

	std::cout << endl;

	std::cout << "Computed solution for deJong using the Simulated Anealing: " << " " << de_jong_function(computed_sol_annealing_jong) << std::endl;
	std::cout << "The maximum and the minimum values found are: " << std::endl;
	std::cout << computed_sol_annealing_jong.get_vals()[0] << " "
		<< computed_sol_annealing_jong.get_vals()[1] << std::endl;

	std::cout << endl;
	


	FunctionDomains schwefel_domain(-500, 500);
	Function schewefel(schwefel_function, schwefel_domain, 3, 7);
	Punct computed_sol_climbing_ackley = hil_climbing(schewefel, ITERATIONS);
	Punct computed_sol_annealing_ackley = simmulated_annealing(func, ITERATIONS, MINIMUM_TEMPERATURE);

	std::cout << "Computed solution for Scwefel using hill climbing is: " << ackley_function(computed_sol_climbing_ackley) << endl;

	std::cout << "The maximum and the minimum values found are: " << computed_sol_climbing_ackley.get_vals()[0] << " " << computed_sol_annealing_ackley.get_vals()[1] << endl;

	std::cout << endl;

	std::cout << "Computed solution for Scwefel using annealing is : " << ackley_function(computed_sol_annealing_ackley) << endl;

	std::cout << "The maximum and the minimum values found are: " << computed_sol_annealing_ackley.get_vals()[0] << " " << computed_sol_annealing_ackley.get_vals()[1] << endl;

	std::cout << endl;

	FunctionDomains six_hump_domain(-3, 3);
	Function six_hump(six_hump_function, six_hump_domain, 2, 2);
	Punct computed_sol_climbing_sixhump = hil_climbing(six_hump, ITERATIONS);
	Punct computed_sol_annealing_sixhump = simmulated_annealing(func, ITERATIONS, MINIMUM_TEMPERATURE);

	std::cout << "Computed solution for Six Hump using hill climbing is: " << six_hump_function(computed_sol_climbing_sixhump) << endl;

	std::cout << "The maximum and the minimum values found are: " << computed_sol_climbing_sixhump.get_vals()[0] << " " << computed_sol_annealing_sixhump.get_vals()[1] << endl;

	std::cout << endl;

	std::cout << "Computed solution for Six hump using annealing is: " << six_hump_function(computed_sol_annealing_sixhump) << endl;

	std::cout << "The maximum and the minimum values found are: " << computed_sol_annealing_sixhump.get_vals()[0] << " " << computed_sol_annealing_sixhump.get_vals()[1] << endl;

	std::cout <<  endl;

	return 0;
}