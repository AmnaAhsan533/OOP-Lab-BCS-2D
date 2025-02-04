#include<iostream>
using namespace std;

class Employee{
    public:
    string f_name;
    string l_name;
    double monthly_salary;

    void Yearly_salary(double monthly_salary){
        if(monthly_salary < 0){
            monthly_salary = 0.0;
        }
        cout <<"Yearly Salary: "<<monthly_salary *12<<endl;
    }
};

int main(){
    Employee EmployeeTest[2];
    cout<<"Enter monthly salary of emp 1: ";
    cin>>EmployeeTest[0].monthly_salary;
    EmployeeTest[0].Yearly_salary(EmployeeTest[0].monthly_salary);
    cout<<"Enter monthly salary of emp 2: ";
    cin>>EmployeeTest[1].monthly_salary;   
    EmployeeTest[1].Yearly_salary(EmployeeTest[1].monthly_salary);

    cout<<"\nYearly Salary after raise: "<<endl;
    EmployeeTest[0].monthly_salary += EmployeeTest[0].monthly_salary * 0.1;

    EmployeeTest[1].monthly_salary += EmployeeTest[1].monthly_salary * 0.1;
    EmployeeTest[0].Yearly_salary(EmployeeTest[0].monthly_salary);
    EmployeeTest[1].Yearly_salary(EmployeeTest[1].monthly_salary);

    return 0;
}