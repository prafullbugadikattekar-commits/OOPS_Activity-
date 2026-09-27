#include <iostream>

class Number{
    private:
        int value;

    public:
        // explicit constructor: prevents implicit conversion from int to Number
        explicit Number(int givenValue): value(givenValue){}

        // Overloading unary minus (-) operator
        // const member function: returns a new negated Number without modifying the original
        Number operator-() const{
            return Number(-value);
        }

        // const member function to display value
        void display() const{
            std::cout<<value<<"\n";
        }
};

int main(){
    Number first(25);

    // Operator calling: invokes overloaded operator-() on 'first'
    Number second = -first;

    std::cout<<"Original value: ";
    first.display();

    std::cout<<"Negated value: ";
    second.display();

    return 0;
}
