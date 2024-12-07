/*
WAP to create a recursive function to print the power of a number.
*/

#include<iostream>
using namespace std;

int power(int num, int times){
    //Time-Complexity : O(n)
    return (times == 0)?(1):(num * power(num, times-1));
}

int optimize(int num, int times){
    //Time Complexity : O(log n)
    if(times == 0)  return 1;
    if(times%2 == 0){
        return power(num, times/2) * power(num, times/2); 
    } else{
        return num * power(num, times/2) * power(num, times/2); 
    }
}

int main(){
    cout<<optimize(2,0);
    return 0;
}