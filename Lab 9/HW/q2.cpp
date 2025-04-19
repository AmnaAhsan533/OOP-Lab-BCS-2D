#include<iostream>
using namespace std;

class Car{
public:
    string model;
    double price;
    Car(string m): model(m), price(0.0) {}
    string getModel(){ return model; }
    double getprice(){ return price; }
    void setmodel(string m) {
        model = m;
    }
    virtual void setprice(double p) = 0;
    virtual void display() = 0;
    virtual ~Car(){}
};

class Color: public Car{
    string color;
public:
    Color(string m, string c): Car(m), color(c) {}
    void setprice(double p) override {
        if (p > 0)
            price = p;
        else
            cout << "Invalid price for Color car." << endl;
    }
     void setColor(string c) {
        color = c;
    }

    string getColor() const {
        return color;
    }
    void display() override{
        cout << "Car Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Price: $" << price << endl;
    }
};

class Company: public Car{
    string company;
public:
    Company(string m, string comp) : Car(m), company(comp) {}

    void setCompany(string comp) {
        company = comp;
    }

    string getCompany() const {
        return company;
    }
    void setprice(double p) override {
        if (p >= 10000) // Suppose company cars must be expensive
            price = p;
        else
            cout << "Price too low for Company car." << endl;
    }
    void display() override{
        cout << "Car Model: " << model << endl;
        cout << "Company: " << company << endl;
        cout << "Price: $" << price << endl;
    }
};

int main(){
    Car *c1, *c2;
    c1 = new Color("Model X", "Red");
    c1->setprice(30000);
    cout<<"--- Color Car Info ---\n";
    c1->display();
    cout<<endl;
    c2 = new Company("Model Y", "Tesla");
    c2->setprice(50000);
    cout << "--- Company Car Info ---" << endl;
    c2->display();
    return 0;
}