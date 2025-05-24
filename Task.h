/**
 * @file    Task.h
 * @brief   Data model for a schedulable task.
 */

#ifndef TASK_H
#define TASK_H

using namespace std;

/** @class Task
 *  @brief Represents a CPU task with a name, priority, burst time, and remaining time.
 */
class Task { 
    private:
    string name;
    int priority,cpuBurst,remainingTime;
public:
/** @brief Constructs a Task with the given name, priority, and CPU burst time.
     *  @param name       Name of the task.
     *  @param priority   Priority level (higher number = higher priority).
     *  @param cpuBurst   CPU burst time in milliseconds.
     */
    Task(const string& name, int priority, int cpuBurst) {
        this->name = name;
        this->priority = priority;
        this->cpuBurst = cpuBurst;
        this->remainingTime = cpuBurst;
    }

      /** @brief Gets the task's name. */
    string getName() const {
        return name;
    }

     /** @brief Gets the task's priority. */
    int getPriority() const{
        return priority;
    }

    /** @brief Gets the task's CPU burst time. */
    int getCpuBurst() const {
        return cpuBurst;
    }

    /** @brief Gets the task's remaining execution time. */
    int getRemainingTime() const {
        return remainingTime;
    }

    /** @brief Sets the task's name. */
    void setName(const string& name){
        this->name = name;
    }

    /** @brief Sets the task's priority. */
    void setPriority(int priority) {
        this->priority = priority;
    }

    /** @brief Sets the task's CPU burst time. */
    void setCpuBurst(int cpuBurst) {
        this->cpuBurst = cpuBurst;
    }

    /** @brief Sets the task's remaining execution time. */
    void setRemainingTime(int remainingTime) {
        this->remainingTime = remainingTime;
    }
   
};
 #endif