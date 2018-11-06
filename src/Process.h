#ifndef	PROCESS_H
#define PROCESS_H

struct Process
{
	int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;

	Process() {
		//Empty
	}

    Process(int _id, int _arrival, int _burst, int _prioirty)
	{
		id = _id;
		arrivalTime = _arrival;
		burstTime = _burst;
		priority = _prioirty;
		remainingTime = burstTime;
	}
};

#endif
