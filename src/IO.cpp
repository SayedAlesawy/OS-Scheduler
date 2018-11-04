#include "IO.h"

IO::IO()
{
	//Empty constructor
}

GenerationParams IO::readParamsFile(string inputFile)
{
	ifstream in;
	in.open(inputFile + ".txt");

	int processesCount;
	double arrivalTimeMu, arrivalTimeSigma, burstTimeMu, burstTimeSigma, priorityLambda;

	in >> processesCount;
	in >> arrivalTimeMu >> arrivalTimeSigma;
	in >> burstTimeMu >> burstTimeSigma;
	in >> priorityLambda;

	GenerationParams params(processesCount, arrivalTimeMu, arrivalTimeSigma, burstTimeMu, burstTimeSigma, priorityLambda);

	in.close();

	return params;
}

vector<ScheduledTask> IO::readScheduledTasks(string inputFile)
{
	ifstream in;
	in.open(inputFile + ".txt");

	int tasksCount, id;
	double begin, end;
	
	in >> tasksCount;
	vector<ScheduledTask> tasks(tasksCount);

	for (int i = 0; i < tasksCount; i++) {
		in >> id >> begin >> end;
		
		ScheduledTask task(id, begin, end);

		tasks[i] = task;
	}

	in.close();

	return tasks;
}

void IO::writeGeneratedFile(string outputFile, vector<Process> processes)
{
	ofstream out;
	out.open(outputFile + ".txt");

	out << processes.size() << endl;

	for (int i = 0; i < processes.size(); i++) {
		out << processes[i].id << " " << processes[i].arrivalTime << " " << processes[i].burstTime << " " << processes[i].priority << endl;
	}

	out.close();
}

void IO::writeScheduledTasks(string outputFile, vector<ScheduledTask> tasks)
{
	ofstream out;
	out.open(outputFile + ".txt");

	out << tasks.size() << endl;

	for (int i = 0; i < tasks.size(); i++) {
		out << tasks[i].id << " " << tasks[i].begin << " " << tasks[i].end << endl;
	}

	out.close();
}