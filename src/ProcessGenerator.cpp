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

vector<int>ProcessGenerator::getNormalDistribution(double mu, double sigma)
{
	std::default_random_engine generator;
    std::normal_distribution<double> distribution(mu, sigma);

    vector<int>ret(processesCount);

	for (int i = 0; i < processesCount; i++) {
        int number = (int)distribution(generator);

        ret[i] = abs(number);

		if (ret[i] == 0) ret[i] = 1;
	}

	return ret;
}

vector<int>ProcessGenerator::getPossionDistribution(double lambda)
{
	std::default_random_engine generator;
    std::poisson_distribution<int> distribution(lambda);

    vector<int>ret(processesCount);

	for (int i = 0; i < processesCount; i++) {
        int number = distribution(generator);

        ret[i] = abs(number);

		if (ret[i] == 0) ret[i] = 1;
	}

	return ret;
}

vector<Process> ProcessGenerator::generateProcesses()
{
	vector<Process>processes(processesCount);

    vector<int> arrivalTime = getNormalDistribution(arrivalTimeMu, arrivalTimeSigma);
    vector<int> busrtTime = getNormalDistribution(burstTimeMu, burstTimeSigma);
    vector<int> priority = getPossionDistribution(priorityLambda);

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
