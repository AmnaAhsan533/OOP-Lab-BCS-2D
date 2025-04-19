#include <iostream>
using namespace std;

class Person {
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual void bonus() = 0;
    virtual ~Person() {}
};

class Admin : virtual public Person {
    double salary;
public:
    void getData() override {
        cout << "Admin Salary: "; cin >> salary;
    }
    void displayData() override {
        cout << "Admin Salary: " << salary << endl;
    }
    void bonus() override {
        cout << "Admin Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
    double salary;
public:
    void getData() override {
        cout << "Account Salary: "; cin >> salary;
    }
    void displayData() override {
        cout << "Account Salary: " << salary << endl;
    }
    void bonus() override {
        cout << "Account Bonus: " << salary * 0.12 << endl;
    }
};

class Master : public Admin, public Account {
    double adminSalary, accountSalary;
public:
    void getData() override {
        cout << "Master Admin Salary: "; cin >> adminSalary;
        cout << "Master Account Salary: "; cin >> accountSalary;
    }
    void displayData() override {
        cout << "Master Admin Salary: " << adminSalary << endl;
        cout << "Master Account Salary: " << accountSalary << endl;
    }
    void bonus() override {
        cout << "Master Bonus: " << (adminSalary + accountSalary) * 0.15 << endl;
    }
};

int main() {
    Person* employees[3];

    employees[0] = new Admin();
    employees[1] = new Account();
    employees[2] = new Master();

    for (int i = 0; i < 3; ++i) {
        cout << "\nEnter data for employee " << i + 1 << ":\n";
        employees[i]->getData();
    }

    for (int i = 0; i < 3; ++i) {
        cout << "\nDetails for employee " << i + 1 << ":\n";
        employees[i]->displayData();
        employees[i]->bonus();
    }

    for (int i = 0; i < 3; ++i) {
        delete employees[i];
    }

    return 0;
}
