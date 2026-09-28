#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Task {
    private:
    string description;
    bool completed;

    public:
    Task(string desc){
        description = desc;
        completed = false;
    }

    string getDescription() {
        return description;
    }

    bool isCompleted() {
        return completed;
    }

    void markCompleted() {
        completed = true;
    }
};

class ToDoList {
    private:
    vector<Task> tasks;

    public:

    void addTask(){
        string description;

        cout << "Enter the Task\n";
        cin.ignore();
        getline(cin,description);

        Task newTask(description);

        tasks.push_back(newTask);

        cout<< "Task added successfully\n";
    }

    void viewTasks(){
        if(tasks.empty())
        {
            cout << "No tasks\n";
            return;
        }

        cout << "\n======== Your Tasks ========\n";
        for (int i = 0; i< tasks.size(); i++)
        {
            cout << i + 1 << ". " << tasks[i].getDescription();

            if(tasks[i].isCompleted()){
                cout << " - Completed";
            }
            else
            {
                cout << " - Pending";
            }

            cout << endl;
        }

        cout << "============================\n";
    }

    void markTaskCompleted() {
        if (tasks.empty()){
            cout << "No tasks available.\n";
            return;
        }

        viewTasks();

        int taskNumber;

        cout << "Enter task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber < 1 || taskNumber > tasks.size())
        {
            cout << "Invalid task number!\n";
            return;
        }

        tasks[taskNumber - 1].markCompleted();

        cout << "Task marked as completed!\n";
    }

    void removeTask()
    {
        if (tasks.empty()) 
        {
            cout << "No tasks available.\n";
            return;
        }

        viewTasks();
        int taskNumber;

        cout << "Enter the Task to remove: ";
        cin >> taskNumber;

        if (taskNumber < 1 || taskNumber > tasks.size())
        {
            cout << "Invalid task number!\n";
            return;
        }

        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully\n";
    }

};
int main()
{
    ToDoList todo;
    int choice;

    while (true) {
        cout << "\n";
        cout << "===================\n";
        cout << "       To-Do List\n";
        cout << "===================\n";

        cout << "1. Add Task\n";
        cout << "2. view Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        cout << "Enter your choice\n";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                todo.addTask();
                break;
            
            case 2:
                todo.viewTasks();
                break;
            
            case 3:
                todo.markTaskCompleted();
                break;
            
            case 4:
                todo.removeTask();
                break;
            case 5:
            cout << "Thank you for using the ToDo List\n";
            return 0;

            default:
            cout << "Invalid Choice\n";
        }
                
    }
    return 0;
}