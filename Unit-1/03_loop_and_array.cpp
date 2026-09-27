#include<iostream>
using namespace std;

// Demonstrates one-dimensional array traversal with for loop
int main(){
    int marks[5] = {1,20,2,33,40};

    // Loop iteration through array indices from 0 to 4
    for(int i = 0;i<=4;i++)
    {
        cout<<marks[i]<<" ";
    }
}
