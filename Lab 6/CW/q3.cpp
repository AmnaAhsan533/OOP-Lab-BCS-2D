#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
    string name;
    int id;
    Employee(int id, string n) : id(id), name(n) {}
    virtual ~Employee() {}
    virtual void displayRole() = 0;
};

class OrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~OrderTaker() {}
};

class OrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~OrderPreparer() {}
};

class Biller {
public:
    virtual void generateBill() = 0;
    virtual ~Biller() {}
};

class Waiter : public Employee, public OrderTaker {
public:
    Waiter(int id, string n) : Employee(id, n) {}
    void displayRole() override { cout << name << " is a Waiter.\n"; }
    void takeOrder() override { cout << name << " is taking an order.\n"; }
};

class Chef : public Employee, public OrderPreparer {
public:
    Chef(int id, string n) : Employee(id, n) {}
    void displayRole() override { cout << name << " is a Chef.\n"; }
    void prepareOrder() override { cout << name << " is preparing the food.\n"; }
};

class Cashier : public Employee, public Biller {
public:
    Cashier(int id, string n) : Employee(id, n) {}
    void displayRole() override { cout << name << " is a Cashier.\n"; }
    void generateBill() override { cout << name << " is generating the bill.\n"; }
};

class Manager : public Employee, public OrderTaker, public Biller {
public:
    Manager(int id, string n) : Employee(id, n) {}
    void displayRole() override { cout << name << " is a Manager.\n"; }
    void takeOrder() override { cout << name << " (Manager) is taking an order.\n"; }
    void generateBill() override { cout << name << " (Manager) is generating the bill.\n"; }
};

int main() {
    vector<Employee*> employees;
    employees.push_back(new Chef(101,"Sara"));
    //employees.push_back(new Cashier(102,"Hamid")); //if no cashier available then manager will generate bill
    employees.push_back(new Waiter(103, "Ali")); //if no waiter available then manager will take orders
    employees.push_back(new Manager(104, "Dawood"));

    bool foundWaiter = false;
    bool foundCashier = false;

    cout << "Restaurant Employees and Their Roles:\n";
    for (Employee* emp : employees) {
        emp->displayRole();
    }

    cout << "\nTaking Orders\n";
    for (Employee* emp : employees) {
        OrderTaker* orderTaker = dynamic_cast<OrderTaker*>(emp);
        if (orderTaker) {
            if (!foundWaiter || dynamic_cast<Waiter*>(emp)) {
                orderTaker->takeOrder();
                foundWaiter = true; 
            }
        }
    }

    cout << "\nPreparing Orders\n";
    for (Employee* emp : employees) {
        OrderPreparer* preparer = dynamic_cast<OrderPreparer*>(emp);
        if (preparer) {
            preparer->prepareOrder();
        }
    }

    cout << "\nGenerating Bills\n";
    for (Employee* emp : employees) {
        Biller* biller = dynamic_cast<Biller*>(emp);
        if (biller) {
            if (!foundCashier || dynamic_cast<Cashier*>(emp)) {
                biller->generateBill();
                foundCashier = true; 
            }
        }
    }

    for (Employee* emp : employees) {
        delete emp;
    }

    return 0;
}
