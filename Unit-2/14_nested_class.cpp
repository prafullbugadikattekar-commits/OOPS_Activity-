#include <iostream>
#include <string>
#include <utility>

// Outer enclosing class
class University{
    public :
        // Nested inner class definition inside University's scope
        class Department{
            private:
                std::string name;

            public:
                // explicit constructor prevents implicit conversion from string
                explicit Department(std::string departmentname)
                 :name(std::move(departmentname)) {}

                // const member function: displays department name
                void display() const{
                    std::cout<<"Department: "<<name<<'\n';
                }
        };
};

int main(){
    // Instantiating nested class using outer class scope resolution (University::Department)
    University::Department department("Artificial Intelligence and Data Science");

    // Member function calling
    department.display();

    return 0;
}
