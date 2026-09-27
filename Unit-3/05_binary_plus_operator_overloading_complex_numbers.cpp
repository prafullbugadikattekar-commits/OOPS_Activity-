#include <iostream>

class Complex {
private:
    int real;
    int imaginary;

public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Overloading binary plus (+) operator
    // Parameter passed by const reference (&) to prevent copying
    // const member function: guarantees this object is not modified
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // const member function: outputs complex number representation
    void display() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + ";
        } else {
            std::cout << " - ";
        }
        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

int main() {
    Complex first(2, 3);
    Complex second(4, 5);

    // Operator calling: translates to first.operator+(second)
    Complex sum = first + second;

    std::cout << "First complex number: ";
    first.display();

    std::cout << "Second complex number: ";
    second.display();

    std::cout << "Sum: ";
    sum.display();

    return 0;
}
