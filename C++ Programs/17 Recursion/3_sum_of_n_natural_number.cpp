/*
WAP to create a function which resurcively calculates the sum of n natural numbers.
*/

#include<iostream>
using namespace std;

int sumNaturalNo(int num){
    return (num == 1)?(1):(num + sumNaturalNo(num-1));
}

int main(){
    cout<<sumNaturalNo(3);
    return 0;
}