#include "user.hpp"
string User::getName()
{
    return name;
}
User::User(string userName)
{
    name = userName;
    vector<Task*> temp;
    assignedTasks = temp;
}
vector<Task*> User::getAssignedTasks()
{
    return assignedTasks;
}
void User::assignTask(Task* newTask)
{
    assignedTasks.push_back(newTask);
}
int User::searchTask(string taskName)
{
    for (int i = 0; i < assignedTasks.size(); i++)
        if (assignedTasks[i]->getTaskName() == taskName) return i;
}
void User::deleteTask(string taskName)
{
    int index = searchTask(taskName);
    assignedTasks.erase(assignedTasks.begin() + index);
}
