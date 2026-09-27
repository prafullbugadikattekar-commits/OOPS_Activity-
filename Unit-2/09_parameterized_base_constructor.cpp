#include <iostream>
#include <string>
#include <utility>

class person{
    protected:
        std::string name;

    public:
        // explicit keyword avoids implicit type conversions from std::string
        explicit person(std::string Name): name(std::move(Name)){}
};

class Student:public person{
    private:
        int rollNumber;

    public:
        // Parameterized constructor explicitly calling base class parameterized constructor
        Student(std::string StudentName,int roll)
            :person(std::move(StudentName)),rollNumber(roll){}

        // const member function: outputs student information
        void display() const{
            std::cout<<"Name: "<<name<<'\n';
            std::cout<<"Roll Number: "<<rollNumber<<'\n';
        }
};

int main(){
    Student student("Kiran",24);

    // Calling member function on derived class instance
    student.display();
    return 0;
}
