#include <iostream>

class Distance {
private:
    int meters;

public:
    // explicit constructor avoids implicit integer conversion
    explicit Distance(int value) : meters(value) {}

    // Overloading relational greater-than (>) operator
    // Takes argument by const reference (&) and function is marked const
    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }

    // const member function: displays distance
    void display() const {
        std::cout << meters << " meters\n";
    }
};

int main() {
    Distance first(120);
    Distance second(90);

    std::cout << "First distance: ";
    first.display();

    std::cout << "Second distance: ";
    second.display();

    // Calling overloaded relational operator>: evaluates first.operator>(second)
    if (first > second) {
        std::cout << "First distance is greater\n";
    } else {
        std::cout << "Second distance is greater or equal\n";
    }

    return 0;
}
