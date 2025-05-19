#include "Schedule.h"
#include<iostream>

using namespace std;

class FCFS : public Scheduler {
    public:
    void schedule(Task* tasks[], int taskCount) override {
        int currentTime=0;
        int totalWaitingTime=0;
        int totalTurnaroundTime=0;
        cout << "FCFS Scheduling:" << endl;

        for(int i=0;i<taskCount;i++) {
            Task* task= tasks[i];

             int waitingTime = currentTime; 
            int turnaroundTime = waitingTime + task->getCpuBurst();

            cout << "Running Task: " << task->getName() 
                 << " | Burst Time: " << task->getCpuBurst() 
                 << "ms | Waiting Time: " << waitingTime 
                 << "ms | Turnaround Time: " << turnaroundTime 
                 << "ms"<<endl;
        }
    }
}