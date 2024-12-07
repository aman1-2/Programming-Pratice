/*
Question 3 : Write a function which takes 2 numbers as parameters (a & b) and 
outputs : a^2 + b^2 + 2*ab.
*/
#include<iostream>
using namespace std;

void function(int a, int b){
    cout<<a*a<<"+"<<b*b<<"+"<<2*a*b;
    return;   
}

int main(){
    int a,b;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;

    function(a, b);

    return 0;
}