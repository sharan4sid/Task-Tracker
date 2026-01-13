#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>
#include "Task.h"

class FileManager {
public:
    static std::vector<Task> readTasks();
    static void writeTasks(const std::vector<Task>& tasks);
};

#endif
