#include <iostream>

class Base {
public:
    virtual void display() const {
        std::cout << "Base object\n";
    }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived object\n";
    }
};

// Object Slicing: passing by value copies only the Base portion of the object
// The Derived portion is 'sliced' away, losing polymorphic behavior
void displayByValue(Base object) {
    object.display(); // Calls Base::display()
}

// Polymorphism preserved: passing by const reference (&) avoids copying and maintains dynamic binding
void displayByReference(const Base& object) {
    object.display(); // Calls Derived::display() via dynamic dispatch
}

int main() {
    Derived derived;

    // Demonstrating object slicing (pass by value)
    std::cout << "Passing by value: ";
    displayByValue(derived);

    // Demonstrating true polymorphism (pass by const reference &)
    std::cout << "Passing by reference: ";
    displayByReference(derived);

    return 0;
}
