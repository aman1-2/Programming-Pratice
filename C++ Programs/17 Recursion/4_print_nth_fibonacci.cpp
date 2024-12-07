/*
WAP to create a recursive function to find the nth fibonacci number.
*/

#include<iostream>
using namespace std;
//Fibonacci Series
// 0 1 2 3 4 5 6 7 8
// 0 1 1 2 3 5 8 13 21

int nthFibonacci(int num){
    if(num == 0 || num == 1)    return num; //Base case
    //Addition is self-work
    return nthFibonacci(num-1) + nthFibonacci(num-2); //calling function is assumption
}

int main(){
    cout<<nthFibonacci(8);
    return 0;
}