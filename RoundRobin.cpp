#include "Scheduler.h"
#include<iostream>

using namespace std;

class RoundRobin : public Scheduler {
    public:
    void schedule(Task* tasks[], int taskCount) override {
        const int QUANTUM = 10;
        int currentTime = 0;
        int finished = 0;
        int* completion = new int[taskCount];

        for (int i = 0; i < taskCount; ++i)
            completion[i] = -1;

    }
};