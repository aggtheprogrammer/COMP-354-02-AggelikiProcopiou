/**
 * @file    Priority.cpp
 * @brief   Static-priority scheduler (larger number -> higher priority).
 */

#include "Scheduler.h" 
#include<iostream>
#include<cassert>

using namespace std;

/** @class Priority
 *  @brief priority-based CPU scheduler (non-pre-emptive).
 *
 *  tasks are sorted in descending order of numeric priority (higher value = higher priority).
 *  ties are resolved by original order (stable selection sort).
 */
class Priority : public Scheduler {
    public:
    /** @brief Runs Priority scheduling on the task list and prints results.
     *  @param tasks      Array of Task pointers (not null).
     *  @param taskCount  Number of tasks in the array.
     */
    void schedule(Task* tasks[], int taskCount) override {
        assert(tasks != nullptr && "Task array must not be null");
        assert(taskCount > 0 && "Task count must be greater than zero");

       for(int i =0;i<taskCount-1;i++){
            int maxIdx = i; //index of highest-priority task seen so far
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
                 << "  Priority: "<< t->getPriority()
                 << "  Burst: "<< t->getCpuBurst()<< " ms"
                 << "  Waiting: "<< waitTime<< " ms"
                 << "  Turnaround: "<< turnTime<< " ms"<<endl;

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