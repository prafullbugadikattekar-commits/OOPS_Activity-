#include <iostream>

using namespace std;

class Demo{
    public:
        // Default constructor: invoked automatically upon object creation
        Demo(){
            cout<<"Constructor called"<<endl;
        }

        // Destructor: invoked automatically when object goes out of scope
        ~Demo(){
            cout<<"Destructor called";
        }
};

int main(){
    // Object creation triggers constructor; destructor executes when 'd' goes out of scope
    Demo d;
    return 0;
}
