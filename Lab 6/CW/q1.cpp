#include <iostream>
using namespace std;

class BankAccount {
protected:
    int acc_no;
    double balance;

public:
    BankAccount(int acc, double bal) : acc_no(acc), balance(bal) {}

    virtual void Deposit(double amount) {
        balance += amount;
        cout << "Amount deposited in Account " << acc_no << ". New balance: " << balance << endl;
    }

    virtual bool Withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance in Account " << acc_no << ", can't withdraw!" << endl;
            return false;
        } else {
            balance -= amount;
            cout << "Amount withdrawn from Account " << acc_no << ". Remaining balance: " << balance << endl;
            return true;
        }
    }

    virtual void DisplayBalance() const {
        cout << "Account No: " << acc_no << ", Balance: " << balance << endl;
    }

    void SetBalance(double newBalance) { balance = newBalance; }

    int GetAccountNo() const { return acc_no; }
    double GetBalance() const { return balance; }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int acc, double bal, double rate)
        : BankAccount(acc, bal), interestRate(rate) {}

    void ApplyInterest() {
        double interest = balance * (interestRate / 100) ;
        balance += interest;
        cout << "Interest applied! New Balance: " << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraft_limit = 1000;

public:
    CheckingAccount(int acc, double bal) : BankAccount(acc, bal) {}

    bool Withdraw(double amount) override {
        if (amount > balance + overdraft_limit) {
            cout << "Overdraft Limit exceeded for Account " << acc_no << "!" << endl;
            return false;
        } else {
            balance -= amount;
            cout << "Amount withdrawn with overdraft. Remaining balance: " << balance << endl;
            return true;
        }
    }
};

class BusinessAccount : public BankAccount {
private:
    double corporate_tax;

public:
    BusinessAccount(int acc, double bal, double tax) : BankAccount(acc, bal), corporate_tax(tax) {}

    void ApplyCorporateTax() {
        balance -= corporate_tax;
        cout << "Corporate tax applied. New Balance: " << balance << endl;
    }
};

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}

    virtual void DisplayRole() const = 0; 

    virtual ~Employee() {}
};

class Customer {
private:
    string name;
    int id;
    BankAccount* account;

public:
    Customer(string n, int i, BankAccount* acc) : name(n), id(i), account(acc) {}

    void Deposit(double amount) {
        account->Deposit(amount);
    }

    void Withdraw(double amount) {
        account->Withdraw(amount);
    }

    void DisplayAccount() const {
        account->DisplayBalance();
    }
};

class Teller : public Employee {
public:
    Teller(string n, int i) : Employee(n, i) {}

    void FreezeAccount(BankAccount& acc) {
        cout << "Teller has frozen Account No. " << acc.GetAccountNo() << endl;
    }

    void DisplayRole() const override {
        cout << "Teller: " << name << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, int i) : Employee(n, i) {}

    void OverrideAccountLimit(BankAccount& acc, double newBalance) {
        cout << "Manager overriding balance for Account No. " << acc.GetAccountNo() << endl;
        acc.SetBalance(newBalance);
    }

    void DisplayRole() const override {
        cout << "Manager: " << name << endl;
    }
};

int main() {

    SavingsAccount sa(1001, 5000, 3.5);
    CheckingAccount ca(1002, 2000);
    BusinessAccount ba(1003, 10000, 500);

    Customer customer("Ali", 1, &sa);
    Teller teller("Sara", 2);
    Manager manager("Dawood", 3);

    cout << "\nCustomer Operations\n";
    customer.Deposit(2000);
    customer.Withdraw(3000);
    customer.DisplayAccount();

    cout << "\nManager Operations\n";
    manager.OverrideAccountLimit(sa, 8000);
    sa.DisplayBalance();

    cout << "\nTeller Freezing an Account\n";
    teller.FreezeAccount(ca);

    return 0;
}
