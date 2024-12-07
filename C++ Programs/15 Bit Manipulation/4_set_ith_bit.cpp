#include<iostream>
using namespace std;

int setIthBit(int num, int ith_bit){
    int form_bitmask = 1<<ith_bit;

    return (num | form_bitmask);
}

int main(){

    cout<<setIthBit(6,3)<<endl;

    return 0;
}