#include <iostream>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolderName;
    double balance;
public:
    Account(string accNo, string holder, double bal)
        : accountNumber(accNo), accountHolderName(holder), balance(bal) {}
    
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }
    
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    
    virtual void calculateInterest() = 0;
    virtual void printStatement() = 0;
    
    void getAccountInfo() {
        cout << "Account Number: " << accountNumber
             << "\nHolder Name: " << accountHolderName
             << "\nBalance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;
public:
    SavingsAccount(string accNo, string holder, double bal, double rate, double minBal)
        : Account(accNo, holder, bal), interestRate(rate), minimumBalance(minBal) {}
    
    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Added: " << interest << " | New Balance: " << balance << endl;
    }
    
    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw! Maintaining minimum balance required." << endl;
        }
    }
    
    void printStatement() override {
        cout << "Savings Account Statement for " << accountHolderName << endl;
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;
public:
    CheckingAccount(string accNo, string holder, double bal, double overdraft)
        : Account(accNo, holder, bal), overdraftLimit(overdraft) {}
    
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
    
    void calculateInterest() override {
        cout << "Checking accounts do not earn interest." << endl;
    }
    
    void printStatement() override {
        cout << "Checking Account Statement for " << accountHolderName << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;
public:
    FixedDepositAccount(string accNo, string holder, double bal, double rate, string maturity)
        : Account(accNo, holder, bal), fixedInterestRate(rate), maturityDate(maturity) {}
    
    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest: " << interest << " (Accrued until " << maturityDate << ")" << endl;
    }
    
    void withdraw(double amount) override {
        cout << "Cannot withdraw before maturity date: " << maturityDate << endl;
    }
    
    void printStatement() override {
        cout << "Fixed Deposit Account Statement for " << accountHolderName << endl;
    }
};

int main() {
    SavingsAccount sa("SA123", "Ahmed", 5000, 5.0, 1000);
    CheckingAccount ca("CA456", "Ali", 2000, 500);
    FixedDepositAccount fda("FD789", "Talha", 10000, 7.5, "2026-12-31");
    
    sa.deposit(1000);
    sa.calculateInterest();
    sa.withdraw(4500);
    sa.printStatement();
    
    cout << "\n-------------------\n";
    
    ca.withdraw(2200);
    ca.printStatement();
    
    cout << "\n-------------------\n";
    
    fda.calculateInterest();
    fda.withdraw(5000);
    fda.printStatement();
    
    return 0;
}
