#include "../include/TaskManager.h"
#include "../include/FileManager.h"
#include "../include/Utils.h"
#include <iostream>

void TaskManager::addTask(const std::string& desc) {
    auto tasks = FileManager::readTasks();

    Task task;
    task.id = tasks.empty() ? 1 : tasks.back().id + 1;
    task.description = desc;
    task.status = "todo";
    task.createdAt = Utils::getCurrentTimestamp();
    task.updatedAt = task.createdAt;

    tasks.push_back(task);
    FileManager::writeTasks(tasks);

    Utils::printSuccess("Task added successfully (ID: " + std::to_string(task.id) + ")");
}

void TaskManager::updateTask(int id, const std::string& desc) {
    auto tasks = FileManager::readTasks();

    for (auto &task : tasks) {
        if (task.id == id) {
            task.description = desc;
            task.updatedAt = Utils::getCurrentTimestamp();
            FileManager::writeTasks(tasks);
            Utils::printSuccess("Task updated");
            return;
        }
    }

    Utils::printError("Task ID not found");
}

void TaskManager::deleteTask(int id) {
    auto tasks = FileManager::readTasks();

    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            FileManager::writeTasks(tasks);
            Utils::printSuccess("Task deleted");
            return;
        }
    }

    Utils::printError("Task ID not found");
}

void TaskManager::markTask(int id, const std::string& status) {
    auto tasks = FileManager::readTasks();

    for (auto &task : tasks) {
        if (task.id == id) {
            task.status = status;
            task.updatedAt = Utils::getCurrentTimestamp();
            FileManager::writeTasks(tasks);
            Utils::printSuccess("Task marked as " + status);
            return;
        }
    }

    Utils::printError("Task ID not found");
}

void TaskManager::listTasks(const std::string& filter) {
    auto tasks = FileManager::readTasks();

    if (tasks.empty()) {
        std::cout << "No tasks found.\n";
        return;
    }

    for (const auto &task : tasks) {
        if (filter == "all" || task.status == filter) {
            std::cout << "[" << task.id << "] "
                      << task.description
                      << " (" << task.status << ")\n";
        }
    }
}
