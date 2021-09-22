#include "utrello_interface.hpp"
#include "libraries.hpp"

UTrelloInterface::UTrelloInterface()
{
    Connector connector();
}
string UTrelloInterface::addUser(string userName)
{
    return connector.addUser(userName);
}
string UTrelloInterface::addList(string listName)
{
    return connector.addList(listName);
}
string UTrelloInterface::addTask(string listName, string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription)
{
    return connector.addTask(listName, taskName, estimatedTime, taskPriority, taskDescription);
}
string UTrelloInterface::editTask(string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription)
{
    return connector.editTask(taskName, estimatedTime, taskPriority, taskDescription);
}
string UTrelloInterface::assignTask(string taskName, string userName)
{
    return connector.assignTask(taskName, userName);
}
string UTrelloInterface::completeTask(string taskName)
{
    return connector.completeTask(taskName);
}
string UTrelloInterface::moveTask(string taskName, string listName)
{
    return connector.moveTask(taskName, listName);
}
string UTrelloInterface::deleteTask(string taskName)
{
    return connector.deleteTask(taskName);
}
string UTrelloInterface::deleteList(string listName)
{
    return connector.deleteList(listName);
}
int UTrelloInterface::printTotalEstimatedTime()
{
    return connector.printTotalEstimatedTime();
}	
int UTrelloInterface::printTotalRemainingTime()
{
    return connector.printTotalRemainingTime();
}
int UTrelloInterface::printUserWorkload(string userName)
{
    return connector.printUserWorkLoad(userName);
}
string UTrelloInterface::printTask(string taskName)
{
    return connector.printTask(taskName);
}
string UTrelloInterface::printList(string listName)
{
    return connector.printList(listName);
}
string UTrelloInterface::printUserTasks(string userName)
{
    return connector.printUserTasks(userName);
}
string UTrelloInterface::printUserUnfinishedTasks(string userName)
{
    return connector.printUserUnfinishedTasks(userName);
}
string UTrelloInterface::printAllLists()
{
    return connector.printAllLists();
}
string UTrelloInterface::printUnassignedTasksByPriority()
{
    return connector.printUnassignedTasksByPriority();
}	
string UTrelloInterface::printAllUnfinishedTasksByPriority()
{
    return connector.printAllUnfinishedTasksByPriority();
}
string UTrelloInterface::printUsersByWorkload()
{
    return connector.printUsersByWorkload();
}
string UTrelloInterface::printUsersByPerformance()
{
    return connector.printUsersByPerformance();
}

