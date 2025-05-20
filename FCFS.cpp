#include "Scheduler.h"
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
            Task* task= tasks[i]; // Get the task

             int waitingTime = currentTime; 
            int turnaroundTime = waitingTime + task->getCpuBurst();

            cout << "Running Task: " << task->getName()
                 << "  Burst Time: " << task->getCpuBurst()<<" ms"
                 << "  Waiting Time: " << waitingTime <<" ms"
                 << "  Turnaround Time: " << turnaroundTime<<" ms"<<endl;

            currentTime += task->getCpuBurst(); // Update current time
            totalWaitingTime += waitingTime;
            totalTurnaroundTime += turnaroundTime;
        }

        double avgWaitingTime = double(totalWaitingTime) / taskCount;
        double avgTurnaroundTime = double(totalTurnaroundTime) / taskCount;

        cout << "\nAverage Waiting Time: " << avgWaitingTime << " ms\n"; // Calculate average waiting time
        cout << "Average Turnaround Time: " << avgTurnaroundTime << " ms\n"; // Calculate average turnaround time
    }
};