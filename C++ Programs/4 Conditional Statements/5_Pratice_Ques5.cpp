/*WAP to build a calculator using Switch for 4 basic arithmetic Operations(+,-,*,/)? */
#include<iostream>
using namespace std;
int main(){
    int num1, num2;
    cout<<"num1=";
    cin>>num1;
    cout<<"num2=";
    cin>>num2;
    char op;
    cout<<"Operator: ";
    cin>>op;

    switch(op){
        case '+':
            cout<<"Addition: "<<num1 + num2;
            break;
        case '-':
            cout<<"Subtraction: "<<num1 - num2;
            break;
        case '*':
            cout<<"Multiplication: "<<num1 * num2;
            break;
        case '/':
            cout<<"Division: "<<num1 / num2;
            break;
        default :
            cout<<"Invalid operator entered for operation.";
    }

    return 0;

}