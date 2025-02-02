#include<iostream>
#include<string>
using namespace std;

struct Employee{
    int emp_id;
    string emp_name;
    double salary;
};
struct Organisation{
    string org_name;
    string org_number;
    struct Employee emp;
};
int main(){
    Organisation org;
    org.org_name = "NU-Fast";
    org.org_number = "NUFAST123ABC";
    org.emp.emp_id = 127;
    org.emp.emp_name = "Linus Sebastian";
    org.emp.salary = 400000;

    cout << "The size of structure organisation : " << sizeof(Organisation) << endl;
    cout << "Organisation Name : " << org.org_name << endl;
    cout << "Organisation Number : " << org.org_number << endl;
    cout << "Employee id : " << org.emp.emp_id << endl;
    cout << "Employee name : " << org.emp.emp_name << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;
}
