#include "Scheduler.h"
#include<iostream>

using namespace std;

class SFJ: public Scheduler{
    public:
    void schedule(Task* tasks[], int taskCount) override {
        for(int i=0;i<taskCount;i++){ // sort tasks based on CPU burst time
            int minIdx = i;
            for (int j = i + 1; j < taskCount-1; ++j) {
                if (tasks[j]->getCpuBurst() < tasks[minIdx]->getCpuBurst()) // find the task with the minimum CPU burst time
                    minIdx = j;
         }
            if (minIdx != i) { // swaps the tasks
                Task* temp = tasks[i];
                tasks[i]= tasks[minIdx]; 
                tasks[minIdx] = temp;
            }
    }
    /*after sorting, we can calculate waiting time and turnaround time*/ 
    int currentTime= 0;
    long long totalWait= 0;
    long long totalTurnaround= 0;

    cout << "SJF Scheduling Order:\n";

    for (int i = 0; i < taskCount; i++) { // iterate through the sorted tasks
            Task* t = tasks[i];
            int waitTime= currentTime;
            int turnTime= waitTime + t->getCpuBurst();

            cout << "Running Task: "<< t->getName()
            << "  Burst: "<< t->getCpuBurst()<< " ms"
            << "  Waiting: "<< waitTime<< " ms"
            << "  Turnaround: "<< turnTime<< " ms"<<endl;

            currentTime+= t->getCpuBurst(); // updates current time
            totalWait+= waitTime;
            totalTurnaround+= turnTime;
    }
    /*finds the avgs*/
    double avgWait = double(totalWait) / taskCount;
    double avgTurn = double(totalTurnaround) / taskCount;

    cout << "\nAverage Waiting Time   : " << avgWait << " ms"<<endl;
    cout << "Average Turnaround Time : " << avgTurn << " ms"<<endl;
}
};
