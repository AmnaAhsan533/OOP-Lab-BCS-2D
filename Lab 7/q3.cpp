#include<iostream>
#include<iomanip>
using namespace std;

class Currency{
    protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; //To base currency (Assume USD as base currency)
    public:
    Currency(double a, string code, string symbol, double rate = 0.0):
        amount(a), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    virtual double ConvertToBase() = 0;
    double ConvertTo(Currency& targetCurrency){
        return (ConvertToBase() / targetCurrency.exchangeRate);
    }
    virtual void DisplayCurrency() = 0;
    virtual ~Currency(){}
};

class Dollar: public Currency{
    public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    double ConvertToBase() override {
        return amount * exchangeRate; 
    }
    void DisplayCurrency() override {
        cout << currencySymbol <<fixed<< setprecision(2) << amount << " " << currencyCode <<endl;
    }
};

class Euro: public Currency{
    public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}
    double ConvertToBase() override {
        return amount * exchangeRate; 
    }
    void DisplayCurrency() override {
        cout << currencySymbol <<fixed<< setprecision(2) << amount << " " << currencyCode <<endl;
    }
};

class Rupee: public Currency{
    public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs.", 0.013) {}
    double ConvertToBase() override {
        return amount * exchangeRate; 
    }
    void DisplayCurrency() override {
        cout << currencySymbol <<fixed<< setprecision(2) << amount << " " << currencyCode <<endl;
    }
};

int  main(){
    Dollar usd(100);
    Euro eur(90);
    Rupee pkr(5000);

    usd.DisplayCurrency();
    eur.DisplayCurrency();
    pkr.DisplayCurrency();

    std::cout << "\nConversion Examples:\n";
    std::cout << "100 USD to EUR: " << usd.ConvertTo(eur) << " EUR\n";
    std::cout << "85 EUR to INR: " << eur.ConvertTo(pkr) << " INR\n";
    std::cout << "7500 INR to USD: " << pkr.ConvertTo(usd) << " USD\n";
    return 0;
}
