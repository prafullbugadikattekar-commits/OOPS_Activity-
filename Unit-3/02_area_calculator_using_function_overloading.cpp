#include<iostream>

// Overload 1: calculates area of a square (1 integer parameter)
int calculateArea(int side){
    return side*side;
}

// Overload 2: calculates area of a rectangle (2 integer parameters)
int calculateArea(int length,int width){
    return length *width;
}

// Overload 3: calculates area of a circle (1 double parameter)
double calculateArea(double radius){
    constexpr double PI = 3.141592653589793;
    return PI*radius*radius;
}

int main(){
    // Function calling: compiler determines function to execute based on arguments
    std::cout<<"Square Area: "<<calculateArea(5)<<'\n';
    std::cout<<"Rectangle Area: "<<calculateArea(6,4)<<'\n';
    std::cout<<"Circle Area: "<<calculateArea(2.0)<<'\n';

    return 0;
}
