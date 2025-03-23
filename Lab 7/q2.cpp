#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Shape{
    protected:
    string color;
    pair<float, float> position;
    float borderThickness;
    public:
    Shape(float x, float y, string c , float bt = 1.0) 
        : position({x, y}), color(c), borderThickness(bt) {}
    virtual void draw() = 0;
    virtual float CalculateArea() = 0;
    virtual float CalculatePerimeter() = 0;
    void printPosition() const {
        cout << "Position: (" << position.first << ", " << position.second << ")\n";
    }
    virtual ~Shape(){}
};

class Circle: public Shape{
    float radius;
    public:
    Circle(float r, float x, float y, string c , float bt = 1.0)
        : Shape(x, y, c, bt), radius(r) {}
    void draw() override {
        cout << "Drawing Circle at Position (" << position.first << ", " 
        << position.second << ") with radius " << radius << " and color " << color << "\n";
    }
    float CalculateArea() override {
        return M_PI * radius * radius;
    }
    float CalculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle: public Shape{
    float width;
    float height;
    public:
    Rectangle(float w, float h, float x, float y, string c , float bt = 1.0)
        : Shape(x, y, c, bt), width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle at Position (" << position.first << ", " 
        << position.second << ") with width " << width << " and height " << height << "\n";
    }
    float CalculateArea() override {
        return width * height;
    }
    float CalculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle: public Shape{
    pair<float, float> v1, v2, v3; // Three vertices
    public:
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3, string c, float bt = 1.0)
        : Shape(x1, y1, c, bt), v1({x1, y1}), v2({x2, y2}), v3({x3, y3}) {}
    void draw() override {
        cout << "Drawing Triangle with vertices (" << v1.first << ", " << v1.second << "), (" 
        << v2.first << ", " << v2.second << "), (" << v3.first << ", " << v3.second << ")\n";
    }
    float CalculateArea() override {
        return 0.5 * abs(v1.first * (v2.second - v3.second) + v2.first * (v3.second - v1.second) + v3.first * (v1.second - v2.second));
    }
    float CalculatePerimeter() override {
        double a = hypot(v1.first - v2.first, v1.second - v2.second);
        double b = hypot(v2.first - v3.first, v2.second - v3.second);
        double c = hypot(v3.first - v1.first, v3.second - v1.second);
        return a + b + c;
    }
};

class Polygon: public Shape{
    vector<pair<float, float>> vertices; // List of vertices
    public:
    Polygon(const vector<pair<float, float>>& v, string c, float bt = 1.0)
    : Shape(v[0].first, v[0].second, c, bt), vertices(v) {}
    void draw() override {
        cout << "Drawing Polygon with " << vertices.size() << " vertices\n";
    }
    float CalculateArea() override {
        double area = 0;
        int n = vertices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += vertices[i].first * vertices[j].second;
            area -= vertices[j].first * vertices[i].second;
        }
        return abs(area) / 2.0;
    }
    float CalculatePerimeter() override {
        double perimeter = 0;
        int n = vertices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            perimeter += hypot(vertices[j].first - vertices[i].first, vertices[j].second - vertices[i].second);
        }
        return perimeter;
    }
};

int main() {
    Shape* shapes[4];
    shapes[0] = new Circle(5, 3.5, 7.2, "red");
    shapes[1] = new Rectangle(4, 6, 1, 1, "blue");
    shapes[2] = new Triangle(0, 0, 3, 0, 3, 4, "green");
    shapes[3] = new Polygon({{0, 0}, {4, 0}, {4, 3}, {0, 3}}, "yellow");

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        shapes[i]->printPosition();
        cout << "Area: " << shapes[i]->CalculateArea() << "\n";
        cout << "Perimeter: " << shapes[i]->CalculatePerimeter() << "\n\n";
    }

    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    return 0;
}
