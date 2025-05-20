#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Task.h"
#include<iostream>

using namespace std;

class Scheduler {
public:
    virtual void schedule(Task* tasks[], int taskCount) = 0; 
    virtual ~Scheduler() = default;
};

 #endif