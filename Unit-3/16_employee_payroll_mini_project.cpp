#include <iostream>
#include <string>
#include <utility>

// Abstract base class representing generic employee
class Employee {
protected:
    int employeeId;
    std::string name;

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function (= 0): must be implemented by concrete subclasses
    virtual double calculateSalary() const = 0;

    // const member function: displays common employee details
    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor ensures proper polymorphic destruction
    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;

public:
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}

    // override keyword: computes monthly salary with allowances
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

    // override keyword: computes wages based on hourly rate
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Polymorphic utility function taking Employee by const reference (&)
// Prevents copying and enables dynamic dispatch of calculateSalary()
void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    // Dynamic binding: calls correct overridden calculateSalary() at runtime
    std::cout << "Salary: Rs. " << employee.calculateSalary() << "\n\n";
}

int main() {
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

    // Calling polymorphic function with derived objects
    printPaySlip(permanentEmployee);
    printPaySlip(contractEmployee);

    return 0;
}
