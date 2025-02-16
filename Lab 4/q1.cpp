#include<iostream>
using namespace std;

class Circle{
    double radius;
    public:
    
    Circle(double r){
        radius = r;
    }
    double getArea(){
        return (3.142*radius*radius);
    }
    double getPerimeter(){
        return (2*3.142*radius);
    }
};

int main(){
    double r;
    cout<<"Enter radius: ";
    cin>>r;
    Circle c(r);
    cout<<"Area: "<<c.getArea()<<endl;
    cout<<"Perimeter: "<<c.getPerimeter();
    return 0;
}