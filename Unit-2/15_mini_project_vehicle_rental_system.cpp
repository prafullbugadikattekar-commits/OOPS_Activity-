#include <iostream>
#include <string>
#include <utility>

class Vehicle {
protected:
    std::string registrationNumber;
    double ratePerDay;

public:
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}

    // virtual member function: allows derived classes to customize rent calculation
    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    // virtual display function for polymorphic output
    virtual void display() const {
        std::cout << "Registration: " << registrationNumber << '\n';
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    // virtual destructor ensures clean polymorphic deletion
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate), numberOfDoors(doors) {}

    // override keyword guarantees this overrides Vehicle::display()
    void display() const override {
        Vehicle::display(); // Reusing base class display logic
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate), engineCapacity(capacity) {}

    // Overriding base calculateRent() to apply a 10% discount for bikes
    double calculateRent(int days) const override {
        return ratePerDay * days * 0.9;
    }

    // Overriding display() to include bike engine capacity
    void display() const override {
        Vehicle::display();
        std::cout << "Engine Capacity: " << engineCapacity << " cc\n";
    }
};

int main() {
    Car car("MH12AB1234", 2000.0, 5);
    Bike bike("MH12CD5678", 800.0, 150);

    std::cout << "Car Details\n";
    // Calling overridden display and inherited calculateRent on Car
    car.display();
    std::cout << "Rent for 3 days: " << car.calculateRent(3) << "\n\n";

    std::cout << "Bike Details\n";
    // Calling overridden display and overridden calculateRent on Bike
    bike.display();
    std::cout << "Rent for 3 days: " << bike.calculateRent(3) << '\n';

    return 0;
}
