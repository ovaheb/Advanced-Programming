#ifndef __LIST_H__
#define __LIST_H__

#include "libraries.hpp"
#include "task.hpp"

class List
{
public:
    List(string listName);
    string getName(){ return name; }
    void addTask(Task* newTask);
    vector<Task*> getTasksWithin();
    void deleteTask(string taskName);
private:
    string name;
    vector<Task*> tasksWithin;
    int searchTask(string taskName);
};


#endif