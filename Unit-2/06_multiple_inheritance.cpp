#include<iostream>

// First independent base class
class Academic{
    protected:
        int academicMarks;

    public:
        // explicit keyword prevents implicit int conversions
        explicit Academic(int marks) : academicMarks(marks) {}

        // const member function: displays academic score
        void showAcademic() const{
            std::cout<<"Academic Marks:"<<academicMarks<<'\n';
        }
};

// Second independent base class
class Sports{
    protected:
        int sportsMarks;

    public:
        explicit Sports(int marks): sportsMarks(marks){}

        // const member function: displays sports score
        void showSports() const{
            std::cout<<"Sports Marks: "<<sportsMarks<<'\n';
        }
};

// Derived class demonstrating multiple inheritance: inherits both Academic and Sports
class Student: public Academic,public Sports{
    public:
        // Constructor initializes both base classes via member initializer list
        Student(int academic,int sports)
            :Academic(academic),Sports(sports){}

        // const member function computing aggregate marks from both base classes
        void showTotal() const{
            std::cout<<"Total Marks: "<<academicMarks+sportsMarks<<'\n';
        }
};

int main(){
    Student student(80,15);

    // Calling member functions inherited from Academic, Sports, and defined in Student
    student.showAcademic();
    student.showSports();
    student.showTotal();
    return 0;
}
