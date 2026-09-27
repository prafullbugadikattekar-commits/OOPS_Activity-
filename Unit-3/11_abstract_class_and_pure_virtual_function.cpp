#include <iostream>

// Abstract base class: contains pure virtual function and cannot be instantiated
class Shape {
public:
    // Pure virtual function (= 0): provides pure interface contract
    virtual double area() const = 0;

    // Virtual destructor for proper polymorphic deletion
    virtual ~Shape() = default;
};

// Concrete derived class implementing the abstract interface
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // override keyword: provides required concrete implementation of area()
    double area() const override {
        return length * width;
    }
};

int main() {
    // Instantiating concrete derived class
    Rectangle rectangle(8.0, 4.0);

    // Calling overridden member function
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';

    return 0;
}
