/*WAF to find the product of two numbers - a&b?*/
#include<iostream>
using namespace std;

int product(int num1, int num2){
    return (num1*num2);
}

int main(){
    int num1, num2;
    cout<<"Num1 = ";
    cin>>num1;
    cout<<"Num2 = ";
    cin>>num2;

    cout<<"Product = "<<product(num1, num2);

    return 0;
}