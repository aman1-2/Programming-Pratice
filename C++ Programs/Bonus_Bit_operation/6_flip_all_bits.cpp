/**
 * PROBLEM STATEMENT :- Given an integer n, flip all its bits i.e. if the given bit is 1,
change it to 0 and vice-versa.

We can bit of use last approach in this as well we were converting all the bits to 1 here too after converting
all the bits to 1 we can find the xor between the original number and all bits 1. Which will eventually flip all the numbers
because same bit value in xor gives 0 and different gives 1.
*/

#include<iostream>
using namespace std;

int flip_all_bits(int num) {
    int temp = num;

    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);
    num = num | (num >> 16);

    return (temp ^ num);
}

//Approach-2
int flipAllBits(int num) {
    int ans = 0, temp = num;

    while(num > 0) {
        ans = num;
        num = (num & num-1);
    }

    return ((ans<<1)-1) ^ temp; //What we are doing is finding just smaller power of 2 then 
    //number then multiplying 2 in it and making power of 2 just greater then number 
    //subtracting by 1 this value will be all 1 and then at the end finding a xor with the 
    //original number.
}

int main() {
    int num = 23;
    cout<<flipAllBits(num);
    return 0;
}