#include<iostream>
using namespace std;

class Account {
    int accNo;
    double balance;
    string name;
    string accType;
    public:
    void deposit(double amount){
        balance += amount;
        cout<<amount<<" deposited!"<<endl;
    }
    void withdraw(double amount){
        if(amount < balance){
            cout<<"Insufficient balance!"<<endl;
        } else {
            balance -= amount;
            cout<<"Balance withdrwan successfully!"<<endl;
        }
    }
    void calculateInterest(){

    }
    void printStatement(){

    }
    void getaccountInfo(){

    }
};

class SavingsAccount: public Account{

};

class CheckingAccount: public Account{

};

class FixedDepositAccount: public Account{

};