#include "Scheduler.h"
#include<iostream>

using namespace std;

class Priority : public Scheduler {
    public:
    void schedule(Task* tasks[], int taskCount) override {
       for(int i =0;i<taskCount-1;i++){
            int maxIdx = i;
           for(int j=i+1;j<taskCount;j++){
               if(tasks[j]->getPriority() > tasks[maxIdx]->getPriority()) // find the task with the maximum priority
                   maxIdx = j;
           }
           if(maxIdx != i){ // swaps the tasks
               Task* temp   = tasks[i];
               tasks[i]    = tasks[maxIdx]; 
               tasks[maxIdx] = temp;
           }
       }
    }
};