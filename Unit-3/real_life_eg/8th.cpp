#include <iostream>

using namespace std;

// Real-world example: AC Electrical Circuit Analysis using Complex Impedance Numbers
class Complex{
    private:
        double real;
        double img;

    public:
        // Constructor with default parameters
        Complex(double r=0.0,double i=0.0)
            :real(r),img(i){}

        // Overloaded operator+: adds two complex impedances
        // Parameter passed by const reference (&) to avoid copies; member function marked const
        Complex operator+(const Complex& other) const{
            return Complex(real+other.real,img+other.img);
        }

        // Overloaded operator-: subtracts two complex numbers
        Complex operator-(const Complex& other) const{
            return Complex(real-other.real,img-other.img);
        }
        
        // Overloaded operator*: performs complex multiplication: (a+bi)*(c+di)
        Complex operator*(const Complex& other) const{
            return Complex(real * other.real-img*other.img,
            real* other.real+img*other.img
        );
        }

        // Overloaded equality operator (==): checks if both real and imaginary components match
        bool operator==(const Complex & other ) const{
            return real ==other.real && img == other.img;
        }

        // const member function: outputs complex number in a+bi format
        void display() const{
            cout<<real<<"+"<<img<<"i"<<endl;
        }

};

int main(){
    Complex c1(3.0,4.0);
    Complex c2(1.0,2.0);

    cout<<"C1 :";
    c1.display();
    cout<<"C2 :";
    c2.display();

    // Calling overloaded operator+ and chaining display()
    cout<<"SUM: ";
    (c1+c2).display();

    // Calling overloaded operator-
    cout<<"Difference: ";
    (c1-c2).display();

    // Calling overloaded operator*
    cout<<"Product: ";
    (c1*c2).display();
}
