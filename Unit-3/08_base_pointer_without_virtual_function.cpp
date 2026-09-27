#include <iostream>

// Demonstrates early (static / compile-time) binding without the virtual keyword
class Base {
public:
    void display() const {
        std::cout << "Base display function\n";
    }
};

class Derived : public Base {
public:
    // This hides Base::display() rather than overriding dynamically
    void display() const {
        std::cout << "Derived display function\n";
    }
};

int main() {
    Derived derivedObject;
    // Base class pointer pointing to a Derived class object
    Base* basePointer = &derivedObject;

    // Early binding: calls Base::display() because display() is non-virtual
    // Resolution is based on the pointer's type (Base*), not the underlying object (Derived)
    basePointer->display();

    return 0;
}
