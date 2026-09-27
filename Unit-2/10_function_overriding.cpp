#include <iostream>

class Vehicle{
    public:
        // virtual keyword: enables dynamic binding / runtime polymorphism
        virtual void move() const{
            std::cout<<"Vehicle is moving \n";
        }

        // virtual destructor: ensures proper cleanup of derived objects through base pointers
        virtual ~Vehicle() = default;
};

class Car:public Vehicle{
    public:
        // override keyword: ensures compiler checks this matches a virtual method in Base
        void move() const override{
            std::cout<<"Car moves on road\n";
        }
};

class Boat:public Vehicle{
    public:
        // Overriding base class virtual function for water movement
        void move() const override{
            std::cout<<"Boat moves on water\n";
        }
};

int main(){
    Car car;
    Boat boat;

    // Calling overridden member functions directly on derived instances
    car.move();
    boat.move();
    return 0;
}
