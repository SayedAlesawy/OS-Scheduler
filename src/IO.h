#ifndef	IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "ProcessStat.h"
#include "Process.h"
#include "GenerationParams.h"

using namespace std;

class IO
{
public:
	IO();

	GenerationParams readParamsFile(string inputFile);

    // vector<ScheduledTask> readScheduledTasks(string inputFile);

    void writeGeneratedFile(string outputFile, vector<Process> processes);

    //vector<Process>readProcessesFile(string inputFile);

    // void writeScheduledTasks(string outputFile, vector<ScheduledTask> tasks);

    void saveFile(string outputFile, vector<ProcessStat> stats, double totalATAT, double totalAWTAT);

    bool error;
};

#endif
