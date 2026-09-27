#include <iostream>

class Complex {
private:
    int real;
    int imaginary;

public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Non-member friend operator+ declaration: permits commutative operations where primitive is on left (e.g. 10 + complex)
    // Passes object by const reference (&) to avoid copies
    friend Complex operator+(int value, const Complex& number);

    // const member function: formats and displays complex number
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

// Friend operator+ definition: has access to private members 'real' and 'imaginary'
Complex operator+(int value, const Complex& number) {
    return Complex(value + number.real, number.imaginary);
}

int main() {
    Complex complex(2, 3);

    // Calling friend non-member operator+: compiler invokes operator+(10, complex)
    Complex result = 10 + complex;

    std::cout << "Result: ";
    result.display();

    return 0;
}
