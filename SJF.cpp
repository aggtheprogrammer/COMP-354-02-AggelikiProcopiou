#include "Scheduler.h"
#include<iostream>

using namespace std;

class SFJ: public Scheduler{
    public:
    void schedule(Task* tasks[], int taskCount) override {
        for(int i=0;i<taskCount;i++){ // Sort tasks based on CPU burst time
            int minIdx = i;
            for (int j = i + 1; j < taskCount; ++j) {
                if (tasks[j]->getCpuBurst() < tasks[minIdx]->getCpuBurst()) // find the task with the minimum CPU burst time
                    minIdx = j;
        }
    }
}
};
