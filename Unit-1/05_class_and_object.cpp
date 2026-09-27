#include <iostream>
using namespace std;

// Class definition representing Student entity
class Student{
    public:
        string name;
        int age;

        // Member function definition to display student details
        void show(){
            cout<<name<<" "<<age<<"yrs old"<<endl;
        }
};

int main(){
    // Object instantiation
    Student s1;
    s1.name = "Amit";
    s1.age = 20;

    // Member function calling on object s1
    s1.show();
    return 0;
}
