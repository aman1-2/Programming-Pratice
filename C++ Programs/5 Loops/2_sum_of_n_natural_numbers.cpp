/*WAP to calculate the sum of n natural numbers.*/
#include<iostream>
using namespace std;
int main(){
    int num, sum=0;
    cout<<"num=";
    cin>>num;

    // for(int i=1; i<=num; i++){
    //     sum += i;
    // }

    sum = num*(num+1)/2;

    cout<<"Sum="<<sum;

    return 0;
}