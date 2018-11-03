class Constants
{
public:
	//Any values for now
	static int quantumSize;
	static int contextSwitchingTime;
	static int SchedularTimeStep;
	static double maxArrivalTime;
	static double maxBurstTime;
	static double maxPriority;
	
	static void initializeConstants()
	{
		quantumSize = 5;
		contextSwitchingTime = 2;
		SchedularTimeStep = 1;
		maxArrivalTime = 1000.0;
		maxBurstTime = 300.0;
		maxPriority = 20.0;
	}
};