#include "Scheduler.h"
#include<iostream>

using namespace std;

class PriorityRR : public Scheduler {
    public:
    void schedule(Task* tasks[], int taskCount) override {
        const int QUANTUM = 10;
        int currentTime = 0;
        int finished = 0;
        int* completion = new int[taskCount];
        for (int i = 0; i < taskCount; ++i)
            completion[i] = -1;

            for (int i = 0; i < taskCount - 1; ++i) {
            int maxIdx = i;
            for (int j = i + 1; j < taskCount; ++j) {
                if (tasks[j]->getPriority() > tasks[maxIdx]->getPriority())
                    maxIdx = j;
        }
            if (maxIdx != i) {
                Task* temp = tasks[i];
                tasks[i] = tasks[maxIdx];
                tasks[maxIdx] = temp;
            }
        }
        
    }
};