#include <iostream>
#include <string>
#include <utility>

// Abstract base class representing general employee
class Employee {
protected:
    int employeeId;
    std::string name;

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function (= 0): must be implemented by derived classes
    virtual double calculateSalary() const = 0;

    // const member function: displays common employee details
    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor enables safe deletion of derived instances via base pointer
    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;

public:
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}

    // Overrides pure virtual function to calculate permanent employee compensation
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

    // Overrides pure virtual function to calculate hourly wages
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Polymorphic standalone function accepting base reference (&)
// Const reference avoids object copying and slicing while enabling dynamic dispatch
void displayPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    // Dynamic binding: calls correct overridden calculateSalary() at runtime
    std::cout << "Salary: " << employee.calculateSalary() << "\n\n";
}

int main() {
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

    // Function calling passing derived objects polymorphically by reference (&)
    displayPaySlip(permanentEmployee);
    displayPaySlip(contractEmployee);

    return 0;
}
