/*
Question 1 : Write a Function to clear the range of bits from i to j in a given number. (i 
& j are counted backwards from the right end of the number)

Examples :
Input : num = 15, i = 1, j = 3 
Output : 1

Explanation :
15 in binary form is => 00001111 [i=1st & j=3rd bit] 
After bits are cleared, number will become 00000001

Input : num = 31, i = 1, j = 3 
Output : 17

Note - Think about what type of bit mask is needed. It can also be a combination of 2 Numbers.
*/

#include<iostream>
using namespace std;

int clearBitRange(int num, int i, int j){
    int a = ~(0) << (j+1);
    int b = (1<<i) - 1;
    
    int bitmask = a | b; //This will make the range of value as zero.

    return (num & bitmask);
}

int main(){
    cout<<clearBitRange(31, 1, 3);

    return 0;
}