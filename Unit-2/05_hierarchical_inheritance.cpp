#include<iostream>
#include<string>
#include<utility>

// Common base class for hierarchical inheritance
class Vehicle{
    protected:
        std::string registrationNumber;

    public:
        // explicit constructor avoids implicit conversions from std::string
        explicit Vehicle(std::string registration)
            :registrationNumber(std::move(registration)){}

        // const member function: leaves vehicle state unmodified
        void start() const{
            std::cout<<"Vehicle "<<registrationNumber<<" started\n";
        }
};

// First derived branch of Vehicle
class Car: public Vehicle{
    public:
        explicit Car(std::string registration):Vehicle(std::move(registration)){}

        void openBoot() const{
            std::cout<<"Car boot opened\n";
        }
};

// Second derived branch of Vehicle (demonstrating hierarchical inheritance)
class Bike:public Vehicle{
    public:
        explicit Bike(std::string registration): Vehicle(std::move(registration)){}

        void helmetReminder() const{
            std::cout<<"Please wear a helmet\n";
        }
};

int main(){
    Car car("MH12AB1234");
    Bike bike("MH12CD5678");

    // Calling inherited and specific member functions on Car
    car.start();
    car.openBoot();

    // Calling inherited and specific member functions on Bike
    bike.start();
    bike.helmetReminder();

    return 0;
}
