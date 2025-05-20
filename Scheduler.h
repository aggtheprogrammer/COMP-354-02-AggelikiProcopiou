#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Task.h"

using namespace std;

/** @class Scheduler
 *  @brief Abstract base class for all CPU scheduling algorithms.
 */
class Scheduler {
public:
/** @brief Schedules a list of tasks according to a specific algorithm.
     *  @param tasks      Array of Task pointers.
     *  @param taskCount  Number of tasks.
     */
    virtual void schedule(Task* tasks[], int taskCount) = 0; 

    /** @brief Virtual destructor for proper cleanup of derived classes. */
    virtual ~Scheduler() = default;
};

 #endif