/*Question 5 : For a positive N , WAP that prints the first N Fibonacci numbers.
(Assume N >= 2)*/
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Num = ";
    cin>>num;

    int first = 0, second = 1;
    
    cout<<"Fibonacci Series : "<<first<<" "<<second<<" ";
    for(int i=2; i<num; i++){
        int third = first + second;
        cout<<third<<" ";
        first = second;
        second = third;
    }

    return 0;
}