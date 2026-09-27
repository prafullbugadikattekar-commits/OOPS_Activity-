#include <iostream>
#include <memory>
#include <vector>

// Abstract base class establishing interface for shapes
class Shape {
public:
    // Pure virtual functions (= 0): require implementation in derived classes
    virtual double area() const = 0;
    virtual void displayName() const = 0;

    // Virtual destructor ensuring safe deletion via base pointer
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // override keyword: provides implementation of pure virtual area()
    double area() const override {
        return length * width;
    }

    // override keyword: provides implementation of pure virtual displayName()
    void displayName() const override {
        std::cout << "Rectangle";
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    // explicit constructor prevents implicit numeric conversion
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius;
    }

    void displayName() const override {
        std::cout << "Circle";
    }
};

int main() {
    // Vector holding unique_ptr to base class Shape: stores heterogeneous derived objects
    std::vector<std::unique_ptr<Shape>> shapes;

    // Instantiating derived objects wrapped in smart pointers
    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(std::make_unique<Circle>(2.0));

    // Iterating with const reference (&): avoids copying unique_ptr
    for (const auto& shape : shapes) {
        // Runtime polymorphism / dynamic binding: resolves appropriate derived method
        shape->displayName();
        std::cout << " Area: " << shape->area() << '\n';
    }

    return 0;
}
