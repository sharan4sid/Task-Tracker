#include "../include/TaskManager.h"
#include <iostream>

int main(int argc, char* argv[]) {

    TaskManager manager;

    if (argc < 2) {
        std::cout << "Usage: task-cli <command>\n";
        return 0;
    }

    std::string cmd = argv[1];

    if (cmd == "add" && argc >= 3) {
        manager.addTask(argv[2]);
    }
    else if (cmd == "update" && argc >= 4) {
        manager.updateTask(std::stoi(argv[2]), argv[3]);
    }
    else if (cmd == "delete" && argc >= 3) {
        manager.deleteTask(std::stoi(argv[2]));
    }
    else if (cmd == "mark-done" && argc >= 3) {
        manager.markTask(std::stoi(argv[2]), "done");
    }
    else if (cmd == "mark-in-progress" && argc >= 3) {
        manager.markTask(std::stoi(argv[2]), "in-progress");
    }
    else if (cmd == "list") {
        if (argc == 3)
            manager.listTasks(argv[2]);
        else
            manager.listTasks();
    }
    else {
        std::cout << "Invalid command\n";
    }

    return 0;
}
