#include <iostream>
#include <string>
#include <utility>

// Base class representing a person
class person{
    protected:
        std::string name; // protected member: accessible within derived classes

    public:
        // explicit constructor: prevents implicit type conversions from std::string
        explicit person(std::string personName):name(std::move(personName)){}

        // const member function: guarantees no modification to member variables
        void displayName() const{
            std::cout<<"Name: "<<name<<'\n';
        }
};

// Derived class demonstrating single inheritance (publicly inherits from person)
class Student : public person{
    private:
        int rollNumber;

    public:
        // Constructor forwarding personName to base class constructor via member initializer list
        Student(std::string studentName,int roll)
            :person(std::move(studentName)),rollNumber(roll) {}

        // const member function displaying combined student details
        void displayStudent() const{
            displayName(); // Calling inherited base member function
            std::cout<<"Roll Number:"<<rollNumber<<'\n';
        }
};

int main(){
    // Object instantiation of derived class
    Student student("Amit",101);

    // Member function calling on derived object
    student.displayStudent();
    return 0;
}
