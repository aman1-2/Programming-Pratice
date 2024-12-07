#include<iostream>
using namespace std;

int clearIthBit(int num, int ith_bit){
    int form_bitmask = ~(1<<ith_bit); //Here we have not because we want just the opposite at the ith position 0 must be present and rest must be 1.
    //And (1<<ith_bit) will return us 1 at the ith position and rest would be 0.

    return (num & form_bitmask);
}

int main(){
    cout<<clearIthBit(6,1);
    return 0;
}