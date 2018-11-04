#ifndef	PROCESS_H
#define PROCESS_H

struct Process
{
	int id;
	double arrivalTime;
	double burstTime;
	double priority;
	double remainingTime;

	Process() {
		//Empty
	}

	Process(int _id, double _arrival, double _burst, double _prioirty)
	{
		id = _id;
		arrivalTime = _arrival;
		burstTime = _burst;
		priority = _prioirty;
		remainingTime = burstTime;
	}
};

#endif PROCESS_H;