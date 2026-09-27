#include <iostream>
#include <string>

using namespace std;

// Real-world example: Student Attendance Tracking System
class Student{
    private:
        int rollNo;
        string name;
        int totalDays;
        int presentDays;
    public:
        // Parameterized constructor initializing attendance counters to zero
        Student(int r,string n)
            :rollNo(r),name(n),totalDays(0),presentDays(0){}

        // Member function definition to log attendance per lecture
        void markAttendance(bool isPresent){
            totalDays++;
            if (isPresent){
                presentDays++;
            }
        }

        // const member function: calculates attendance percentage without modifying object state
        double getAttendancePercentage() const{
            if (totalDays ==0){
                return 0;
            }
            return (presentDays*100)/totalDays;
        }
        
        // const member function definition for displaying student attendance
        void display() const
        {
            cout<<"Roll:"<<rollNo<<"|Name: "<<name<<"|Attendance: "<<getAttendancePercentage()<<"%"<<endl;
        }
};

int main()
{
    Student s1(101,"Rahul");
    Student s2(102,"Prafull");

    // Function calling to log attendance status
    s1.markAttendance(true);
    s1.markAttendance(true);
    s1.markAttendance(false);

    s2.markAttendance(true);
    s2.markAttendance(true);
    s2.markAttendance(true);

    cout<<"===Attendance Report==="<<endl;
    // Calling display member function
    s1.display();
    s2.display();
}
