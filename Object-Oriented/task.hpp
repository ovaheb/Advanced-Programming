#ifndef __TASK_H__
#define __TASK_H__

#include "libraries.hpp"

class Task
{
public:
    Task(string listName, string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription);
    string getListName();
    string getTaskName() { return name; }
    unsigned int getEstimatedTime() { return time; }
    unsigned int getPriority() { return priority; }
    string getDescription() { return description; }
    string getUserAssignedTo() { return assignedTo; }
    bool isFinished() { return finished; }
    void editTaskDetails(unsigned int estimatedTime, unsigned int taskPriority, string taskDescription);
    void assignTask(string userName);
    void finishTask();
    void moveTask(string listName);
private:
    string list;
    string name;
    unsigned int time;
    unsigned int priority; 
    string description;
    string assignedTo;
    bool finished;
};

#endif