#ifndef	PROCESSGENERATOR_H
#define PROCESSGENERATOR_H

#include<vector>
#include"Process.h"

using namespace std;

class ProcessGenerator
{
private:
	int processesCount;
	double arrivalTimeMu;
	double arrivalTimeSigma;
	double burstTimeMu;
	double burstTimeSigma;
	double priorityLambda;

	vector<double>getNormalDistribution(double mu, double sigma);

	vector<double>getPossionDistribution(double lambda);

	vector<Process> generateProcesses();

public:
	ProcessGenerator(int _processesCount, double _arrivalTimeMu, double _arrivalTimeSigma, double _burstTimeMu, 
		double _burstTimeSigma, double _priorityLambda);

	vector<Process> run();
};

#endif PROCESSGENERATOR_H;