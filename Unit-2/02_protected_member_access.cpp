#include<iostream>
#include<string>
#include<utility>

// Base class showcasing protected access specifier
class Employee{
    protected:
        std::string name; // protected member: accessible by derived classes, but private to external code

    public:
        // explicit keyword prevents implicit conversion from std::string to Employee
        explicit Employee(std::string employeeName):name(std::move(employeeName)){}
};

// Derived class publicly inheriting Employee
class Developer: public Employee{
    private:
        std::string language;

    public:
        // Parameterized constructor invoking base class constructor
        Developer(std::string employeeName,std::string programmingLanguauge)
            :Employee(std::move(employeeName)),language(std::move(programmingLanguauge)){}

        // const member function accessing inherited protected member 'name' directly
        void display() const{
            std::cout<<"Developer: "<<name<<'\n';
            std::cout<<"Language: "<<language<<'\n';
        }
};

int main(){
    Developer developer("Neha","C++");

    // Function calling on derived class object
    developer.display();
    return 0;
}
