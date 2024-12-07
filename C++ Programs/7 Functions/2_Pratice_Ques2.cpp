/*WAF to print if a number is even or odd? */
#include<iostream>
using namespace std;

void evenOdd(int num){
    if(num % 2 == 0)
        cout<<"Even";
    else
        cout<<"Odd";

    return;
}

int main(){
    int num;
    cout<<"Num = ";
    cin>>num;

    evenOdd(num);
    
    return 0;
}