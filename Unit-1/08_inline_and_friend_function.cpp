#include <iostream>

using namespace std;

class Test{
    private:
        int value;

    public:
        // Parameterized constructor definition
        Test(int v){
            value = v;

        }

        // inline function: hints compiler to replace call with code body to optimize performance
        inline int getValue(){
            return value;
        }

        // friend function declaration: permits non-member function to access private members
        friend void show(Test t);
};

// Friend function definition: accesses private member 'value' directly
void show(Test t){
    cout<<t.value;
}
int main(){
    Test t1(50);

    // Calling inline member function
    cout<<t1.getValue()<<endl;

    // Calling friend function, passing object by value
    show(t1);
    return 0;
}
