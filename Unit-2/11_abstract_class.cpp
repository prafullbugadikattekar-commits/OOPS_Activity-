#include <iostream>

// Abstract base class: contains at least one pure virtual function
class Shape{
    public:
        // Pure virtual function (= 0): forces derived classes to implement area()
        virtual double area() const=0;

        // Virtual destructor for safe polymorphic destruction
        virtual ~Shape() = default;
};

class Rectangle:public Shape{
    private:
        double length;
        double width;

    public:
        Rectangle(double givenLength,double givenWidth)
            :length(givenLength),width(givenWidth){}

        // override keyword: provides concrete implementation of pure virtual function
        double area() const override{
            return length *width;
        }
};

class Circle: public Shape{
    private:
        double radius;
    public:
        // explicit keyword prevents implicit double-to-Circle conversion
        explicit Circle(double givenRadius):radius(givenRadius){}

        // Concrete implementation of pure virtual area()
        double area() const override{
            return 3.1215926535897793*radius*radius;
        }
};

int main(){
    Rectangle rectangle(5.0,3.0);
    Circle circle(2.0);

    // Calling overridden area() methods on concrete derived objects
    std::cout<<"Rectangle Area:"<<rectangle.area()<<'\n';
    std::cout<<"Circle Area:"<<circle.area()<<'\n';

    return 0;
}
