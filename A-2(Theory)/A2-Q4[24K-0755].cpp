#include <iostream>
#include <string>
using namespace std;

// Function to generate a hash for the password
unsigned long hashPassword(const string &password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = (hash * 33) + c;
    }
    return hash;
}

// Base User Class
class User {
protected:
    string name, email;
    int id;
    unsigned long hash_password;
    string permissionList[5];
    int permCount;

public:
    User(int id, string n, string e, string password, string *perms, int count)
        : id(id), name(n), email(e), permCount(count) {
        for (int i = 0; i < permCount; i++) {
            permissionList[i] = perms[i];
        }
        hash_password = hashPassword(password);
    }

    bool authenticatePassword(string password) {
        return hash_password == hashPassword(password);
    }

    virtual void display() {
        cout << "ID: " << id << "\nName: " << name << "\nEmail: " << email << endl;
        cout << "Permissions: ";
        for (int i = 0; i < permCount; i++) {
            cout << permissionList[i] << ", ";
        }
        cout << endl;
    }

    bool hasPermission(const string &action) {
        for (int i = 0; i < permCount; i++) {
            if (permissionList[i] == action)
                return true;
        }
        return false;
    }
    string getName(){ return name; }
};

// Student Class
class Student : public User {
protected:
    int assignments[5];

public:
    Student(int id, string n, string e, string password, string perm[], int count)
        : User(id, n, e, password, perm, count) {
        for (int i = 0; i < 5; i++) {
            assignments[i] = 0;
        }
    }

    void submitAssignment(int index) {
        if (index >= 0 && index < 5) {
            assignments[index] = 1;
            cout << "Assignment " << index + 1 << " submitted!\n";
        }
    }

    void display() override {
        User::display();
        cout << "Assignments\n";
        for (int i = 0; i < 5; i++) {
            cout << (i + 1) << ": " << (assignments[i] ? "Submitted" : "Not submitted") << "\n";
        }
        cout << "\n";
    }
};

// TA Class
class TA : public Student {
    Student *students[10];
    string projects[2];
    int std_count;
    int proj_count;

public:
    TA(int id, string n, string e, string password, string perm[], int count)
        : Student(id, n, e, password, perm, count), std_count(0), proj_count(0) {}

    void display() override {
        Student::display();
        cout << "TA managing " << std_count << " students.\n";
        cout << "Projects: ";
        for (int i = 0; i < proj_count; i++) {
            cout << projects[i] << ", ";
        }
        cout << endl;
    }

    void assignStudent(Student *s) {
        if (std_count >= 10) {
            cout << "Max capacity reached! Cannot assign more students\n";
            return;
        } else {
            students[std_count++] = s;
            cout << "Assigned "<<s->getName()<<" to TA.\n";
        }
    }

    void addProject(string project) {
        if (proj_count < 2) {
            projects[proj_count++] = project;
            cout << "Project added: " << project << "\n";
        } else {
            cout << "Cannot add more than 2 projects.\n";
        }
    }
};

// Professor Class
class Professor : public User {
public:
    Professor(int id, string n, string e, string password, string perm[], int count)
        : User(id, n, e, password, perm, count) {}

    void display() override {
        User::display();
        cout << "Professor has full lab access.\n";
    }

    void assignProjectToTA(TA &ta, string project) {
        ta.addProject(project);
        cout<<project<<" assign to "<<ta.getName()<<endl;
    }
};

bool authenticateAndPerformAction(User *user, string action) {
    string password;
    cout << "Enter password for authentication: ";
    cin >> password;

    if (!user->authenticatePassword(password)) {
        cout << "Authentication failed. Action denied!\n";
        return false; 
    }

    if (user->hasPermission(action)) {
        cout << "Authentication successful! Action '" << action << "' allowed.\n";
        return true;
    } else {
        cout << "Authentication successful, but insufficient permissions for action: " << action << "\n";
        return false;
    }
}


int main() {
    string studentPerm[] = {"submit_assignment"};
    string taPerm[] = {"view_projects", "manage_students"};
    string profPerm[] = {"assign_projects", "full_lab_access"};

    Student s1(755, "Amna", "k240755@nu.edu.pk", "amna123", studentPerm, 1);
    TA ta1(4293, "Anaksha", "k224293@nu.edu.pk", "anaksha123", taPerm, 2);
    Professor p1(101, "Abeeha", "abeeha.sattar@nu.edu.pk", "abeeha123", profPerm, 2);

    cout << "--- Displaying Users ---\n";
    s1.display();
    cout<<endl;
    ta1.display();
    cout<<endl;
    p1.display();
    cout<<endl;

    cout << "\n--- Authenticating and Performing Actions ---\n";
    cout<<"For student\n";
    if(authenticateAndPerformAction(&s1, "submit_assignment")){
        cout << "\n--- Student Submitting Assignment ---\n";
        s1.submitAssignment(0);
    }
    

    cout<<"For TA\n";
    if(authenticateAndPerformAction(&ta1, "manage_students")){
        cout << "\n--- TA Assigning Student ---\n";
        ta1.assignStudent(&s1);
    }


    cout<<"For Professor\n";
    if(authenticateAndPerformAction(&p1, "assign_projects")){
        cout << "\n--- Professor Assigning Project to TA ---\n";
        p1.assignProjectToTA(ta1, "Grok3 Research");
    }

    return 0;
}
