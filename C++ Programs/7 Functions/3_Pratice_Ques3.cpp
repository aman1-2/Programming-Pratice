/*WAF to print the factorial of a number n? */
#include<iostream>
using namespace std;

int factorial(int num){
    int fact=1;
    for(int i=1; i<=num; i++)
        fact *= i;
    
    return fact;
}

int main(){
    int num;
    cout<<"Num = ";
    cin>>num;

    cout<<"Factorial is : "<<factorial(num);
    
    return 0;
}