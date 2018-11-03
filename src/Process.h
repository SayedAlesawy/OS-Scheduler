#include<fstream>

using namespace std;

class Process
{
public:
	int id;
	double arrivalTime;
	double burstTime;
	double priority;
	double remainingTime;

	Process();

	Process(int id, double arrival, double burst, double prioirty);

	friend ofstream& operator << (ofstream &out, const Process process);
};