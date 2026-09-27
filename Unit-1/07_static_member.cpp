#include <iostream>
using namespace std;

class Student{
    public:
        // static data member: shared across all instances of the class
        static int count;

        // Constructor increments static counter each time a new object is created
        Student(){
            count++;
        }
};

// Static member definition and initialization outside the class
int Student :: count= 0;
int main(){
    Student s1,s2;

    // Accessing static member using class name and scope resolution operator (::)
    cout<<Student::count;

}
