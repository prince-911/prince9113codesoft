#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task {
    string description;
    bool completed;

    task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<task> tasks;

public:
    void addTask(string description) {
        tasks.push_back(task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            cout << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Removed task: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    while (true) {
        cout << "\nTo-Do List " << endl;
        cout << "1. To Add The Task" << endl;
        cout << "2. To View Tasks" << endl;
        cout << "3. Mark The Task as Completed" << endl;
        cout << "4. To Remove the Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Please Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cin.ignore();  // Clear the newline from the buffer
                    string task;
                    cout << "Enter task description: ";
                    getline(cin, task);
                    toDoList.addTask(task);
                    break;
                }
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                {
                    int index;
                    cout << "Enter task index of task to mark as completed: ";
                    cin >> index;
                    toDoList.markTaskCompleted(index - 1);
                    break;
                }
            case 4:
                {
                    int index;
                    cout << "Enter task index to remove: ";
                    cin >> index;
                    toDoList.removeTask(index - 1);
                    break;
                }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
