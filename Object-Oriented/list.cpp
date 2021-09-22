#include "list.hpp"

List::List(string listName)
{
    name = listName;
    vector<Task*> temp;
    tasksWithin = temp;
}
vector<Task*> List::getTasksWithin()
{
    return tasksWithin;
}
void List::addTask(Task* newTask)
{
    tasksWithin.push_back(newTask);
}
int List::searchTask(string taskName)
{
    for (int i = 0; i < tasksWithin.size(); i++)
        if (tasksWithin[i]->getTaskName() == taskName) return i;
}
void List::deleteTask(string taskName)
{
    int index = searchTask(taskName);
    tasksWithin.erase(tasksWithin.begin() + index);
}