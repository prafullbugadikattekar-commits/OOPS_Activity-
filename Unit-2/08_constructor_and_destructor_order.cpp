#include <iostream>

// Base class to demonstrate construction and destruction timing
class Base{
    public:
        // Base constructor runs first when derived object is instantiated
        Base(){
            std::cout<<"Base constructors\n";
        }

        // Base destructor runs last (after derived destructor)
        ~Base(){
            std::cout<<"Base Destruction\n";
        }
};

// Derived class publicly inheriting Base
class Derived : public Base{
    public:
        // Derived constructor executes after Base constructor completes
        Derived(){
            std::cout<<"Derived constructor\n";
        }

        // Derived destructor executes first before Base destructor
        ~Derived(){
            std::cout<<"Derived destructor\n";
        }
};

int main(){
    // Instantiating derived object: Order -> Base ctor, then Derived ctor.
    // Destruction at scope exit: Order -> Derived dtor, then Base dtor.
    Derived object;
    return 0;
}
