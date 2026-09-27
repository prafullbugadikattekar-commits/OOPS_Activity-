#include <iostream>
#include <string>
#include <utility>

// Level 1: Base class in multilevel hierarchy
class Person{
    protected:
        std::string name;

    public:
        // explicit constructor prevents implicit conversion from string
        explicit Person(std::string Name):name(std::move(Name)){}

        // const member function: displays person data
        void showPerson() const{
            std::cout<<"Name :"<<name<<'\n';
        }
};

// Level 2: Intermediate derived class inheriting Person
class Employee:public Person{
    protected:
        int employeeId;

    public:
        // Constructor forwards Name to Person and initializes employeeId
        Employee(std::string EmpName,int id)
            :Person(std::move(EmpName)),employeeId(id){}

        // const member function: displays employee ID
        void showEmployee() const{
            std::cout<<"Employee ID: "<<employeeId<<'\n';
        }
};

// Level 3: Most derived class inheriting Employee (Multilevel inheritance)
class Manager: public Employee{
    private:
        int teamSize;

    public:
        // Constructor forwards parameters to direct base Employee
        Manager(std::string managerName,int id,int size)
            :Employee(std::move(managerName),id),teamSize(size){}

        // const member function: invokes ancestor methods and displays manager details
        void showManager() const{
            showPerson();   // Method from Person
            showEmployee(); // Method from Employee
            std::cout<<"Team Size: "<<teamSize<<'\n';
        }
};

int main(){
    Manager manager("Ravi",501,8);

    // Calling member function on multilevel derived object
    manager.showManager();
    return 0;
}
