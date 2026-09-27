#include <iostream>

class Base {
public:
    // virtual destructor: essential when deleting derived objects via base class pointer
    // Ensures derived destructor is invoked first, preventing memory/resource leaks
    virtual ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    // override keyword explicitly marks destructor override
    ~Derived() override {
        std::cout << "Derived destructor\n";
    }
};

int main() {
    // Dynamic allocation of Derived object held by Base pointer
    Base* pointer = new Derived();

    // Deleting via base pointer: virtual destructor guarantees Derived dtor executes before Base dtor
    delete pointer;

    return 0;
}
