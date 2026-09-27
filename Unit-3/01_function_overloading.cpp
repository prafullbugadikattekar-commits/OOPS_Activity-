#include <iostream>

// Function overloading: multiple functions with the same name but different parameter signatures
// Overload 1: accepts two integers
int add(int first,int second){
    return first + second;
}

// Overload 2: accepts two double precision floating-point numbers
double add(double first,double second){
    return first+second;
}

// Overload 3: accepts three integers (differentiated by parameter count)
int add(int first,int second,int third){
    return first+second+third;
}

int main(){
    // Function calling: compiler resolves the appropriate overload based on argument types and count
    std::cout<<"Sum of two integers: "<<add(10,20)<<'\n';
    std::cout<<"Sum of two doubles : "<<add(2.5,3.7)<<'\n';
    std::cout<<"Sum of three integers: "<<add(10,20,30)<<'\n';

    return 0;
}
