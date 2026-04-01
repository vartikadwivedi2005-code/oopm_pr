#include <iostream> 
#include <cmath> 
using namespace std; 
 
// Interface for Shape 
class Shape { 
public: 
    virtual double calculateArea() const = 0; 
    virtual double calculatePerimeter() const = 0; 
 
    virtual ~Shape() {} 
}; 
 
class Rectangle : public Shape { 
private: 
    double length; 
    double width; 
 
public: 
    Rectangle(double l, double w) : length(l), width(w) {} 
    double calculateArea() const override { 
        return length * width; 
    } 
 
    double calculatePerimeter() const override { 
        return 2 * (length + width); 
    } 
}; 
 
 
 
class Circle : public Shape { 
private: 
    double radius; 
public: 
    Circle(double r) : radius(r) {} 
 
    double calculateArea() const override { 
        return M_PI * radius * radius; 
    } 
 
    double calculatePerimeter() const override { 
        return 2 * M_PI * radius; 
    } 
}; 
int main() { 
    Shape* rect = new Rectangle(10, 5); 
    Shape* circ = new Circle(7); 
 
    cout << "Rectangle:" << endl; 
    cout << "Area: " << rect->calculateArea() << endl; 
    cout << "Perimeter: " << rect->calculatePerimeter() << 
endl; 
 
    cout << "Circle:" << endl; 
    cout << "Area: " << circ->calculateArea() << endl; 
    cout << "Perimeter: " << circ->calculatePerimeter() << 
endl; 
 
    delete rect; 
    delete circ; 
    return 0; 
} 
