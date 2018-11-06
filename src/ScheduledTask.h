#ifndef	SCHEDULEDTASK_H
#define SCHEDULEDTASK_H

struct ScheduledTask
{
	int id;
    int begin;
    int end;

	ScheduledTask()
	{
		//Empty
	}

    ScheduledTask(int _id, int _begin, int _end)
	{
		id = _id;
		begin = _begin;
		end = _end;
	}
};

#endif
