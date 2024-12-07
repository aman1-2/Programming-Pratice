/*WAF to print all the primes in range 2 to n?. */
#include<iostream>
using namespace std;

bool isPrime(int num){
    if(num==1)    return false;
    for(int i=2; i*i<=num; i++){
        if(num%i == 0)  return false;
    }

    return true;
}

void allPrimes(int num){
    for(int i=2; i<=num; i++){
        if(isPrime(i))  cout<<i<<" ";
    }
    return;
}

int main(){
    int num;
    cout<<"NUm = ";
    cin>>num;

    allPrimes(num);

    return 0;
}