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

	vector<Process>processes;
	string inputFile, outputFile;

public:
	ProcessGenerator(string _inputFile, string _outputFile);

	vector<double>getNormalDistribution(double mu, double sigma);

	vector<double>getPossionDistribution(double lambda);

	void generateProcesses();

	void readInputFile();

	void printProcessesToFile();

	void run();
};