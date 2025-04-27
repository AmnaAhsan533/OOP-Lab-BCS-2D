#include<iostream>
#include<fstream>
#include <vector>
#include <string>
using namespace  std;

const string FILENAME = "todo.txt";

void addTask(const string& task){
    ofstream file(FILENAME, ios::app);
    file << "[ ] "<< task <<endl;
    file.close();
    cout<<"Tasl added!\n";
}

void viewTasks(){
    ifstream file(FILENAME);
    string line;
    int index = 1;
    cout << "\nYour To-Do List:\n";
    while (getline(file, line)) {
        cout << index++ << ". " << line << endl;
    }
    file.close();
}

void markAsDone(int taskNo){
    ifstream file(FILENAME);
    vector<string> tasks;
    string line;
    while(getline(file, line)){
        tasks.push_back(line);
    }
    file.close();

    if(taskNo < 1 || taskNo > tasks.size()){
        cout<<"Invalid task number!\n";
        return;
    }

    if(tasks[taskNo - 1].substr(0, 3) == "[ ]")
        tasks[taskNo -1].replace(0, 3, "[X]");

    ofstream outFile(FILENAME, ios::trunc);
    for (const string& task : tasks)
        outFile << task << endl;
    outFile.close();

    cout << "Task marked as done.\n";
}

int main(){

    int choice;
    string task;
    int taskNum;

    do {
        cout << "\n=== To-Do List Manager ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                addTask(task);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as done: ";
                cin >> taskNum;
                markAsDone(taskNum);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
