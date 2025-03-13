#include <iostream>
#include <string>
using namespace std;

class Skill {
public:
    int skillID;
    string skillName;
    string description;
    Skill(int id = 0, string name = "", string des = "") :
     skillID(id), skillName(name), description(des) {}

    void showSkillDetails() {
        cout << "Skill ID: " << skillID << "\nSkill Name: " <<
         skillName << "\nDescription: " << description << endl;
    }
    void updateSkillDetails(string newDescription) {
        description = newDescription;
    }
};
class Sport {
public:
    int sportID;
    string name;
    string description;
    Skill* requiredSkills;
    int skillCount;
    Sport(int id = 0, string n = "", string des = "") : sportID(id), 
    name(n), description(des), skillCount(0) {
        requiredSkills = new Skill[10];
    }   
    ~Sport() { delete[] requiredSkills; }
    void addSkill(Skill s) {
        if (skillCount < 10) {
            requiredSkills[skillCount++] = s;
        } else cout << "Skill list is full!" << endl;
    }
    void removeSkill(int skillID) {
        for (int i = 0; i < skillCount; i++) {
            if (requiredSkills[i].skillID == skillID) {
                for (int j = i; j < skillCount - 1; j++) {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                skillCount--;
                break;
            }
        }
    }
};

class Mentor; 
class Student {
public:
    int studentID;
    string name;
    int age;
    Sport* sportsInterests;
    int sportCount;
    Mentor* mentorAssigned;

    Student(int id = 0, string n = "", int a = 0) : 
    studentID(id), name(n), age(a), sportCount(0), mentorAssigned(nullptr) {
        sportsInterests = new Sport[5];
    }   
    ~Student() {
        delete[] sportsInterests;
    }
    void registerForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(Sport s) {
        if (sportCount < 5) {
            sportsInterests[sportCount++] = s;
        } else {
            cout << "Cannot add more sports interests!" << endl;
        }
    }
};
class Mentor {
public:
    int mentorID;
    string name;
    Sport* sportsExpertise;
    int sportCount;
    int maxLearners;
    Student** assignedLearners;
    int learnerCount;

    Mentor(int id = 0, string n = "", int max = 3) : mentorID(id), 
    name(n), maxLearners(max), learnerCount(0), sportCount(0) {
        sportsExpertise = new Sport[5];
        assignedLearners = new Student * [maxLearners];  
    }    
    ~Mentor() {
        delete[] sportsExpertise;
        delete[] assignedLearners;
    }
    bool assignLearners(Student* s) {
        if (learnerCount < maxLearners) {
            assignedLearners[learnerCount++] = s;
            s->mentorAssigned = this;
            return true;
        }
        cout << "Mentor capacity full!" << endl;
        return false;
    }
    void removeLearner(Student* s) {
        for (int i = 0; i < learnerCount; i++) {
            if (assignedLearners[i] == s) {
                for (int j = i; j < learnerCount - 1; j++) {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                learnerCount--;
                s->mentorAssigned = nullptr;
                cout << s->name << " has been removed from mentorship under " <<
                 name << "." << endl;
                return;
            }
        }
        cout << "Student not found in mentor's list!" << endl;
    }

    void viewLearners() {
        cout << "Mentor: " << name << "\nAssigned Learners: " << endl;
        if (learnerCount == 0) {
            cout << "No learners assigned yet." << endl;
            return;
        }
        for (int i = 0; i < learnerCount; i++) {
            cout << "- " << assignedLearners[i]->name << endl;
        }
    }

    void provideGuidance() {
        cout << "Mentor " << name << " is providing guidance to students." <<endl;
    }
};
void Student::registerForMentorship(Mentor* m) {
    if (m->assignLearners(this)) {
        mentorAssigned = m;
        cout<<name<<" successfully registered under mentor "<<m->name<<"!"<<endl;
    }
}
void Student::viewMentorDetails() {
    if (mentorAssigned) {
        cout << "Mentor name: " << mentorAssigned->name << endl;
    } else {
        cout << "No mentor assigned." << endl;
    }
}
int main() {
    cout << "\nName: Amna Ahsan\nID: 24K-0755\n\n";
    Mentor m1(1, "Ali", 3);
    Student std1(101, "Saad", 20);
    Student std2(102, "Arham", 21);
    Student std3(103, "Ayesha", 22);
    Student std4(104, "Bilal", 23); 

    Sport tennis(201, "Tennis", "A racket sport played individually or in pairs.");

    m1.sportsExpertise[m1.sportCount++] = tennis;

    std1.sportsInterests[std1.sportCount++] = tennis;
    std2.sportsInterests[std2.sportCount++] = tennis;
    std3.sportsInterests[std3.sportCount++] = tennis;
    std4.sportsInterests[std4.sportCount++] = tennis;

    std1.registerForMentorship(&m1);
    std2.registerForMentorship(&m1);
    std3.registerForMentorship(&m1);
    std4.registerForMentorship(&m1); 

    m1.viewLearners();
    m1.removeLearner(&std2);
    m1.viewLearners();

    return 0;
}
