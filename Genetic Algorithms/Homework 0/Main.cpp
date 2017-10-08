#include<iostream>
#include<cmath>
#include<stdio.h>

// auxiliary classes for defining a point in the dimension and declaring as variable the specified functions

#include"Punct.h"
#include"FunctionDomains.h"
#include"MathematicalFunction.h"

#define M_PI 3.14

// constants for the simulated annealing algorithm

#define MINIMUM_TEMPERATURE 0.00001
#define ITERATIONS 100
#define ALPHA 0.9
#define INITIAL_TEMPERATURE 1.0

using namespace std;

static float generate_rand_double(double low, double high)
{
	return low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low)));
}

Punct get_initial_solution(MathematicalFunction& f)
{
	vector<double> vals;

	for (int i = 0; i < f.getVariables(); i++)
	{
		double lower_bound = (f.getDomains()[i]).GetTheLowerBound();

		double upper_bound = (f.getDomains()[i]).GetTheUpperBound();

		vals.push_back(generate_rand_double(lower_bound, upper_bound));
	}

	return Punct(vals);
}

bool acceptProbability(double old_cost, double new_cost, double temperature)
{
	return exp((old_cost - new_cost) / temperature);
}

Punct simulated_annealing(MathematicalFunction &mf)
{
	Punct solution = get_initial_solution(mf);

	double oldCost = mf(solution);

	double temperature = INITIAL_TEMPERATURE;

	while (temperature > MINIMUM_TEMPERATURE)
	{
		for (int i = 0; i < ITERATIONS; i++)
		{
			Punct newSolution = get_initial_solution(mf);

			double newCost = mf(newSolution);

			if ((acceptProbability(oldCost, newCost, temperature)) > rand() % 2 )
			{
				solution = newSolution;
				oldCost = newCost;
			}
		}

		temperature = temperature * ALPHA;
	}

	return solution;
}


template<int n>
double deJongIFunction(Punct &myPunct)
{
	double result = 0;

	vector<double> vals = myPunct.GetValues();

	for (int i = 0; i < n; i++)
	{
		result = result + pow(vals[i], 2.0);
	}

	return result;
}

template<int n>
double scwefel7Function(Punct &myPunct)
{
	double result = 0;

	vector<double> vals = myPunct.GetValues();

	for (int i = 0; i < n; i++)
	{
		result = result + -1 * vals[i] * sin(sqrt(abs(vals[i])));
	}

	return result;
}

template<int n>
double ackkeyPathFunction(Punct &myPunct)
{
	double result = 0;

	vector<double> vals = myPunct.GetValues();

	const int a = 20;

	const int b = 0.2;

	double sum1 = 0;

	double sum2 = 0;

	for (int i = 0; i < n; i++)
	{
		sum1 = sum1 + pow(vals[i], 2);

		sum2 = sum2 + cos((2 * M_PI) * vals[i]);
	}

	result += -a * exp(-b * sqrt(1 / n * sum1)) - exp(1 / n) * sum2 + a + exp(1);

	return result;
}

int main()
{
	//Computing the values for deJong 1
	MathematicalFunction de_jong;
	de_jong.setFunction(deJongIFunction<4>);
	de_jong.setDomains(vector<FunctionDomains> {
		FunctionDomains(-5.12, 5.12),
		FunctionDomains(-5.12, 5.12),
		FunctionDomains(-5.12, 5.12),
		FunctionDomains(-5.12, 5.12)
	});

	de_jong.setVariables(4);

	Punct average_solDeJong(vector<double> { 0.0, 0.0, 0.0, 0.0});
	Punct max_sol2(vector<double> {-DBL_MAX, -DBL_MAX, -DBL_MAX, -DBL_MAX});
	Punct min_sol2(vector<double> {DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX});


	cout << "Computing values for deJong function: " << endl;

	for (int i = 0; i < 30; i++)
	{
		Punct &deJongPoint = simulated_annealing(de_jong);

		vector<double> g = deJongPoint.GetValues();

		vector<double> currentSolutionDeJong = average_solDeJong.GetValues();

		average_solDeJong = Punct(vector<double> {
			g[0] + currentSolutionDeJong[0],
				g[1] + currentSolutionDeJong[1],
				g[2] + currentSolutionDeJong[2],
				g[3] + currentSolutionDeJong[3]
		});

		if (g[0] >= max_sol2.GetValues()[0]
			&& g[1] >= max_sol2.GetValues()[1]
			&& g[2] >= max_sol2.GetValues()[2]
			&& g[3] >= max_sol2.GetValues()[3])
		{
			max_sol2 = Punct(vector<double> {g[0], g[1], g[2], g[3]});
		}

		if (g[0] <= min_sol2.GetValues()[0]
			&& g[1] <= min_sol2.GetValues()[1]
			&& g[2] <= min_sol2.GetValues()[2]
			&& g[3] <= min_sol2.GetValues()[3])
		{
			min_sol2 = Punct(vector<double> {g[0], g[1], g[2], g[3]});
		}
	}

	cout << "Printing datas for De Jong with n = 4" << endl;
	cout << "The average solution is: "
		<< (average_solDeJong.GetValues()[0] / 30) << " "
		<< (average_solDeJong.GetValues()[1] / 30) << " "
		<< (average_solDeJong.GetValues()[2] / 30) << " "
		<< (average_solDeJong.GetValues()[3] / 30) << " "
		<< endl;

	cout << "The minimum sollution found is "
		<< (min_sol2.GetValues()[0]) << " "
		<< (min_sol2.GetValues()[1]) << " "
		<< (min_sol2.GetValues()[2]) << " "
		<< (min_sol2.GetValues()[3]) << " "
		<< endl;

	cout << "The maximum solution found so far is "
		<< (max_sol2.GetValues()[0]) << " "
		<< (max_sol2.GetValues()[1]) << " "
		<< (max_sol2.GetValues()[2]) << " "
		<< (max_sol2.GetValues()[3]) << " "
		<< endl;

	cout << endl;

	// Computing values for ackley

	MathematicalFunction ackley;

	ackley.setFunction(ackkeyPathFunction<3>);
	vector<FunctionDomains> ackleyDomain;

	ackleyDomain.push_back(FunctionDomains(-32, 32));
	ackleyDomain.push_back(FunctionDomains(-32, 32));
	ackleyDomain.push_back(FunctionDomains(-32, 32));

	ackley.setDomains(ackleyDomain);
	ackley.setVariables(3);

	Punct average_solAckley(vector<double> { 0.0, 0.0, 0.0, 0.0});
	Punct max_sol3(vector<double> {-DBL_MAX, -DBL_MAX, -DBL_MAX, -DBL_MAX});
	Punct min_sol3(vector<double> {DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX});

	for (int i = 0; i < 30; i++)
	{
		Punct &ackleyPoint = simulated_annealing(de_jong);

		vector<double> g = ackleyPoint.GetValues();

		vector<double> currentSolutionAckley = average_solAckley.GetValues();

		average_solDeJong = Punct(vector<double> {
			g[0] + currentSolutionAckley[0],
				g[1] + currentSolutionAckley[1],
				g[2] + currentSolutionAckley[2],
				g[3] + currentSolutionAckley[3]
		});

		if (g[0] >= max_sol3.GetValues()[0]
			&& g[1] >= max_sol3.GetValues()[1]
			&& g[2] >= max_sol3.GetValues()[2]
			&& g[3] >= max_sol3.GetValues()[3])
		{
			max_sol3 = Punct(vector<double> {g[0], g[1], g[2], g[3]});
		}

		if (g[0] <= min_sol3.GetValues()[0]
			&& g[1] <= min_sol3.GetValues()[1]
			&& g[2] <= min_sol3.GetValues()[2]
			&& g[3] <= min_sol3.GetValues()[3])
		{
			min_sol3 = Punct(vector<double> {g[0], g[1], g[2], g[3]});
		}
	}

	cout << "Printing datas for Ackley function" << endl;
	cout << "The average solution is: "
		<< (average_solAckley.GetValues()[0] / 30) << " "
		<< (average_solAckley.GetValues()[1] / 30) << " "
		<< (average_solAckley.GetValues()[2] / 30) << " "
		<< (average_solAckley.GetValues()[3] / 30) << " "
		<< endl;

	cout << "The minimum sollution found is "
		<< (min_sol3.GetValues()[0]) << " "
		<< (min_sol3.GetValues()[1]) << " "
		<< (min_sol3.GetValues()[2]) << " "
		<< (min_sol3.GetValues()[3]) << " "
		<< endl;

	cout << "The maximum solution found so far is "
		<< (max_sol3.GetValues()[0]) << " "
		<< (max_sol3.GetValues()[1]) << " "
		<< (max_sol3.GetValues()[2]) << " "
		<< (max_sol3.GetValues()[3]) << " "
		<< endl;

	cout << endl;



	// Computing values for Scwefel

	MathematicalFunction schwefel;
	schwefel.setFunction(scwefel7Function<4>);
	vector<FunctionDomains> scwefelDomain;

	scwefelDomain.push_back(FunctionDomains(-500, 500));
	scwefelDomain.push_back(FunctionDomains(-500, 500));
	scwefelDomain.push_back(FunctionDomains(-500, 500));
	scwefelDomain.push_back(FunctionDomains(-500, 500));

	schwefel.setVariables(4);
	schwefel.setDomains(scwefelDomain);

	Punct averageSolutionScwefel(vector<double>{0.0, 0.0, 0.0, 0.0});
	Punct maximumSolutionScwefel(vector<double> {-DBL_MAX, -DBL_MAX, -DBL_MAX, -DBL_MAX});
	Punct minimumSolutionScwefel(vector<double> {DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX});

	for (int i = 0; i < 30; i++)
	{
		Punct &scwefelPoint = simulated_annealing(schwefel);
		vector<double> g = scwefelPoint.GetValues();
		vector<double> currentSolutionScwefel = averageSolutionScwefel.GetValues();

		averageSolutionScwefel = Punct(vector<double>
		{
			g[0] + currentSolutionScwefel[0],
            g[1] + currentSolutionScwefel[1],
			g[2] + currentSolutionScwefel[2],
			g[3] + currentSolutionScwefel[3]
		});

		if (g[0] >= maximumSolutionScwefel.GetValues()[0] && g[1] >= maximumSolutionScwefel.GetValues()[1] && g[2] >= maximumSolutionScwefel.GetValues()[2] && g[3] >= maximumSolutionScwefel.GetValues()[3])
		{
			maximumSolutionScwefel = Punct(vector<double> {g[0], g[1], g[2], g[3]});
		}

		if (g[0] <= minimumSolutionScwefel.GetValues()[0] && g[1] <= minimumSolutionScwefel.GetValues()[1] && g[2] <= minimumSolutionScwefel.GetValues()[2] && g[3] <= minimumSolutionScwefel.GetValues()[3])
		{
			minimumSolutionScwefel = Punct(vector<double>{g[0], g[1], g[2], g[3]});
		}
	}

	cout << "Printing values for the Scwefel function : " << endl;

	cout << "The average solution found is : " << (averageSolutionScwefel.GetValues()[0] / 30) << (averageSolutionScwefel.GetValues()[1] / 30) << (averageSolutionScwefel.GetValues()[2] / 30) << (averageSolutionScwefel.GetValues()[3] / 30) << endl;;

	cout << "The minimum solution found is: " << (minimumSolutionScwefel.GetValues()[0]) << (minimumSolutionScwefel.GetValues()[1]) << (minimumSolutionScwefel.GetValues()[2]) << (minimumSolutionScwefel.GetValues()[3]) << endl;;

	cout << "The maximum solution found is: " << (maximumSolutionScwefel.GetValues()[0]) << (maximumSolutionScwefel.GetValues()[1]) << (maximumSolutionScwefel.GetValues()[2]) << (maximumSolutionScwefel.GetValues()[3]) << endl;

	return 0;

	}


