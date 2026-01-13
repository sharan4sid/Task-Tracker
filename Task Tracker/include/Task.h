

#ifndef TASK_H
#define TASK_H

#include <string>

struct Task {
    int id;
    std::string description;
    std::string status;      // todo | in-progress | done
    std::string createdAt;
    std::string updatedAt;
};

#endif
