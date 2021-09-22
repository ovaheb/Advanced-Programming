#include "task.hpp"

Task::Task(string listName, string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription)
{
    list = listName;
    name = taskName;
    time = estimatedTime;
    priority = taskPriority;
    description = taskDescription;
    finished = false;
    assignedTo = UNASSIGNED;
}
string Task::getListName()
{
    return list;
}
void Task::editTaskDetails(unsigned int estimatedTime, unsigned int taskPriority, string taskDescription)
{
    time = estimatedTime;
    priority = taskPriority;
    description = taskDescription;
}
void Task::assignTask(string userName)
{
    assignedTo = userName;
}
void Task::finishTask()
{
    finished = true;
}
void Task::moveTask(string listName)
{
    list = listName;
}

