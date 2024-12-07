/*WAP to print the digits of a number in a reverse order.*/
#include<iostream>
using namespace std;
int main(){
    int num,temp=0;
    cout<<"num=";
    cin>>num;

    while(num>0){
        int last_digit = num % 10;
        temp = (temp*10) + last_digit;
        num /= 10;
    }

    cout<<"Reversed Number = "<<temp;

    return 0;
}