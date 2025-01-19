#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual double area() const { return 0.0; }
    virtual double perimeter() const { return 0.0; }

    virtual void display() const {
        cout << "Base class display function." << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void display()  {
        cout << "This is a Circle." << endl;
    }
};


class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
    
    void display() const {
        cout << "This is a Rectangle." <<endl;
    }
};


class Triangle : public Shape {
private:
    double a, b, c; 
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double area() const override {
        // Using Heron's formula
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void display() const {
     cout << "This is a Triangle." <<endl;
    }
};

int main() {
    // Static Binding
    Shape* shape_ptr; 
    
    Circle circle(5.0);
    circle.display();

    Rectangle rectangle(4.0, 6.0);
    rectangle.display(); 

    Triangle triangle(3.0, 4.0, 5.0);
    triangle.display(); 

    // Dynamic Binding
    shape_ptr = &circle;
    shape_ptr->display();
    shape_ptr = &rectangle;
    shape_ptr->display();
    shape_ptr = &triangle;
    shape_ptr->display();
    return 0;
}
