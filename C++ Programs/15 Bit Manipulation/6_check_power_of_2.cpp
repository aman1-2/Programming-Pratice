#include<iostream>
using namespace std;

bool isPowerOf2(int num){
    return !(num & num-1);
}

int main(){
    int num;
    cin>>num;

    cout<<isPowerOf2(num);

    return 0;
}