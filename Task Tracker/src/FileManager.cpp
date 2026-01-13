#include "../include/FileManager.h"
#include "../include/Utils.h"
#include <fstream>
#include <sstream>

static const std::string FILE_NAME = "tasks.json";

std::vector<Task> FileManager::readTasks() {
    std::vector<Task> tasks;
    std::ifstream file(FILE_NAME);

    if (!file.is_open()) {
        // File doesn't exist → return empty list
        return tasks;
    }

    std::string line;
    while (getline(file, line)) {
        if (line.find("\"id\"") != std::string::npos) {
            Task task;

            task.id = std::stoi(line.substr(line.find(":") + 1));

            getline(file, line);
            task.description = line.substr(line.find(":") + 3);
            task.description.pop_back();
            task.description.pop_back();

            getline(file, line);
            task.status = line.substr(line.find(":") + 3);
            task.status.pop_back();
            task.status.pop_back();

            getline(file, line);
            task.createdAt = line.substr(line.find(":") + 3);
            task.createdAt.pop_back();
            task.createdAt.pop_back();

            getline(file, line);
            task.updatedAt = line.substr(line.find(":") + 3);
            task.updatedAt.pop_back();
            task.updatedAt.pop_back();

            tasks.push_back(task);
        }
    }

    file.close();
    return tasks;
}

void FileManager::writeTasks(const std::vector<Task>& tasks) {
    std::ofstream file(FILE_NAME);

    file << "[\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        const Task& t = tasks[i];
        file << "  {\n";
        file << "    \"id\": " << t.id << ",\n";
        file << "    \"description\": \"" << t.description << "\",\n";
        file << "    \"status\": \"" << t.status << "\",\n";
        file << "    \"createdAt\": \"" << t.createdAt << "\",\n";
        file << "    \"updatedAt\": \"" << t.updatedAt << "\"\n";
        file << "  }";
        if (i != tasks.size() - 1) file << ",";
        file << "\n";
    }
    file << "]";

    file.close();
}
