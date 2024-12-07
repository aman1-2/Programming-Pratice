/*WAF to print if the given number is prime or not? */
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num){
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int num;
    cout<<"Num = ";
    cin>>num;

    bool flag=isPrime(num);

    if(flag)    cout<<"Is Prime";
    else    cout<<"Not a Prime";

    return 0;
}