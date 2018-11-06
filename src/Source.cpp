#include <iostream>
#include <queue>

#include "ProcessGenerator.h"
#include "GenerationParams.h"
#include "Process.h"
#include "IO.h"
#include "SchedulerFCFS.h"
#include "TaskManager.h"

using namespace std;

int main()
{
	//testing code
	IO inputReader;
	GenerationParams params = inputReader.readParamsFile("../Input/input");

	ProcessGenerator gen(params.processesCount, params.arrivalTimeMu, params.arrivalTimeSigma, params.burstTimeMu, params.burstTimeSigma, params.priorityLambda);

	vector<Process> processes = gen.run();

    SchedulerFCFS fcfs;
    TaskManager manager(&fcfs);

    manager.submitProcesses(processes);
    fcfs.simulate();

    // IO outputWriter;
    // outputWriter.writeGeneratedFile("../Output/output", processes);
	
	cout << "done";

	int wait; cin >> wait;
}
