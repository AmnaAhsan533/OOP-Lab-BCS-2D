#include<iostream>
using namespace std;

class Account{
    double balance;
    public:
    Account(double balance){
        this->balance = balance;
    }
    void Credit(double amount){
        balance += amount;
    }
    void Debits(double amount){
        if(amount > balance){
            cout<<"Amount exceeded from balance!";
            return;
        }
        balance -= amount;
    }
    double getBalance(){ return balance; }
};

int main(){
    Account a(1000.0);
    cout<<"Initial Balance: "<<a.getBalance()<<endl;
    a.Credit(100.0);
    cout<<"Balance after credit: "<<a.getBalance()<<endl;
    a.Debits(500.0);
    cout<<"Balance after debit: "<<a.getBalance()<<endl;
}