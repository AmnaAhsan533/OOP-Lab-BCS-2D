#include<iostream>
using namespace std;

class Vehicles{
    protected:
    double price;
    public:
    Vehicles(double p): price(p) {}
};

class Car: public Vehicles{
    public:
    int capacity;
    int doors;
    string fuel_type;
    Car(int c, int d, string ft, double p): capacity(c), doors(d), fuel_type(ft), Vehicles(p) {}
};

class Motorcycle: public Vehicles{
    public:
    int cylinders;
    int gears;
    int wheels;
    Motorcycle(int c, int g, int w, double p): cylinders(c), gears(g), wheels(w), Vehicles(p) {}
};

class Audi: public Car{
    public:
    string model_type;
    Audi(int s, int d, string ft, double p, string mt): Car(s, d, ft, p), model_type(mt) {}
    void display(){
        cout << "Audi Car Details:" << endl;
        cout<<"Price: $"<<price<<endl;
        cout<<"Seating Capacity: "<<capacity<<endl;
        cout<<"No. of doors: "<<doors<<endl;
        cout<<"Fuel type: "<<fuel_type<<endl;
        cout<<"Model type: "<<model_type<<endl;
        cout << "------------------------" << endl;
    }
};

class Yamaha: public Motorcycle{
    public:
    string make_type;
    Yamaha(int c, int g, int w, double p, string mt): make_type(mt), Motorcycle(c, g, w, p) {}
    void display(){
        cout << "Yamaha Motorcycle Details:" << endl;
        cout<<"Price: $"<<price<<endl;
        cout<<"No. of cylinders: "<<cylinders<<endl;
        cout<<"No. of gears: "<<gears<<endl;
        cout<<"No. of wheels: "<<wheels<<endl;
        cout<<"Make type: "<<make_type<<endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Audi myAudi(5, 4, "Petrol", 50000, "A6");
    Yamaha myYamaha(2, 6, 2, 15000, "YZF R1");

    myAudi.display();
    myYamaha.display();
    
    return 0;
}