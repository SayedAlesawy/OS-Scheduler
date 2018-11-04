#ifndef	GENERATIONPARAMS_H
#define GENERATIONPARAMS_H

struct GenerationParams
{
	int processesCount;
	double arrivalTimeMu;
	double arrivalTimeSigma;
	double burstTimeMu;
	double burstTimeSigma;
	double priorityLambda;

	GenerationParams(int _processesCount, double _arrivalTimeMu, double _arrivalTimeSigma, double _burstTimeMu,
		double _burstTimeSigma, double _priorityLambda)
	{
		processesCount = _processesCount;
		arrivalTimeMu = _arrivalTimeMu;
		arrivalTimeSigma = _arrivalTimeSigma;
		burstTimeMu = _burstTimeMu;
		burstTimeSigma = _burstTimeSigma;
		priorityLambda = _priorityLambda;
	}
};

#endif
