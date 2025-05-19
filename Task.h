#ifndef TASK_H
#define TASK_H
#include<iostream>

using namespace std;

class Task {
    private:
    string name;
    int priority,cpuBurst,remainingTime;
public:
    Task(string name, int priority, int cpuBurst) {
        this->name = name;
        this->priority = priority;
        this->cpuBurst = cpuBurst;
        this->remainingTime = cpuBurst;
    }

    string getName() {
        return name;
    }

    int getPriority() {
        return priority;
    }

    int getCpuBurst() {
        return cpuBurst;
    }

    int getRemainingTime() {
        return remainingTime;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setPriority(int priority) {
        this->priority = priority;
    }

    void setCpuBurst(int cpuBurst) {
        this->cpuBurst = cpuBurst;
    }
    void setRemainingTime(int remainingTime) {
        this->remainingTime = remainingTime;
    }
   
};

 #endif