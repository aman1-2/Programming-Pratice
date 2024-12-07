/*WAP to print the sum of digit using the while loop.*/
#include<iostream>
using namespace std;
int main(){
    int num,sum=0;
    cout<<"num=";
    cin>>num;

    while(num>0){
        int last_digit = num % 10;
        sum += last_digit;
        num = num / 10;
    }

    cout<<"Sum = "<<sum;

    return 0;
}