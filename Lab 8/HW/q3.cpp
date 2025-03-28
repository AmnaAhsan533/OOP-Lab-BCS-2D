
#include <iostream>
using namespace std;

class Person {
protected:
    int id;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> id;
    }
    void display(){
        cout<<"ID: "<<id<<endl;
    }

};

class Admin: public Person {
protected:
    string name;
    double monthlyIncome;
public:
void getData() {
    Person::getData(); 
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Monthly Income: ";
    cin >> monthlyIncome;
    }
    double calculateBonus(){
        return monthlyIncome * 0.05 * 12;
    }
    void display(){
        Person::display();
        cout<<"Name: "<<name<<"\nMonthly Income: "<<monthlyIncome<<"\nBonus: "<<calculateBonus()<<endl;
    }

};

class Accounts: public Person {
protected:
    string name;
    double monthlyIncome;
public:
void getData() {
    Person::getData(); 
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Monthly Income: ";
    cin >> monthlyIncome;
    }
    double calculateBonus(){
        return monthlyIncome * 0.05 * 12;
    }
    void display(){
        Person::display();
        cout<<"Name: "<<name<<"\nMonthly Income: "<<monthlyIncome<<"\nBonus: "<<calculateBonus()<<endl;
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;
    
    cout << "Enter details for Admin Employee:\n";
    adminEmp.getData();
    cout << "\nEnter details for Accounts Employee:\n";
    accountsEmp.getData();
    
    cout << "\nDisplaying Employee Details:\n";
    cout << "\nAdmin Employee:\n";
    adminEmp.display();
    
    cout << "\nAccounts Employee:\n";
    accountsEmp.display();
    return 0;
}