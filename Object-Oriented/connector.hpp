#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "libraries.hpp"
#include "user.hpp"
#include "task.hpp"
#include "list.hpp"
class Connector
{
public:
    Connector();
    string addUser(string userName);
    string addTask(string listName, string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription);
    string addList(string listName);
    string editTask(string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription);
    string assignTask(string taskName, string userName);
    string completeTask(string taskName);
    string moveTask(string taskName, string listName);
    string deleteTask(string taskName);
    string deleteList(string listName);
    int printTotalEstimatedTime();
    int printTotalRemainingTime();
    int printUserWorkLoad(string userName);
    string printTask(string taskName);
    string printList(string listName);
    string printUserTasks(string userName);
    string printAllLists();
    string printUnassignedTasksByPriority();
    string printAllUnfinishedTasksByPriority();
    string printUserUnfinishedTasks(string userName);
    string printUsersByWorkload();
    string printUsersByPerformance();
private:
    vector<User> users;
    vector<List> lists;
    vector<Task*> tasks;
    int searchUser(string userName);
    int searchList(string listName);
    int searchTask(string taskName);
    
};


#endif