#include<iostream>
using namespace std;

class Student{
public:
    virtual int getTuition(string status, int crh) = 0;
    virtual ~Student() {}
};

class GraduateStudent: public Student{
    string researchTopic;
public:
    void setResearch(string r){ researchTopic = r; }
    string getResearch(){ return researchTopic; }
    int getTuition(string status, int crh) override{
        int rate = 0;
        if(status == "Undergraduate"){
            rate = 200 * crh;
        } else if(status == "Graduate"){
            rate = 300 * crh;
        } else if(status == "Doctoral"){
            rate = 400 * crh;
        }
        return rate;
    }
};
int main(){
    GraduateStudent grad;
    grad.setResearch("Quantum Computing");
    cout << "Research Topic: " << grad.getResearch() << endl;

    string status;
    int creditHours;

    cout << "Enter student status (Undergraduate / Graduate / Doctoral): ";
    cin >> status;
    cout << "Enter number of credit hours: ";
    cin >> creditHours;

    double tuition = grad.getTuition(status, creditHours);
    cout << "Total Tuition: $" << tuition << endl;

    return 0;
}
