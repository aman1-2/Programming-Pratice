/*
WAF to update the ith bit in a number according to given value(0 or 1).
num = 7, i = 2, val = 0
num = 7, i = 3, val = 1
*/

#include<iostream>
using namespace std;

int clearIthBit(int num, int ith_bit){
    int bitmask = ~(1<<ith_bit);
    return (num & bitmask);
}

int updateIthBit(int num,int ith_bit, int value){
    int res = clearIthBit(num, ith_bit);
    return (res | (value<<ith_bit));
}

int main(){
    cout<<updateIthBit(7, 2, 0);
    return 0;
}