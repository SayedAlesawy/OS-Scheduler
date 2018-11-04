#include "ProcessGenerator.h"
#include<random>

ProcessGenerator::ProcessGenerator(int _processesCount, double _arrivalTimeMu, double _arrivalTimeSigma, double _burstTimeMu,
	double _burstTimeSigma, double _priorityLambda)
{
	processesCount = _processesCount;
	arrivalTimeMu = _arrivalTimeMu;
	arrivalTimeSigma = _arrivalTimeSigma;
	burstTimeMu = _burstTimeMu;
	burstTimeSigma = _burstTimeSigma;
	priorityLambda = _priorityLambda;
}

vector<double>ProcessGenerator::getNormalDistribution(double mu, double sigma)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(mu, sigma);

	vector<double>ret(processesCount);

	for (int i = 0; i < processesCount; i++) {
		double number = distribution(generator);

		ret[i] = fabs(number);
	}

	return ret;
}

vector<double>ProcessGenerator::getPossionDistribution(double lambda)
{
	std::default_random_engine generator;
	std::poisson_distribution<int> distribution(lambda);

	vector<double>ret(processesCount);

	for (int i = 0; i < processesCount; i++) {
		double number = distribution(generator);

		ret[i] = fabs(number);
	}

	return ret;
}

vector<Process> ProcessGenerator::generateProcesses()
{
	vector<Process>processes(processesCount);

	vector<double> arrivalTime = getNormalDistribution(arrivalTimeMu, arrivalTimeSigma);
	vector<double> busrtTime = getNormalDistribution(burstTimeMu, burstTimeSigma);
	vector<double> priority = getPossionDistribution(priorityLambda);

	for (int i = 1; i <= processesCount; i++) {
		Process newProcess(i, arrivalTime[i-1], busrtTime[i-1], priority[i-1]);

		processes[i-1] = newProcess;
	}

	return processes;
}

vector<Process> ProcessGenerator::run()
{
	return generateProcesses();
}