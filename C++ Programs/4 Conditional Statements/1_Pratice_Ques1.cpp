/*WAP to print the largest of 2 numbers??*/
#include<iostream>
using namespace std;
int main(){
    int num1, num2;
    cout<<"num1=";
    cin>>num1;
    cout<<"num2=";
    cin>>num2;

    if(num1>num2){
        cout<<"num1 "<<num1<<" is the largest."; 
    } else{
        cout<<"num2 "<<num2<<" is the largest.";
    }

    return 0;
}