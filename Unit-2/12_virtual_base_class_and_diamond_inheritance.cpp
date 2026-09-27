#include <iostream>
#include <string>
#include <utility>

// Common ancestor class at the apex of the diamond hierarchy
class Person{
    protected:
        std::string name;

    public:
        // explicit constructor prevents implicit conversion from string
        explicit Person(std::string personName)
            :name(std::move(personName)) {}

        // const member function: displays name
        void displayName() const{
            std::cout<<"Name: "<<name<<'\n';
        }
};

// virtual inheritance: ensures only a single shared instance of Person is inherited
class Student : virtual public Person{
    public:
        Student():Person("Unknown"){}
};

// virtual inheritance: shares the same Person subobject with Student
class Employee : virtual public Person{
    public:
        Employee():Person("unkown"){}
};

// Bottom of the diamond: inherits both Student and Employee without duplicate Person copies
class TeachingAssistant : public Student ,public Employee{
    public:
        // When using virtual base classes, the most derived class directly calls the virtual base constructor
        explicit TeachingAssistant(std::string assistantName)
            :Person(std::move(assistantName)),Student(),Employee(){}
};

int main(){
    TeachingAssistant assistant("Riya");

    // Calling displayName() without ambiguity thanks to virtual inheritance
    assistant.displayName();

    return 0;
}
