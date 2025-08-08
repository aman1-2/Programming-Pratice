/**
 * PROBLEM STATEMENT :- Given an integer n, Find the maximum power of two that is smaller than n.

Probelm is saying that we will be given an integer n and we need to find the maximum power of 2 which is just smaller than n.

For Example -> We are given number as n = 24 then what is the power of 2 which is just smaller then 24.
So for this the answer will be 16
Lets take another value as n = 100, then just smaller value of power of 2 for 100 will be 64 (the biggest [max] power of 2 less than 100 is 64).

So if we are given a Binary lets say (1011010) which is 90 and we know 2 power in binary looks like 1 followed or not followed by number of zeroes.
And if we just have an idea of MSB set bit in that number then from that point till end all will bits will be 0 and that value will be the max power of 2 less then that number.
This is because in (1011010) we have some 1 in between which will give some power of 2 contribution but in (1000000) only startin one will contribute.

So case can be this only either the given number is itself in the power of 2 or if its not in 2 ki power then we can say if we make all the bits after the MSB bit of that number then it will be the max power of 2 less then number.

One way to solve this problem would be to do a complete binary conversion and do thing corresponding to that.
The other way could be lets say we have a binary as 1011010. Now the approach of set bit which we have explored where we saw how can we count the set bits.
So to count the set bit what we use to do is we use to find the and operation result of x and x-1 which use to remove one possible set bit from x and this it use to as in x and x-1 we have some part absolutely same and other part absolutely flipped off. And we use to repeat this problem till the time our number was greater than zero.
For max power less than number if we somehow store the value of x in the last iteration as after last iteration everything will become 0. So if somehow we store the last iteration value of x then whatever will be my last value of x that will just be my answer.
*/
#include<iostream>
using namespace std;

int max_2_Power(int num) {
    int ans = -1;

    while(num > 0) {
        ans = num;
        num = (num & num-1);
    }

    return ans;
}

//Approach-2 : We try to convert all the bits from the MSB bit till the end to 1 and at the 
//end the number we will get will power of some 2 - 1 and we just smaller so we can add + 1 
//to it and divide by 2 we will get one lesser power and thats only our answer
int max_power_2(int num) {
    num = num | num >> 1;
    num = num | num >> 2;
    num = num | num >> 4;
    num = num | num >> 8;
    num = num | num >> 16;

    return (num+1)>>1;

}

int main() {
    int num = 100; //64
    cout<<max_power_2(num)<<endl;

    int num1 = 24; //16
    cout<<max_power_2(num1)<<endl;

    int num2 = 90; //64
    cout<<max_power_2(num2)<<endl;

    return 0;
}