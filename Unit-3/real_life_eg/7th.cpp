#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Real-world example: Computer-Aided Design (CAD) Shape Rendering Engine
// Abstract base class defining shape interface
class Shape{
    public:
        // Pure virtual functions (= 0): enforce implementation in all concrete geometric shapes
        virtual double area() const =0;
        virtual void draw() const =0;

        // Virtual destructor ensures proper cleanup of derived objects via smart pointers
        virtual ~Shape() = default;
};

class Circle : public Shape{
    private:
        double radius;

    public:
        // explicit keyword: prevents implicit double-to-Circle conversions (e.g. Shape = 5.0)
        explicit Circle(double r) :radius(r) {}

        // override keyword: verifies this function overrides Shape::area()
        // const member function: guarantees no modification to member variables
        double area() const override{
            return 3.141592653589793*radius*radius;
        }

        // override keyword: provides drawing behavior for Circle
        void draw() const override{
            cout<<"Drawing circle with radius "<<radius<<endl;
        }
};

class Rectangle : public Shape{
    private:
        double length;
        double width;

    public:
        // Parameterized constructor using member initializer list
        Rectangle(double l,double w):length(l),width(w){}

        double area() const override{
            return length*width;
        }

        void draw() const override{
            cout<<"Drawing Rectangle with length : "<<length<<" and breadth : "<<width<<endl;
        }
};

class Triangle : public Shape{
    private:
        double base;
        double height;

    public:
        Triangle(double b,double h): base(b),height(h){}

        double area() const override{
            return 0.5*base*height;
        }

        void draw() const override{
            cout<<"Drawing triangle with the base "<<base<<" and height "<<height<<endl;
        }
};

int main(){
    // Storing polymorphic objects using vector of unique_ptr
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0,6.0));
    shapes.push_back(make_unique<Triangle>(3.0,8.0));

    cout<<"=== CAD Shape System ==="<<endl<<endl;
    // Range-based for loop using const reference (&): avoids copying smart pointers and protects data
    for(const auto& shape:shapes){
        // Dynamic binding: calls correct derived draw() and area() at runtime
        shape->draw();
        cout<<"Area: "<<shape->area()<<" square units"<<endl;
    }
}
