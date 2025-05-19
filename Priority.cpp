#include "Scheduler.h"
#include<iostream>

using namespace std;

class Priority : public Scheduler {
    public:
    void schedule(Task* tasks[], int taskCount) override {
       for(int i =0;i<taskCount-1;i++){
            int maxIdx = i; //Index of highest-priority task seen so far
           for(int j=i+1;j<taskCount;j++){
               if(tasks[j]->getPriority() > tasks[maxIdx]->getPriority()) //if we find a task with a higher numeric priority → update maxIdx
                   maxIdx = j;
           }
           if(maxIdx != i){ // swaps the tasks
               Task* temp   = tasks[i];
               tasks[i]    = tasks[maxIdx]; 
               tasks[maxIdx] = temp;
           }
       }
       int currentTime= 0;
       long long totalWait= 0;
       long long totalTurnaround= 0;

       cout << "Priority Scheduling Order:"<<endl;

        for (int i = 0; i < taskCount; ++i) { 
            Task* t= tasks[i];
            int waitTime= currentTime;
            int turnTime= waitTime + t->getCpuBurst();
        
            cout << "Running Task: "<< t->getName()
                 << " | Priority: "<< t->getPriority()
                 << " | Burst: "<< t->getCpuBurst()<< " ms"
                 << " | Waiting: "<< waitTime<< " ms"
                 << " | Turnaround: "<< turnTime<< " ms"<<endl;

            currentTime+= t->getCpuBurst();
            totalWait+= waitTime;
            totalTurnaround+= turnTime;
        }

        double avgWait = double(totalWait) / taskCount;
        double avgTurn = double(totalTurnaround) / taskCount;

        cout << "\nAverage Waiting Time   : " << avgWait << " ms"<<endl;
        cout << "Average Turnaround Time : " << avgTurn << " ms"<<endl;
    }
};