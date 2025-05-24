/**
 * @file    FCFS.cpp
 * @brief   First-Come-First-Served scheduler implementation.
 *
 * Non-pre-emptive: tasks run strictly in arrival order.
 */

#include "Scheduler.h"
#include<iostream>
#include<cassert>

using namespace std;

/** @class FCFS
 *  @brief First-Come First-Served scheduler (non-pre-emptive).
 */
class FCFS : public Scheduler {
    public:
    /** @brief Execute FCFS on the provided task array and print stats.
     *  @param tasks      Array of Task pointers (arrival time assumed 0).
     *  @param taskCount  Number of tasks in the array.
     */
    void schedule(Task* tasks[], int taskCount) override {
        assert(tasks != nullptr && "Task array must not be null");
        assert(taskCount > 0 && "Task count must be greater than zero");

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