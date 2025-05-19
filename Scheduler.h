#ifndef SCHEDULER_H
#define SCHEDULER_H
#include<iostream>

using namespace std;

class Scheduler {
public:
    virtual void schedule(Scheduler* tasks[], int taskCount) = 0;
    virtual ~Scheduler() = default;
};

 #endif