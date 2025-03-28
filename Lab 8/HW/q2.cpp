#include<iostream>
using namespace std;

class Shape{
    double area;
    public:
    Shape(double a): area(a){}
    Shape operator+(Shape& other){
        return Shape(this->area + other.area);
    }
    double getArea(){
        return area;
    }
    void display(){
        cout<<"Area: "<<area<<endl;
    }
};

int main(){
    Shape shape1(20.5);
    Shape shape2(10);

    Shape shape3 = shape1 + shape2;
    cout << "Shape1: ";
    shape1.display();
    cout << "Shape2: ";
    shape2.display();
    cout << "Combined Shape: ";
    shape3.display();
    return 0;
}