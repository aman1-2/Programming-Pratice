/*WAP to print the sum of odd digits from a number by using while loop.*/
#include<iostream>
using namespace std;
int main(){
    int num,sum=0;
    cout<<"num=";
    cin>>num;

    while(num>0){
        int last_digit = num % 10;
        if(last_digit % 2 != 0)
            sum += last_digit;
        num = num / 10;
    }

    cout<<"Sum = "<<sum;

    return 0;
}