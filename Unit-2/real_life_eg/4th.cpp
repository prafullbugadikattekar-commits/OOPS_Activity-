#include <iostream>
#include <string>
using namespace std;

// Real-world example: Corporate Employee Compensation & Payroll System
// Abstract base class
class Employee{
    protected:
        int empId;
        string name;
        string department;
    public:
        // Parameterized constructor initializing protected base attributes
        Employee(int id,string n,string dept)
            :empId(id),name(n),department(dept){}

        // const member function: displays shared employee metadata
        void displayBasicInfo() const{
            cout<<"ID: "<<empId<<"|Name: "<<name<<"|Department "<<department;
        }

        // Pure virtual function (= 0): defines interface for salary computation
        virtual double calculateSalary() const =0 ;

        // Virtual destructor ensures proper cleanup of derived class objects
        virtual ~Employee()=default;
};

class FullTimeEmployee:public Employee{
    private:
        double monthlySalary;

    public:
        // Constructor forwards id, n, and dept to base class Employee
        FullTimeEmployee(int id,string n,string dept,double salary)
            :Employee(id,n,dept),monthlySalary(salary){}

        // override keyword: implements pure virtual calculateSalary() for full-time salary
        double calculateSalary() const override{
            return monthlySalary;
        }

        // const member function definition for displaying full-time details
        void display() const{
            displayBasicInfo(); // Calling inherited base member function
            cout<<"|Type:Full-Time |Salary:Rs"<<calculateSalary()<<endl;
        }
};

class PartTimeEmployee:public Employee{
    private:
        double hourlyRate;
        int hoursWorked;

    public:
        // Constructor initializes hourly wage and hours worked
        PartTimeEmployee(int id,string n,string dept,double rate,int hours)
            :Employee(id,n,dept),hourlyRate(rate),hoursWorked(hours){}

        // Overrides calculateSalary() to compute hourly compensation
        double calculateSalary() const override{
            return hourlyRate*hoursWorked;
        }

        void display() const{
            displayBasicInfo();
            cout<<"|Type:Part-Time |Salary:Rs"<<calculateSalary()<<endl;
        }
};

class Intern :public Employee{
    private:
        double stipened;

    public:
        // Constructor initializes intern stipend
        Intern(int id,string n,string dept,double stipen)
            :Employee(id,n,dept),stipened(stipen){}

        // Overrides calculateSalary() returning fixed stipend
        double calculateSalary() const override{
            return stipened;
        }

        void display() const{
            displayBasicInfo();
            cout<<"|Type:Intern |Salary:Rs"<<calculateSalary()<<endl;
        }
};

int main(){
    // Instantiating derived class objects with different compensation models
    FullTimeEmployee f1(101,"Amit","IT",100000);
    PartTimeEmployee p1(102,"Sneha","HR",250,120);
    Intern i1(103,"Rohan","Marketing",15000);

    cout<<"====Employee Payroll====="<<endl;
    // Calling display member functions on concrete employee objects
    f1.display();
    p1.display();
    i1.display();
}
