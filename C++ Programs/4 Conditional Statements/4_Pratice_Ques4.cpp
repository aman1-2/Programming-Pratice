/*WAP to print the largest among the three numbers.

We can too solve this QUestion with the Logical operator && to check two conditios at a single go.*/
#include<iostream>
using namespace std;
int main(){
    int num1, num2, num3;
    cout<<"num1=";
    cin>>num1;
    cout<<"num2=";
    cin>>num2;
    cout<<"num3=";
    cin>>num3;

    if(num1>num2){
        if(num3>num1){
            cout<<"num3 "<<num3<<" is the largest.";
        }
        else{
            cout<<"num1 "<<num1<<" is the largest.";
        }
    } else if(num2>num1){
        if(num3>num2){
            cout<<"num3 "<<num3<<" is the largest.";
        }
        else{
            cout<<"num2 "<<num2<<" is the largest.";
        }
    }

    return 0;
}