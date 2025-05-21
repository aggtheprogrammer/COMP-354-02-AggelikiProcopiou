/**
 * @file   main.cpp
 * @author Aggeliki Procopiou
 * @date   2025-05-21
 * @brief  Demonstrates five CPU-scheduling algorithms.
 *
 * The driver:
 * 1. Prompts the user to choose an algorithm,
 * 2. Loads task definitions from schedule.txt, and
 * 3. Invokes the matching Scheduler subclass
 *    (FCFS, SJF, Priority, RoundRobin, or PriorityRR).
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "Task.h"
#include "Scheduler.h"
#include "FCFS.cpp"
#include "SJF.cpp"
#include "Priority.cpp"
#include "RoundRobin.cpp"
#include "PriorityRR.cpp"

using namespace std;

/**
 * @brief launches the scheduler, selects algorithm, loads tasks, and executes the schedule.
 *
 * Prompts the user to select a scheduling algorithm, reads task definitions
 * from "schedule.txt", and invokes the chosen scheduler implementation.
 *
 * @return zero on success; non-zero on error.
 */
int main(){

    string algName;
    string fileName;

    cout << "Algorithm (fcfs | sjf | priority | rr | priority_rr): ";
    cin  >> algName;
    

    Scheduler* scheduler = nullptr;

    if (algName == "fcfs" || algName == "FCFS")        
        scheduler = new FCFS();

    else if (algName == "sjf" || algName == "SJF")
         scheduler = new SJF();

    else if (algName == "priority" || algName == "Priority")
        scheduler = new Priority();

    else if (algName == "rr" || algName == "RR" || algName == "Round Robin") 
         scheduler = new RoundRobin();

    else if (algName == "Priority RR" || algName == "priority rr" || algName == "Priority Round Robin")
         scheduler = new PriorityRR();

    else {
        cerr << "Unknown algorithm: " << algName << '\n';
        return 1;
    }

    ifstream fin("schedule.txt");
    if (!fin) {
        cerr << "Cannot open schedule.txt"<< endl;
        delete scheduler;
        return 1;
    }

    const int MAX_TASKS = 1024;
    Task* tasks[MAX_TASKS];
    int   taskCount = 0;
    string line;

    while (getline(fin, line) && taskCount < MAX_TASKS) {
        string name;
        int prio, burst;

       size_t c1 = line.find(',');           // first comma
       size_t c2 = line.find(',', c1 + 1);   // second comma

       /*extracts the commas*/
       name  = line.substr(0, c1);
       prio  = stoi(line.substr(c1 + 1, c2 - c1 - 1));    
       burst = stoi(line.substr(c2 + 1));

        while (!name.empty() && (name.front() == ' ' || name.front() == '\t' || name.front() == '\r' || name.front() == '\n')){
                name.erase(name.begin()); 
            }

         while (!name.empty() && (name.back() == ' ' || name.back() == '\t' || name.back() == '\r' || name.back() == '\n')){
                name.pop_back(); 
            }

        tasks[taskCount++] = new Task(name, prio, burst);

    }
    assert(taskCount > 0 && "No valid tasks loaded"); // ensure at least one task is loaded

    scheduler->schedule(tasks, taskCount); // schedule the tasks

    for (int i = 0; i < taskCount; i++) 
        delete tasks[i];

    fin.close();
    delete scheduler;

    return 0;
}