#include<iostream>
using namespace std;

class Student{
    int id;
    string name;
    public:
    Student(int id, string n): id(id), name(n) {}
    void getStudentDetails(){
        cout<<"Student ID: "<<id<<endl;
        cout<<"Student Name: "<<name<<endl;
    }
};

class Marks: public Student{
    protected:
    int oop, pf, ds, db;
    public:
    Marks(int id, string n, int oop, int pf, int ds, int db): Student(id, n), oop(oop), pf(pf), ds(ds), db(db) {}
    void getMarks(){
        cout<<"Marks obtained\n";
        cout<<"OOP: "<<oop<<"\nPF: "<<pf<<"\nDS: "<<ds<<"\nDB: "<<db<<endl;
    }
};

class Result: public Marks{
    protected:
    int total_marks;
    double avg;
    public:
    Result(int id, string n, int oop, int pf, int ds, int db): Marks(id, n, oop, pf, ds, db) {}
    void calculateTotal(){
        total_marks = oop + pf + ds + db;
        avg = total_marks / 4.0;
    }
    void display(){
        cout<<"Total Marks: "<<total_marks<<"\nAvg: "<<avg<<endl;
    }
};

int main(){
    Result std1(755, "Amna", 90, 85, 80, 75);
    std1.getStudentDetails();
    std1.getMarks();
    std1.calculateTotal();
    std1.display();
    return 0;
}