#include<iostream>
#include <vector>
#include <random>
#include <time.h>

#include"Point.h"
#include"MathematicalDomain.h"
#include"Function.h"
#include"CandidateSolution.h"
#include"Population.h"
#include"GeneticAlgorithm.h"

#define M_PI 3.14159265358979323846

using std::cout;
using std::endl;
using std::vector;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::default_random_engine;

#define POPULATION_SIZE 100
#define ITERATIONS 100

double ackley_function(RawPoint p)
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


double de_jong_function(RawPoint p)
{
	double sum = 0.0;

	for (int i = 0; i < p.get_vals().size(); ++i)
	{
		sum += pow(p.get_vals()[i], 2.0);
	}

	return sum;
}


double schwefel_function(RawPoint p)
{
	double sum = 0.0;
	for (int i = 0; i < p.get_vals().size(); ++i)
	{
		sum += p.get_vals()[i] * sin(sqrt(fabs(p.get_vals()[i])));
	}

	return sum;
}

double schwefel_function_pos(RawPoint p)
{
	return -1 * schwefel_function(p) + 5000;
}



double six_hump_function(RawPoint p)
{
	double x1 = p.get_vals()[0];
	double x2 = p.get_vals()[1];

	return (4 - 2.1 * pow(x1, 2.0) + pow(x1, 4.0 / 3.0)) * pow(x1, 2.0) +
		x1 * x2 + (-4 + 4 * pow(x2, 2.0)) * pow(x2, 2.0);
}

double rastrigin_function(RawPoint p)
{
	double x1 = p.get_vals().size();
	double sum = 0;

	for (int i = 0; i < p.get_vals().size(); i++)
	{
		sum += pow(p.get_vals()[i], 2) - 10 * cos(2 * M_PI*p.get_vals()[i]);
	}

	return 10 * x1 + sum;
}


double to_optimize(RawPoint p)
{

	double x = p.get_vals()[0];

	return pow(x, 3.0) -
		60 * pow(x, 2.0) +
		900 * x +
		100;
}

int main()
{

	Domain rastrigin_domain(-5.12, 5.12);
	Function func(rastrigin_function, rastrigin_domain, 2, 5);

	Population p(1000, 1000, func);
	GeneticAlgorithm g(p, ITERATIONS);

	RawPoint point = g.run();

	for (int i = 0; i < point.get_vals().size(); ++i)
	{
		std::cout << point.get_vals()[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Time in seconds since the launch: ";

	float t1 = clock();

	std::cout << t1 / CLOCKS_PER_SEC;

	return 0;
}
