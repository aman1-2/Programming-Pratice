/*Write a C++ program to get a number from the user and print whether 
it's positive, negative or zero.*/
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"num=";
    cin>>num;

    if(num > 0){
        cout<<"Positive";
    } else if(num < 0){
        cout<<"Negative";
    } else{
        cout<<"Zero";
    }

    return 0;
}