#include "connector.hpp"

Connector::Connector()
{
    vector<User> temp;
    users = temp;
    vector<List> temp2;
    lists = temp2;
    vector<Task*> temp3;
    tasks = temp3;
}
int Connector::searchUser(string userName)
{
    int place = NOT_FOUND_YET;
    for (int i = 0; i < users.size(); i++)
        if (users[i].getName() == userName) place = i;
    return place;
}
int Connector::searchList(string listName)
{
    int place = NOT_FOUND_YET;
    for (int i = 0; i < lists.size(); i++)
        if (lists[i].getName() == listName) place = i;
    return place;
}
int Connector::searchTask(string taskName)
{
    for (int i = 0; i < tasks.size(); i++)
        if (tasks[i]->getTaskName() == taskName) return i;
    return NOT_FOUND_YET;
}
string Connector::addUser(string userName)
{
    int place = searchUser(userName);
    if (place != NOT_FOUND_YET) return "User already exists";
    User newUser(userName);
    users.push_back(newUser);
    return "Success";
}
string Connector::addList(string listName)
{
    int place = searchList(listName);
    if (place != NOT_FOUND_YET) return "List already exists";
    List newList(listName);
    lists.push_back(newList);
    return "Success";
}
string Connector::addTask(string listName, string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription)
{
    int place = searchTask(taskName);
    if (place != NOT_FOUND_YET) return "Task already exists";
    place = searchList(listName);
    if (place == NOT_FOUND_YET) return "List does not exist";
    Task* newTask = new Task(listName, taskName, estimatedTime, taskPriority, taskDescription);
    tasks.push_back(newTask);
    lists[place].addTask(newTask);
    return "Success";
}
string Connector::editTask(string taskName, unsigned int estimatedTime, unsigned int taskPriority, string taskDescription)
{
    int taskIndex = searchTask(taskName);
    if (taskIndex == NOT_FOUND_YET) return "Task does not exist";
    tasks[taskIndex]->editTaskDetails(estimatedTime, taskPriority, taskDescription);
    return "Success";
}
string Connector::assignTask(string taskName, string userName)
{
    int taskPlace = searchTask(taskName);
    if (taskPlace == NOT_FOUND_YET) return "Task does not exist";
    int userPlace = searchUser(userName);
    if (userPlace == NOT_FOUND_YET) return "User does not exist";
    tasks[taskPlace]->assignTask(userName);
    users[userPlace].assignTask(tasks[taskPlace]);
    return "Success";    
}
string Connector::completeTask(string taskName)
{
    int taskPlace = searchTask(taskName);
    if (taskPlace == NOT_FOUND_YET) return "Task does not exist";
    tasks[taskPlace]->finishTask();
    return "Success";
}
string Connector::moveTask(string taskName, string listName)
{
    int taskPlace = searchTask(taskName);
    string oldListName = tasks[taskPlace]->getListName();
    int listPlace = searchList(oldListName);
    int newListPlace = searchList(listName);
    if (taskPlace == NOT_FOUND_YET) return "Task does not exist";
    if (listPlace == NOT_FOUND_YET) return "List does not exist";
    tasks[taskPlace]->moveTask(listName);
    lists[listPlace].deleteTask(taskName);
    lists[newListPlace].addTask(tasks[taskPlace]);
    return "Success";
}
string Connector::deleteTask(string taskName)
{
    int taskPlace = searchTask(taskName);
    if (taskPlace == NOT_FOUND_YET) return "Task does not exist";
    string listName = tasks[taskPlace]->getListName();
    int listPlace = searchList(listName);
    lists[listPlace].deleteTask(taskName);
    string userName = tasks[taskPlace]->getUserAssignedTo();
    if (userName != UNASSIGNED)
    {
        int userPlace = searchUser(userName);
        users[userPlace].deleteTask(taskName);
    }
    tasks.erase(tasks.begin() + taskPlace);
    return "Success";
}
string Connector::deleteList(string listName)
{
    int listPlace = searchList(listName);
    if (listPlace == NOT_FOUND_YET) return "List does not exist";
    vector<Task*> listTasks = lists[listPlace].getTasksWithin();
    for (int i = 0; i < listTasks.size(); i++)
        deleteTask(listTasks[i]->getTaskName());
    lists.erase(lists.begin() + listPlace);
    return "Success";
}
int Connector::printTotalEstimatedTime()
{
    int userWorkLoad, max = 0;
    for (int i = 0; i < users.size(); i++)
    {
        userWorkLoad = 0;
        vector<Task*> userTasks = users[i].getAssignedTasks();
        for (int j = 0; j < userTasks.size(); j++)
            userWorkLoad += userTasks[j]->getEstimatedTime();
        if (userWorkLoad > max) max = userWorkLoad;
    }
    return max;
}
int Connector::printTotalRemainingTime()
{
    int userWorkLoad, max = 0;
    for (int i = 0; i < users.size(); i++)
    {
        userWorkLoad = 0;
        vector<Task*> userTasks = users[i].getAssignedTasks();
        for (int j = 0; j < userTasks.size(); j++)
            if (userTasks[j]->isFinished() == true)
                userWorkLoad += userTasks[j]->getEstimatedTime();
        if (userWorkLoad > max) max = userWorkLoad;
    }
    return max;
}
int Connector::printUserWorkLoad(string userName)
{
    int userWorkLoad = 0;
    int userPlace = searchUser(userName);
    if (userPlace == NOT_FOUND_YET) return 0;
    vector<Task*> userTasks = users[userPlace].getAssignedTasks();
    for (int i = 0; i < userTasks.size(); i++)
        userWorkLoad += userTasks[i]->getEstimatedTime();
    return userWorkLoad;
}
string Connector::printTask(string taskName)
{
    string result;
    int taskPlace = searchTask(taskName);
    if (taskPlace == NOT_FOUND_YET) return "Task does not exist";
    result += tasks[taskPlace]->getTaskName();
    result += "\n";
    result += tasks[taskPlace]->getDescription();
    result += "\n";
    result += "Priority: ";
    result += to_string(tasks[taskPlace]->getPriority());
    result += "\n";
    result += "Estimated Time: ";
    result += to_string(tasks[taskPlace]->getEstimatedTime());
    result += "\n";
    if (tasks[taskPlace]->getUserAssignedTo() != UNASSIGNED)
    {
        result += "Assigned to ";
        result += tasks[taskPlace]->getUserAssignedTo();
    }
    else 
        result += UNASSIGNED;
    result += "\n";
    return result;
}
string Connector::printList(string listName)
{
    int listPlace = searchList(listName);
    if (listPlace == NOT_FOUND_YET) return "List does not exist";
    string result;
    vector<Task*> listTasks = lists[listPlace].getTasksWithin();
    result += "List " + lists[listPlace].getName();
    for (int i = 0; i < listTasks.size(); i++)
        result = result + "\n" + to_string(listTasks[i]->getPriority()) + " | " + listTasks[i]->getTaskName()
        + " | " + listTasks[i]->getUserAssignedTo() + " | " + to_string(listTasks[i]->getEstimatedTime())
        + "h" + "\n";
    return result;
}
string Connector::printUserTasks(string userName)
{
    int userPlace = searchUser(userName);
    if (userPlace == NOT_FOUND_YET) return "User does not exist";
    vector<Task*> userTasks = users[userPlace].getAssignedTasks();
    string result;
    for (int i = 0; i < userTasks.size(); i++)
        result = result + to_string(userTasks[i]->getPriority()) + " | " + userTasks[i]->getTaskName()
        + " | " + userTasks[i]->getUserAssignedTo() + " | " + to_string(userTasks[i]->getEstimatedTime())
        + "h" + "\n";
    return result;
}
string Connector::printAllLists()
{
    string result;
    for (int i = 0; i < lists.size(); i++)
        result += printList(lists[i].getName());
    return result;
}
string Connector::printUserUnfinishedTasks(string userName)
{
    int userPlace = searchUser(userName);
    if (userPlace == NOT_FOUND_YET) return "User does not exist";
    vector<Task*> userTasks = users[userPlace].getAssignedTasks();
    string result;
    for (int i = 0; i < userTasks.size(); i++)
    {
        if (userTasks[i]->isFinished() == false)
            result = result + to_string(userTasks[i]->getPriority()) + " | " + userTasks[i]->getTaskName()
            + " | " + userTasks[i]->getUserAssignedTo() + " | " + to_string(userTasks[i]->getEstimatedTime())
            + "h" + "\n";
    }
    return result;
}
string Connector::printUnassignedTasksByPriority()
{
    string result;
    vector<Task*> unassignedTasks;
    for (int i = 0; i < tasks.size(); i++)
        if (tasks[i]->getUserAssignedTo() == UNASSIGNED)
            unassignedTasks.push_back(tasks[i]);
    for (int i = 0; i < unassignedTasks.size(); i++)
        for (int j = 0; j < unassignedTasks.size() - 1; j++)
            if (unassignedTasks[j]->getPriority() < unassignedTasks[j + 1]->getPriority())
                swap(unassignedTasks[j], unassignedTasks[j+1]);
    for (int i = 0; i < unassignedTasks.size(); i++)
        result = result + to_string(unassignedTasks[i]->getPriority()) + " | " + unassignedTasks[i]->getTaskName()
        + " | " + unassignedTasks[i]->getUserAssignedTo() + " | " + to_string(unassignedTasks[i]->getEstimatedTime())
        + "h" + "\n";
    return result; 
}
string Connector::printAllUnfinishedTasksByPriority()
{
    string result;
    vector<Task*> unfinishedTasks;
    for (int i = 0; i < tasks.size(); i++)
        if (tasks[i]->isFinished() == false)
            unfinishedTasks.push_back(tasks[i]);
    for (int i = 0; i < unfinishedTasks.size(); i++)
        for (int j = 0; j < unfinishedTasks.size() - 1; j++)
            if (unfinishedTasks[j]->getPriority() > unfinishedTasks[j + 1]->getPriority())
                swap(unfinishedTasks[j], unfinishedTasks[j+1]);
    for (int i = 0; i < unfinishedTasks.size(); i++)
        result = result + to_string(unfinishedTasks[i]->getPriority()) + " | " + unfinishedTasks[i]->getTaskName()
        + " | " + unfinishedTasks[i]->getUserAssignedTo() + " | " + to_string(unfinishedTasks[i]->getEstimatedTime())
        + "h" + "\n";
    return result;     
}
string Connector::printUsersByWorkload()
{
    vector<User> allUsers = users;
    int userWorkLoad, nextUserWorkLoad;
    for (int i = 0; i < allUsers.size(); i++)
        for (int j = 0; j < allUsers.size() - 1; j++)
        {
            userWorkLoad = 0;
            nextUserWorkLoad = 0;
            vector<Task*> userTasks = allUsers[j].getAssignedTasks();
            for (int k = 0; k < userTasks.size(); k++)
                userWorkLoad += userTasks[k]->getEstimatedTime();
            userTasks = allUsers[j + 1].getAssignedTasks();
            for (int k = 0; k < userTasks.size(); k++)
                nextUserWorkLoad += userTasks[k]->getEstimatedTime();
            if (nextUserWorkLoad < userWorkLoad)
            { 
                swap(userTasks[j], userTasks[j + 1]);
                swap(allUsers[j], allUsers[j + 1]);
            }
        }
    string result;
    for (int i = 0; i < allUsers.size(); i++)
        result = result + allUsers[i].getName() + "\n";
    return result;
}
string Connector::printUsersByPerformance()
{
    vector<User> allUsers = users;
    int userWorkLoad, nextUserWorkLoad;
    if (allUsers.size() == 0) return "";
    for (int i = 0; i < allUsers.size(); i++)
        for (int j = 0; j < allUsers.size() - 1; j++)
        {
            userWorkLoad = 0;
            nextUserWorkLoad = 0;
            vector<Task*> userTasks = allUsers[j].getAssignedTasks();
            for (int k = 0; k < userTasks.size(); k++)
                userWorkLoad += userTasks[k]->getEstimatedTime();
            userTasks = allUsers[j + 1].getAssignedTasks();
            for (int k = 0; k < userTasks.size(); k++)
                if (userTasks[k]->isFinished() == true)
                    nextUserWorkLoad += userTasks[k]->getEstimatedTime();
            if (nextUserWorkLoad > userWorkLoad)
            { 
                swap(userTasks[j], userTasks[j + 1]);
                swap(allUsers[j], allUsers[j + 1]);
            }
        }
    string result;
    for (int i = 0; i < allUsers.size(); i++)
    {
        result += allUsers[i].getName();
        result += "\n";
    }
    return result;
}