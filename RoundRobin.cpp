#include "Scheduler.h"
#include<iostream>

using namespace std;

class RoundRobin : public Scheduler {
    public:
    void schedule(Task* tasks[], int taskCount) override {
        const int QUANTUM = 10;
        int currentTime = 0;
        int finished = 0;
        int* completion = new int[taskCount];

        for (int i = 0; i < taskCount; ++i)
            completion[i] = -1;


        cout << "Round-Robin Scheduling (Time Quantum = 10 ms):"<<endl;

        while (finished < taskCount) {
            for (int i = 0; i < taskCount; ++i) {
                int remaining = tasks[i]->getRemainingTime();

                if (remaining == 0) 
                    continue;

                int slice = min(QUANTUM, remaining);

                cout << "Running Task: " << tasks[i]->getName()
                     << "  Time Slice: " << slice << " ms"
                     << "  Remaining: " << remaining - slice << " ms" << endl;

            tasks[i]->setRemainingTime(remaining - slice);
            currentTime += slice;

            if (tasks[i]->getRemainingTime() == 0) {
                completion[i] = currentTime;
                finished++;

            }
            }
        }

        long long totalWait = 0;
        long long totalTurn = 0;

        cout << "\nPer-task Summary:"<<endl;
        for (int i = 0; i < taskCount; i++) {
            int burst = tasks[i]->getCpuBurst();
            int turn = completion[i];
            int wait = turn - burst;

             cout << tasks[i]->getName()
                  << "  Burst: " << burst << " ms"<<endl
                  << "  Waiting: " << wait << " ms"<<endl
                  << "  Turnaround: " << turn << " ms" << endl;

            totalWait += wait;
            totalTurn += turn;
        }
        double avgWait = double(totalWait) / taskCount;
        double avgTurn = double(totalTurn) / taskCount;

        cout << "\nAverage Waiting Time   : " << avgWait << " ms" << endl;
        cout << "Average Turnaround Time: " << avgTurn << " ms" << endl;

        delete[] completion;

    }
};