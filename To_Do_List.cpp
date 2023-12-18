#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;

    cout << "Welcome to the To-Do List Manager!\n";

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nTo-Do List Manager Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, description);

    tasks.emplace_back(description);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "") << tasks[i].description << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    viewTasks(tasks);

    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int index;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid index. Please enter a valid index.\n";
    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);

    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int index;
    cout << "Enter the index of the task to remove: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid index. Please enter a valid index.\n";
    }
}
