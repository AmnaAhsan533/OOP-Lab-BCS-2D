#include<iostream>
using namespace std;

class Wallet{
private:
    double balance;
    double dailyDeposit;
    double dailyWithd;
    const double maxDeposit = 10000.0;
    const double maxWithd = 5000.0;
public:
    Wallet():  balance(0.0), dailyDeposit(0.0), dailyWithd(0.0) {}
    bool deposit(double amount) {
        if(amount <= 0){
            cout<<"Invalid deposit amount!"<<endl;
            return false;
        }
        if (dailyDeposit + amount > maxDeposit){
            cout<<"Deposit failed: Daily deposit limit exceeded!"<<endl;
            return false;
        }
        balance += amount;
        dailyDeposit += amount;
        return true;
    }
    bool withdraw(double amount){
        if(amount > balance){
            cout<<"Withdrawal failed: Insufficient balance!"<<endl;
            return false;
        } else if(balance + amount > maxWithd){
            cout<<"Withdrawal failed: Daily withdrawal limit exceeded!"<<endl;
            return false;
        }
        balance -= amount;
        dailyWithd += amount;
        return true;
    }
    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        dailyDeposit = 0.0;
        dailyWithd = 0.0;
    }
};

class User{
private:
    int userID;
    string name;
    Wallet w;
public:
    User(int id, string nm) : userID(id), name(nm) {}
    bool deposit(double  a){
        cout<<"\n"<<name<<" tries to deposit $"<<a<<endl;
        return w.deposit(a);
    }
    bool withdraw(double  a){
        cout<<"\n"<<name<<" tries to withdraw $"<<a<<endl;
        return w.withdraw(a);
    }
    void checkBalance() const {
        cout << name << "'s Balance: $" << w.getBalance() << endl;
    }

    void resetLimits() {
        w.resetDailyLimits();
    }
};

int main() {
    User amna(1001, "Amna");
    User aisha(1002, "Aisha");

    amna.deposit(3000);
    amna.deposit(8000);   // exceeds daily limit
    amna.withdraw(1000);
    amna.withdraw(4500);  // exceeds daily withdrawal limit
    amna.checkBalance();

    // Reset limits for demonstration
    amna.resetLimits();
    cout<<"\nAfter resetting limits...";

    // Try again
    amna.deposit(5000);
    amna.withdraw(2000);
    amna.checkBalance();

    // Bob’s transactions
    aisha.deposit(2000);
    aisha.withdraw(2500);  // overdraw
    aisha.withdraw(1500);
    aisha.checkBalance();

    return 0;
}
