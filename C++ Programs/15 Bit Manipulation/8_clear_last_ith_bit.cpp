#include<iostream>
using namespace std;

int clearLastIthBits(int num, int ith_bit){
    int bitmask = ( (~0) << ith_bit );
    num = (num & (bitmask));
    return num;
}

int main(){
    cout<<clearLastIthBits(15, 2);
    
    return 0;
}