📝 Task Tracker CLI (C++)
https://github.com/sharan4sid/Task-Tracker

A lightweight, production-ready Command Line Task Tracker built using C++.
This tool helps you manage your to-do list directly from the terminal with persistent storage using a local JSON file — no external libraries, no frameworks.

🚀 Features

Add new tasks

Update existing tasks

Delete tasks

Mark tasks as:

todo

in-progress

done

List all tasks

Filter tasks by status

Persistent storage using tasks.json

Clean, modular C++ architecture

🧱 Project Structure
task-tracker/
│
├── src/
│   ├── main.cpp          # CLI entry point
│   ├── TaskManager.cpp  # Core business logic
│   ├── FileManager.cpp  # File & JSON handling
│   └── Utils.cpp        # Utility functions
│
├── include/
│   ├── Task.h           # Task data structure
│   ├── TaskManager.h
│   ├── FileManager.h
│   └── Utils.h
│
├── tasks.json            # Auto-created task storage
├── README.md
└── Makefile (optional)

⚙️ Build Instructions
Compile
g++ src/*.cpp -Iinclude -o task-cli

Run
./task-cli <command> [arguments]

📌 Usage Examples
➕ Add a task
./task-cli add "Buy groceries"

✏️ Update a task
./task-cli update 1 "Buy groceries and cook dinner"

🗑 Delete a task
./task-cli delete 1

🔄 Change task status
./task-cli mark-in-progress 2
./task-cli mark-done 2

📋 List tasks
./task-cli list
./task-cli list todo
./task-cli list in-progress
./task-cli list done

🧾 Task Format (tasks.json)
[
  {
    "id": 1,
    "description": "Buy groceries",
    "status": "todo",
    "createdAt": "2026-01-13 19:40",
    "updatedAt": "2026-01-13 19:40"
  }
]


The file is automatically created if it does not exist.

🧠 Design Decisions

No external libraries → full control over logic

Manual JSON handling → predictable format

Separation of concerns:

CLI logic → main.cpp

Business logic → TaskManager

Storage → FileManager

Designed to be easy to extend (priority, due dates, search)

⚠️ Error Handling

Invalid commands

Missing arguments

Non-existent task IDs

Empty task list

Missing or newly created tasks.json

Errors are handled gracefully with clear terminal messages.

🔮 Future Enhancements

Task priorities

Due dates

Search & sort

Export to CSV

Cross-platform binary

Unit testing

📄 License

This project is open-source and free to use for learning and personal projects.

💡 Why This Project?

This project demonstrates:

CLI application design

File handling in C++

Modular architecture

Real-world problem solving without frameworks

Perfect for learning C++, interview prep, and portfolio projects.
