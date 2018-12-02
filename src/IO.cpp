#include "IO.h"

IO::IO()
{
	//Empty constructor
}

GenerationParams IO::readParamsFile(string inputFile)
{
    error = false;
	ifstream in;
    in.open(inputFile);

    int processesCount = 0;
    double arrivalTimeMu = 0,
            arrivalTimeSigma = 0,
            burstTimeMu = 0,
            burstTimeSigma = 0,
            priorityLambda = 0;

    if(in.is_open())
    {
        in >> processesCount;
        in >> arrivalTimeMu >> arrivalTimeSigma;
        in >> burstTimeMu >> burstTimeSigma;
        in >> priorityLambda;
    }
    else
    {
        error = true;
    }

	GenerationParams params(processesCount, arrivalTimeMu, arrivalTimeSigma, burstTimeMu, burstTimeSigma, priorityLambda);

	in.close();

	return params;
}

/*
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
*/

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

/*
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
*/

void IO::saveFile(string outputFile, vector<ProcessStat> stats, double totalATAT, double totalAWTAT)
{
    ofstream out;
    out.open(outputFile);

    for(int i=0; i<stats.size(); i++){
        out << stats[i].id << '\t' << stats[i].waitingTime << '\t' <<
               stats[i].TAT << '\t' << stats[i].weightedTAT << endl;
    }

    out<<endl<<totalATAT<<'\t'<<totalAWTAT<<endl;
}

vector<Process> IO::readProcesses(string inputFile)
{
    ifstream in;
    in.open(inputFile);

    int processCount;
    in >>processCount;

    vector<Process> processes (processCount);

    for(int i=0;i<processCount;i++)
    {
        Process process;
        in >> process.id >> process.arrivalTime >> process.burstTime >> process.priority;
        process.remainingTime = process.burstTime;
        processes[i] = process;
    }

    return processes;
}


