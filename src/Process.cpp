#include "Process.h"

Process::Process()
{
	//default constructor
}

Process::Process(int _id, double _arrival, double _burst, double _priority)
{
	id = _id;
	arrivalTime = _arrival;
	burstTime = remainingTime = _burst;
	priority = _priority;
}

ofstream& operator<<(ofstream &out, Process process)
{
	out << process.id << " " << process.arrivalTime << " " << process.burstTime << " " << process.priority << endl;

	return out;
}