/**
 * PROBLEM STATEMENT :- Calculate the Minimum number of bit flips to convert from one number to another.

EXAMPLE : 5 can be written as 0101 and 
         11 can be written as 1011, so number of bit flips required will be 3.

If we observe this problem clearly then we need to flip only that bit which is opposite. So where the bits are same
we don't need to do anything there. We just need to find where the bits are opposite and adjust it there.
So we have to detect how many bits are there which are different those bits only we need to flip. 
We need to count different bits and here we can use the property of xor because what xor does is it gives 1 only when we have
different bits for same bits gives a value 0. And the xor resuult of those 2 number in result 1 will show the number of flis required and
0 shows no change.

In short in the problem if we find out xor of num1 and num2 and then cout the number of sets bit of result that will be our answer.
*/

#include<iostream>
using namespace std;

int minFlipReqToConvOneNumToAnother(int num1, int num2) {
    int result = (num1 ^ num2);
    return __builtin_popcount(result);
}

int main() {
    int num1 = 5, num2 = 11;
    cout<<minFlipReqToConvOneNumToAnother(num1, num2)<<endl;
    return 0;
}