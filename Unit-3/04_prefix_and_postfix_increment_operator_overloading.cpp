#include <iostream>

class Counter{
    private:
        int value;

    public:
        // explicit constructor with default parameter
        explicit Counter(int initialValue =0) : value(initialValue){}

    // Overloading prefix increment (++counter)
    // Returns reference (&) to current modified object (*this) for chaining
    Counter& operator++(){
        ++value;
        return *this;
    }

    // Overloading postfix increment (counter++)
    // Dummy 'int' parameter differentiates postfix from prefix
    // Returns previous state by value before incrementing
    Counter operator++(int){
        Counter old = *this; // Save current state
        ++value;             // Increment
        return old;          // Return old state
    }

    // const member function: displays current counter value
    void display() const{
        std::cout<<value<<'\n';
    }
};

int main(){
    Counter counter(5);

    std::cout<<"After prefix increment: ";
    // Calling prefix operator++: increments first, then displays
    ++counter;
    counter.display();

    std::cout<<"Value returned by postfix increment: ";
    // Calling postfix operator++: returns old value before incrementing
    Counter oldValue = counter++;
    oldValue.display();

    std::cout<<"Counter after postfix increment: ";
    counter.display();

    return 0;
}
