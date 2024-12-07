/*
Question 4 : Write a function that prints the largest of 3 numbers.
*/
#include<iostream>
using namespace std;

void largest(int num1, int num2, int num3){
    if(num1>num2 && num1>num3)  cout<<num1<<" is the largest number.";
    else if(num2>1 && num2>num3)    cout<<num2<<" is the largest number.";
    else    cout<<num3<<" is the largest number.";
    return;
}

int main(){
    int num1, num2, num3;
    cout<<"Num1 = ";
    cin>>num1;
    cout<<"Num2 = ";
    cin>>num2;
    cout<<"Num3 = ";
    cin>>num3;

    largest(num1, num2, num3);

    return 0;
}