#include<iostream>
using namespace std;

class BankAccount{
    public:
    int acc_no;
    double balance;
    bool isDeposited;
    BankAccount() {}
    BankAccount(double bal): balance(bal) {}

    void Deposit(double amount){
        balance += amount;
        cout<<"Amount deposited!"<<endl;
        isDeposited = true;
    }
    int withdraw(double amount){
        if(amount > balance){
            cout<<"Insufficient balance, can't withdraw!"<<endl;
            return 1;
        } else {
            balance -= amount;
            cout<<"Amount withdrawn!"<<endl;
            return 0;
        }
    }
};

class SavingsAccount : public BankAccount {
    public:
    double interest;
    SavingsAccount(double i): interest(i) {}
    void ApplyInterest(int numOfMonths){
        balance -= (interest * numOfMonths);
    }

};

class CheckingAccount : public BankAccount {
    public:
    double overdraft_amount;
    double overdraft_limit = 1000;
    void overdraft(double loan){
        if(withdraw(loan)){
            overdraft_amount = balance + (loan - overdraft_limit);
            if(overdraft_amount < 0){
                cout<<"Overdraft Limit exceeded!"<<endl;
            } 
        }
    }
};

class BusinessAccount : public BankAccount {
    public:
    double corporate_tax;
    BusinessAccount(double ct): corporate_tax(ct) {}
    void ApplyCorporateTax(){
        if(isDeposited){
            balance -= corporate_tax;
        }       
    }
};

class Employee{
    public:
    string name;
    string type;
    int id;
    Employee(){}
    Employee(string n, string t, int id): name(n), type(t), id(id) {}
};

class Customer: public BankAccount{
    public:
    string name;
    int id;
};

class Teller: private BankAccount, public Employee{
    public:
    bool isFreezed;
    void FreezeAccount(){
        isFreezed = true;
    }
};

class Manager: public BankAccount, public Employee{

};

