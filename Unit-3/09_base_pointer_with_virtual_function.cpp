#include <iostream>

// Demonstrates late (dynamic / runtime) binding using the virtual keyword
class Animal {
public:
    // virtual keyword: enables dynamic dispatch via vtable at runtime
    virtual void sound() const {
        std::cout << "Animal makes a sound\n";
    }

    // virtual destructor: ensures derived destructors are called through base pointers
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    // override keyword: explicitly overrides base class virtual function
    void sound() const override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    // override keyword: overrides base sound for Cat
    void sound() const override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    Dog dog;
    Cat cat;

    // Base pointer pointing to Dog object
    Animal* animal = &dog;
    // Runtime polymorphism: dynamically calls Dog::sound()
    animal->sound();

    // Reassigning base pointer to Cat object
    animal = &cat;
    // Runtime polymorphism: dynamically calls Cat::sound()
    animal->sound();

    return 0;
}
