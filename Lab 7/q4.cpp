#include<iostream>
#include<vector>
using namespace std;

class Person {
    protected:
    string name;
    int id;
    string address;
    string phoneNo;
    string email;
    public:
    Person(string n, int id, string add, string no, string e):
        name(n), id(id), address(add), phoneNo(no), email(e) {}
    virtual void displayInfo(){
        cout<<"Name: "<<name<<"\nID: "<<id<<"\nAddress: "<<address<<"\nPhone number: "<< phoneNo<<"\nEmail: "<<email<<endl;
    }
    virtual void updateInfo(string newAddr, string newPhone, string newMail) {
        address = newAddr;
        phoneNo = newPhone;
        email = newMail;

    }

};

class Student: public Person{
    vector<string> coursesEnrolled;
    float gpa;
    int enrollmentYear;
    public:
    Student(string n, int id, string add, string no, string e, vector<string> courses, float gpa, int year ) :
    Person(n, id, add, no, e), coursesEnrolled(courses), gpa(gpa), enrollmentYear(year) {}
    void displayInfo() override{
        cout<<"=====Student Details=====\n";
        Person::displayInfo();
        cout<<"Enrollment Year: "<<enrollmentYear<<"\nGPA: "<<gpa<<"\nCourses Enrolled: ";
        for(const auto& course: coursesEnrolled){
            cout<<course<<" ";
        }
        cout<<endl;
    }

};

class Professor: public Person{
    string department;
    vector<string>coursesTaught;
    double salary;
    public:
    Professor(string n, int id, string add, string no, string e, string d, vector<string>courses, double sal) :
    Person(n, id, add, no, e), department(d), coursesTaught(courses), salary(sal) {}
    void  displayInfo() override{
        cout<<"=====Professor Details\n";
        Person::displayInfo();
        cout<<"Department: "<<department<<"\nSalary: "<<salary<<"\nCourses Taught: ";
        for(const auto& course: coursesTaught){
            cout<<course<<" ";
        }
        cout<<endl;
    }
    
};

class Staff: public Person{
    string department;
    string position;
    double salary;
    public:
    Staff(string n, int id, string add, string no, string e, string depart, string pos, double sal) :
    Person(n, id, add, no, e), department(depart), position(pos), salary(sal) {}
    void displayInfo() override{
        cout<<"=====Staff Details=====\n";
        Person::displayInfo();
        cout<<"Department: "<<department<<"\nPosition: "<<position<<"\nSalary: "<<salary<<endl;
    }
    
};

class Course{
    string courseID;
    string courseName;
    int credits;
    Professor* instructor;
    vector<Student*> studentsEnrolled;
    string schedule;
    public:
    Course(string id, string name, int cred, Professor* prof, string sched):
        courseID(id), courseName(name), credits(cred), schedule(sched), instructor(prof) {}
    void registerStudent(Student* s){
        studentsEnrolled.push_back(s);
    }
    string calculateGrades(float marks){
        string grade;
        if(marks >= 90){
            grade = "A+";
        }else if(marks >= 80 && marks < 90){
            grade = "A";
        }else if(marks >= 70 && marks < 80){
            grade = "B";
        }else if(marks < 70){
            grade = "F";
        }
        return grade;
    }
};

int main(){
    Professor prof("Dr. Aftab", 1001, "123 Univ St.", "01234567891", "aftab@nu.edu.pk", "CS", {"CS101", "CS102"}, 90000);
    Student std("Amna Ahsan", 755, "456 St.","01234678501", "k240755@nu.edu.pk", {"CS101"}, 3.9, 2024);
    Staff staff("Ali", 2001, "abc road", "02341567891", "ali@nu.edu.pk", "HR", "Manager", 50000);

    Course cs101("CS101", "Intro to CS", 3, &prof, "Mon-Wed 10AM");
    cs101.registerStudent(&std);
    prof.displayInfo();
    std.displayInfo();
    staff.displayInfo();

    return 0;
}