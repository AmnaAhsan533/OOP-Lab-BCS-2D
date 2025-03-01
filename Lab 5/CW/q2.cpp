#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Car{
    public:
    string name;
    int id;
    
    Car(string n, int id): name(n), id(id) {}
    void display() const{
        cout<<"Car ID: "<<id<<", Name: "<<name<<endl;
    }
};

class Garage{
    vector<Car*> cars;
    public:
    void parkCar(Car* car){
        if(car){
            cars.push_back(car);
        }
    }
    void listCars() const{
        if(cars.empty()){
            cout<<"Garage is empty!"<<endl;
            return;
        }
        cout<<"Cars in Garage\n";
        for(const auto& car : cars){
            if(car){
                cout<<"ID: "<<car->id<<", Name: "<<car->name<<endl;
            }
        }
    }
};

int main() {
    Car car1("Toyota", 101);
    Car car2("Honda", 102);
    Car car3("BMW", 103);

    Garage garage;

    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars();


    // Demonstrate potential pitfall (uncomment below lines to observe)
    {
        Car tempCar("Ford", 104);  // Local scope car
        garage.parkCar(&tempCar);  // Adding a temporary object
    }
    Car car5("Tesla", 105); 
    garage.parkCar(&car5);
    garage.listCars();  // Dangling pointer issue: tempCar no longer exists!

    return 0;
}
