#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>

class TaskManager {
public:
    void addTask(const std::string& desc);
    void updateTask(int id, const std::string& desc);
    void deleteTask(int id);
    void markTask(int id, const std::string& status);
    void listTasks(const std::string& filter = "all");
};

#endif
