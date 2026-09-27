#include <iostream>

class Base{
    public:
        // const member function: leaves object state unchanged
        void show() const{
            std::cout<<"Base public function \n";
        }
};

// Public inheritance: public members of Base remain public in PublicDerived
class PublicDerived: public Base{

};

// Private inheritance: public members of Base become private in PrivateDerived
class PrivateDerived: private Base{
public:
    // Wrapper function providing controlled access to private inherited Base::show()
    void callBaseShow() const{
        show(); // Accessible internally within member function
    }
};

int main(){
    PublicDerived publicObject;
    // Calling show(): valid because Base::show remains public through public inheritance
    publicObject.show();

    PrivateDerived privateobject;
    // Calling callBaseShow(): valid public method inside PrivateDerived
    privateobject.callBaseShow();
    // privateobject.show();  // Compilation Error: show() becomes private in PrivateDerived

    return 0;
}
