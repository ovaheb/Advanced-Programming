#ifndef __USER_H__
#define __USER_H__

#include "libraries.hpp"
#include "task.hpp"

using namespace std;

class User
{
public:
    User(string userName);
    string getName();
    vector<Task*> getAssignedTasks();
    void assignTask(Task* newTask);
    void deleteTask(string taskName);
private:
    string name;
    vector<Task*> assignedTasks;
    int searchTask(string taskName);
};

#endif