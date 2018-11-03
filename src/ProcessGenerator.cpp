#include "ProcessGenerator.h"
#include<random>

ProcessGenerator::ProcessGenerator(string _inputFile, string _outputFile)
{
	inputFile = _inputFile + ".txt";
	outputFile = _outputFile + ".txt";
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

void ProcessGenerator::generateProcesses()
{
	processes.resize(processesCount);

	vector<double> arrivalTime = getNormalDistribution(arrivalTimeMu, arrivalTimeSigma);
	vector<double> busrtTime = getNormalDistribution(burstTimeMu, burstTimeSigma);
	vector<double> priority = getPossionDistribution(priorityLambda);

	for (int i = 1; i <= processesCount; i++) {
		Process newProcess(i, arrivalTime[i-1], busrtTime[i-1], priority[i-1]);

		processes[i-1] = newProcess;
	}
}

void ProcessGenerator::readInputFile()
{
	ifstream in;
	in.open(inputFile);

	in >> processesCount;
	in >> arrivalTimeMu >> arrivalTimeSigma;
	in >> burstTimeMu >> burstTimeSigma;
	in >> priorityLambda;

	in.close();
}

void ProcessGenerator::printProcessesToFile()
{
	ofstream out;
	out.open(outputFile);

	out << processesCount << endl;

	for (int i = 0; i < processesCount; i++) {
		out << processes[i];
	}

	out.close();
}

void ProcessGenerator::run()
{
	readInputFile();

	generateProcesses();

	printProcessesToFile();
}