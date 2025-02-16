#include<iostream>
#include<string>
using namespace std;

class Invoice{
    string partNo;
    string partDescription;
    int quantity;
    double price;
    public:
    Invoice(string partNo, string partDescription, int quantity, double price){
        this->partNo = partNo;
        this->partDescription = partDescription;
        this->quantity = (quantity > 0)? quantity: 0;
        this->price = (price > 0)? price: 0.0;
    }
    double getInvoiceAmount() const { 
        return quantity * price; 
        }
    void Display() const {
        cout<<"Part Number: "<<partNo<<endl;
        cout<<"Part Description: "<<partDescription<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Price per Item: "<<price<<endl;
        cout<<"Total Invoice: "<<getInvoiceAmount()<<endl;
    }
};

int main(){
    Invoice invoice("1234", "Pencil", 5, 20.0);
    invoice.Display();
}