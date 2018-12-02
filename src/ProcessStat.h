#ifndef PROCESSSTAT_H
#define PROCESSSTAT_H

struct ProcessStat
{
    int id;
    int waitingTime;
    int TAT;
    double weightedTAT;
};

#endif // PROCESSSTAT_H
