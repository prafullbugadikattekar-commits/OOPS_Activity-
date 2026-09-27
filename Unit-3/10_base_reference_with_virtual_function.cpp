#include <iostream>

class Shape {
public:
    // virtual keyword enables runtime polymorphic dispatch
    virtual double area() const {
        return 0.0;
    }
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // override keyword: overrides virtual function
    double area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    // explicit keyword: prevents implicit double-to-Circle conversion
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Overrides virtual function
    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius;
    }
};

// Polymorphic function using base reference (&): avoids object slicing and triggers runtime dispatch
void printArea(const Shape& shape) {
    // Dynamic binding: calls correct derived area() method at runtime
    std::cout << "Area: " << shape.area() << '\n';
}

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.0);

    // Calling printArea with derived objects passed by reference (&)
    printArea(rectangle);
    printArea(circle);

    return 0;
}
