#include<iostream>
using namespace std;

// Function prototype/declaration
int add(int,int);

int main(){
    int a = 10;
    int b = 20;

    // Function calling: passes 'a' and 'b' by value
    cout<<"Sum = "<<add(a,b)<<endl;
    return 0;
}

// Function definition: accepts two integers and returns their sum
int add(int x,int y){
    return x+y;
}
