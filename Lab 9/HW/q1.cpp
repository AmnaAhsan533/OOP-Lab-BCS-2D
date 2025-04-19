#include<iostream>
using namespace std;

class Shape{
public:
    double area;
    Shape(double a): area(a) {}
    virtual void getArea() = 0;
    virtual ~Shape(){}
};

class Rectangle: public Shape{
public:
    Rectangle(double a): Shape(a) {}
    void getArea() override{
        cout<<"Area of Rectangle is "<<area<<endl;
    }
};

class Triangle: public Shape{
public:
    Triangle(double a): Shape(a) {}
    void getArea() override{
        cout<<"Area of Triangle is "<<area<<endl;
    }
};

int main(){
    Shape *s1, *s2;
    s1 = new Rectangle(30.5);
    s2 = new Triangle(20);
    s1->getArea();
    s2->getArea();
    return 0;
}
