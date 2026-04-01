 
#include <iostream> 
#include <cmath>  // For M_PI 
 
// Abstract base class 
class Shape { 
public: 
    virtual double area() = 0; 
 
    virtual ~Shape() {} 
}; 
 
class Circle : public Shape { 
private: 
    double radius; 
 
public: 
    Circle(double r) : radius(r) {} 
 
    double area() override { 
        return M_PI * radius * radius; 
    } 
}; 
 
class Rectangle : public Shape { 
private: 
    double width, height; 
 
public: 
    Rectangle(double w, double h) : width(w), height(h) {} 
 
    double area() override { 
        return width * height; 
    } 
}; 
 
int main() { 
    Shape* circle = new Circle(5.0); 
 
 
    Shape* rectangle = new Rectangle(4.0, 6.0); 
 
    std::cout << "Area of Circle: " << circle->area() << 
std::endl; 
    std::cout << "Area of Rectangle: " << rectangle->area() << std::endl; 
 
    delete circle; 
    delete rectangle; 
 
    return 0; 
} 