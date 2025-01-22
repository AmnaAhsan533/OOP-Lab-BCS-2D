#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
    int id, units;
    float surcharge = 0.0, price = 0.0;
    string name;
    cout<<"ID: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Units: ";
    cin>>units;
    float bill;
    if(units <= 199){
        price = 16.2;
    } else if(units >= 200 && units <300){
        price = 20.1;
    } else if(units >= 300 && units <500){
        price = 27.1;
    } else if(units >= 500){
        price = 35.9;
    }
    bill = units * price;
    if(bill > 18000){
        surcharge = bill * 0.15;
    }
    float net = bill + surcharge;
    cout<<"Customer ID: "<<id<<endl;
    cout<<"Customer Name: "<<name<<endl;
    cout<<"Units Consumed: "<<units<<endl;
    
    cout<<"Amount charges @ Rs."<<price<<" per unit: "<<bill<<endl;
    cout<<"Surcharge Amount: "<<surcharge<<endl;
    cout<<"Net Amount Paid by the customer: "<<net;
}