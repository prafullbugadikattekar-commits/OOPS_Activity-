#include <iostream>

using namespace std;

// Base class with display() function
class Academic{
    public:
        void display() const{
            cout<<"Academic information \n";
        }
};

// Another base class with identical function signature display()
class Sports{
    public :
        void display() const{
            cout<<"Sports information\n";
        }
};

// Derived class inheriting from two base classes that both define display()
class Student :public Academic,public Sports{
    public:
        // Member function resolving ambiguity using class scope resolution operator (::)
        void displayAll() const{
            Academic::display(); // Explicitly calls Academic's display()
            Sports::display();   // Explicitly calls Sports' display()
        }
};

int main(){
    Student student;

    // Ambiguity resolution from caller site using object and scope resolution operator (::)
    student.Academic::display();
    student.Sports::display();

    // Calling convenience member function that resolves ambiguity internally
    student.displayAll();
}
