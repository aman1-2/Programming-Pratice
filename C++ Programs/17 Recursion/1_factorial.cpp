#include<iostream>
using namespace std;

int factorial(int num){
    return (num==1)?(1):(num * factorial(num-1));
}

int main(){
    cout<<factorial(5);
    return 0;
}