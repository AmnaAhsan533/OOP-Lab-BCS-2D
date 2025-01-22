#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(int argc, char *argv[]){
    string movie_name;
    double a_ticket, c_ticket, gross_percentage, gross_amount, donated, net;
    int no_a_ticket, no_c_ticket, t_tickets;
    cout<<"Movie name: ";
    getline(cin, movie_name);
    cout<<"Adult ticket price: "; cin>>a_ticket;
    cout<<"Child ticket price: "; cin>>c_ticket;
    cout<<"No. of Adult tickets sold: "; cin>>no_a_ticket;
    cout<<"No. of Child tickets sold: "; cin>>no_c_ticket;
    cout<<"Percentage of the gross amount to be donated to the charity: "; cin>>gross_percentage;
    t_tickets = no_a_ticket + no_c_ticket;
    gross_amount = (a_ticket * no_a_ticket) + (c_ticket * no_c_ticket);
    donated = gross_amount * (gross_percentage / 100);
    net = gross_amount - donated;
    cout<<endl;
    for (int i = 0; i < 35; i++) { 
        cout << "-*";
    }
    cout << endl;
    cout<<left<<setfill('.')<<setw(40)<<"Movie Name: "<<right<<setw(20)<<" "<<movie_name<<endl;
    cout<<left<<setfill('.')<<setw(40)<<"Number of tickets sold: "<<right<<setw(20)<<" "<<t_tickets<<endl;
    cout<<left<<setfill('.')<<setw(40)<<"Gross Amount: "<<right<<setw(20)<<fixed<<setprecision(2)<<" $ "<<gross_amount<<endl;
    cout<<left<<setfill('.')<<setw(40)<<"Percentage of gross amount donated: "<<right<<setw(20)<<fixed<<setprecision(2)<<" "<<gross_percentage<<"%"<<endl;
    cout<<left<<setfill('.')<<setw(40)<<"Amount donated: "<<right<<setw(20)<<fixed<<setprecision(2)<<" $ "<<donated<<endl;
    cout<<left<<setfill('.')<<setw(40)<<"Net sale: "<<right<<setw(20)<<fixed<<setprecision(2)<<" $ "<<net<<endl;


    return 0;
}