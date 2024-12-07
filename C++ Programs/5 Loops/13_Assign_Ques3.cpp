/*Question 3 : WAP to input a number and check whether the number is an Armstrong
number or not.*/
#include<iostream>
using namespace std;
int main(){
    int num, sum=0, temp;
    cout<<"Num = ";
    cin>>num;

    temp = num;

    while(temp > 0){
        int last_digit = temp % 10;
        sum += (last_digit*last_digit*last_digit);
        temp /= 10;
    }

    if(sum == num){
        cout<<"It is an Armstrong Nummber.";
    } else{
        cout<<"It is not an Armstrong Number.";
    }

    return 0;
}