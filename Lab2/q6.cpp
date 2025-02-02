#include<iostream>
#include<vector>
using namespace std;

struct Subject{
    string name;
};

struct Student{
    int id;
    Subject subjects[5];
};

void print(const vector<Student>& students){
    for(const auto& s:students){
        cout << "Student ID: "<< s.id<< endl;
        cout<<"Subjects: ";
        for(const auto& subj: s.subjects){
            cout << subj.name <<" ";
        }
        cout<<endl<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter no. of students ";
    cin>>n;

    vector<Student> students(n);

    for(int i=0; i<n; i++){
        cout<<"Enter Student ID: ";
        cin>>students[i].id;
        cin.ignore();

        for(int j=0; j<5; j++){
            cout <<"Enter Subject "<<j+1<<":";
            getline(cin, students[i].subjects[j].name);
        }
        cout<<endl;
    }
    cout<<"\nStored Student Information:\n";
    print(students);
}