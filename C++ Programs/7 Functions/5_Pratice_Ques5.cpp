/*WAF to find the binomial coefficient for given n and r?*/
#include<iostream>
using namespace std;

int factorial(int num){
    int fact=1;
    for(int i=1; i<=num; i++)
        fact *= i;

    return fact;
}

int main(){
    int choose, pick;
    cout<<"Enter the number of total chooses we have : ";
    cin>>choose;
    cout<<"Pick the number of items we can take from those choose : ";
    cin>>pick;

    //We can too make this calculation inside the function too.
    // binomial_coefficient = !(n)/!(r)*!(n-r)
    int binomial_coefficient = factorial(choose)/(factorial(pick)*(factorial(choose-pick)));

    cout<<"Number of total ways of choosing it is: "<<binomial_coefficient;

    return 0;
;}