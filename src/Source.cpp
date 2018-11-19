#include <iostream>
#include <queue>

#include "ProcessGenerator.h"
#include "GenerationParams.h"
#include "Process.h"
#include "IO.h"
#include "SchedulerFCFS.h"
#include "SchedulerHPF.h"
#include "SchedulerRR.h"
#include "TaskManager.h"


using namespace std;

int maina()
{
	//testing code
	IO inputReader;
	GenerationParams params = inputReader.readParamsFile("../Input/input");

	ProcessGenerator gen(params.processesCount, params.arrivalTimeMu, params.arrivalTimeSigma, params.burstTimeMu, params.burstTimeSigma, params.priorityLambda);

	vector<Process> processes = gen.run();

    //SchedulerFCFS fcfs;
    //TaskManager manager(&fcfs);
    //manager.submitProcesses(processes);
    //fcfs.simulate();

	//SchedulerHPF hpf;
	//TaskManager manager(&hpf);
	//manager.submitProcesses(processes);
	//hpf.simulate();

	//SchedulerRR RR;
	//TaskManager manager(&RR);
	//manager.submitProcesses(processes);
	//RR.simulate();

    // IO outputWriter;
    // outputWriter.writeGeneratedFile("../Output/output", processes);
	
	cout << "done";

	int wait; cin >> wait;
}
