#ifndef	SCHEDULEDTASK_H
#define SCHEDULEDTASK_H

struct ScheduledTask
{
	int id;
	double begin;
	double end;

	ScheduledTask()
	{
		//Empty
	}

	ScheduledTask(int _id, double _begin, double _end)
	{
		id = _id;
		begin = _begin;
		end = _end;
	}
};

#endif
