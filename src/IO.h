#ifndef	IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Process.h"
#include "GenerationParams.h"
#include "ScheduledTask.h"

using namespace std;

class IO
{
public:
	IO();

	GenerationParams readParamsFile(string inputFile);

	vector<ScheduledTask> readScheduledTasks(string inputFile);

	void writeGeneratedFile(string outputFile, vector<Process> processes);

	void writeScheduledTasks(string outputFile, vector<ScheduledTask> tasks);
};

#endif
