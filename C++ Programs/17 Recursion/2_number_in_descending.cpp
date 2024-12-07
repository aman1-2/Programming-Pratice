/*
WAP to create a recursion function for printing the number in descending order from n to 1.*/

#include<iostream>
using namespace std;

void printDescOrder(int num){
    if(num == 0)    return; //Base-case
    cout<<num<<" "; //Self-work
    printDescOrder(num-1); //Assumption
}

int main(){
    printDescOrder(100);
    return 0;
}