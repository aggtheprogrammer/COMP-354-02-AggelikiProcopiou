#include "Scheduler.h"
#include<iostream>

using namespace std;

/** @class PriorityRR
 *  @brief Implements Priority-based Round-Robin scheduling algorithm.
 *
 *  Tasks are sorted by descending priority, and within each priority group,
 *  executed using Round-Robin with a 10 ms time quantum. Assumes all tasks arrive at time 0.
 */
class PriorityRR : public Scheduler {
    public:
    /** @brief Executes Priority Round-Robin scheduling and prints statistics.
     *  @param tasks      Array of Task pointers.
     *  @param taskCount  Number of tasks in the array.
     */
    void schedule(Task* tasks[], int taskCount) override {
        const int QUANTUM = 10;
        int currentTime = 0;
        int finished = 0;
        int* completion = new int[taskCount];
        for (int i = 0; i < taskCount; ++i)
            completion[i] = -1;

            for (int i = 0; i < taskCount - 1; ++i) { // sort tasks by priority (higher value first)
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
        cout << "Priority Round-Robin Scheduling (Time Quantum = 10 ms):" << endl;

        while (finished < taskCount) {
            int currentPriority = -1;

            for (int i = 0; i < taskCount; ++i) {
                if (tasks[i]->getRemainingTime() == 0)  // skip completed tasks
                        continue;

                if (currentPriority == -1)
                    currentPriority = tasks[i]->getPriority();

                if (tasks[i]->getPriority() != currentPriority) // only serve tasks with current group priority
                    continue;

                int remaining = tasks[i]->getRemainingTime();
                int slice = min(QUANTUM, remaining);
                
                cout << "Running Task: " << tasks[i]->getName()
                     << "  Priority: " << tasks[i]->getPriority()
                     << "  Time Slice: " << slice << " ms"
                     << "  Remaining: " << remaining - slice << " ms" << endl;

                tasks[i]->setRemainingTime(remaining - slice);
                currentTime += slice;

                if (tasks[i]->getRemainingTime() == 0) {
                    completion[i] = currentTime; // record when task finishes
                    finished++;
                }
            }
        }

        long long totalWait = 0;
        long long totalTurn = 0;

        cout << "\nPer-task Summary:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            int burst = tasks[i]->getCpuBurst();
            int turn = completion[i];
            int wait = turn - burst;

            cout << tasks[i]->getName()
                 << "  Priority: " << tasks[i]->getPriority()
                 << "  Burst: " << burst << " ms" << endl
                 << "  Waiting: " << wait << " ms" << endl
                 << "  Turnaround: " << turn << " ms" << endl;

            totalWait += wait;
            totalTurn += turn;
        }

        double avgWait = double(totalWait) / taskCount;
        double avgTurn = double(totalTurn) / taskCount;

        cout << "\nAverage Waiting Time   : " << avgWait << " ms" << endl;
        cout << "Average Turnaround Time: " << avgTurn << " ms" << endl;

        delete[] completion; //clean up dynamically allocated memory
    }
};