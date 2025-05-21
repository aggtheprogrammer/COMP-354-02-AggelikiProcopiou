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

int main(){

    string algName;
    string fileName;

    cout << "Algorithm (fcfs | sjf | priority | rr | priority_rr): ";
    cin  >> algName;
    cout << "Task file: ";
    cin  >> fileName;

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
}