#include<iostream>
using namespace std;

class Shape{
    public:
    string color;
    double position;
    double borderThickness;
    void draw(){

    }
    void CalculateArea(){

    }
    void calculatePerimeter(){

    }

};

class Circle: public Shape{

};

class Rectangle: public Shape{

};

class Triangle: public Shape{

};

class Polygon: public Shape{

};