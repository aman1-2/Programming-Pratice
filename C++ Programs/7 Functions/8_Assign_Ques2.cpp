/*
Question 2 : Write a function to calculate the sum of digits of a number.
*/
#include<iostream>
using namespace std;

int digitSum(int num){
    int sum = 0;

    while(num > 0){
        int last_digit = num % 10;
        sum += last_digit;
        num /= 10;
    }

    return sum;
}

int main(){
    int num;
    cout<<"Num = ";
    cin>>num;

    cout<<"Sum of digits is : "<<digitSum(num);

    return 0;
}