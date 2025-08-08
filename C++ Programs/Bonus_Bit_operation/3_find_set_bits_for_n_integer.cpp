/**
 * PROBLEM STATEMENT :- Find the number of set bits for any integer n.

 What is set Bits ?
 -> Lets say there is any integer 5 and its binary is 00000101 (in 8 bit form). So set bit
 are those bit positions where we have one's. And where so ever we have 0's they are called as
 offset bits or unset bits.

 In simple word we need to tell how many 1's are there in any numbers binary representation.
*/

#include<iostream>
using namespace std;

//Approach-1 using the stl __builtin_popcount() function.
int countOfSetBits(int num) {
    return __builtin_popcount(num); //A stl function used of counting the number of set bits in the any integer within the c++.
}
//Brain Kerniglen's Algorithm
//Approac-2 Self building Logic.
/* We have a very small observation of Binary Numbers to solve this problem.
Lets observe one pattern by taking the pairs of (x and x-1)
Like 13 and 12 -> 1101 and 1100 [Here we will observe that one part is absolutely same other part is absolutely fliped]
Like 10 and 9 -> 1010 and 1001
Like 6 and 5 -> 100 and 101 [Here one part is absolutely same and other is flipped off].
Like 16 and 15 -> 10000 and 01111 [One part i.e. 1 is exactly same and rest are just flipped off].

This logic is applicable only on the pairs of (x and x-1) where in the x we see the last set bit position from the last set
bit position till the end we have bits flipped in x-1.

By using this logic if you give me a number then i can write its number-1 by just flipping the bits from the last set bit position.

Now you will be like this observation is good but how is this benefiting in our problem.

As we have observed that in x and x-1 we have some part absolutely same and other art just flipped.
So if we just use a and operator between x and x-1 then the bits smiliar will give that bit only and different bits will form 0 itself.
0 & 0 -> 0      1 & 1 -> 1      0 & 1 -> 0      1 & 0 -> 0
what this will give us that the same region we will get as it is and the flipped region will get exactly removed. Means the flipped bits will have 0 as result in the and operation.
And if we closely observe then while doing and operation from the flipped region we have removed on set bit from our number by doing and operation on x and x-1 it removes one of the set bit from the flipped region.

So lets say we are given a number 22 and we need to find number of set bits of it.
We will do 22 & 21 => 10110 & 10101 => 10100 (20 ka binary). By doing AND operation removing one set bit from 22.
Now just repeat the same process with 20 and 19 => 10100 & 10011 => 10000 (16 ka binary) In second go we removed the second set from 22.
Now lets just do 16 & 15 => 10000 & 1111 => 00000 (0 ka binary). And in this way in the last go the last set bit of 22 is too removed.
So the situation is if you want to count your set bits. One of the way would be create your binary number and after creating the Binary number and then count the number of 1's in that binary string. This is too a good
approach but the problem we could face in this if your system is of 32-bits or 64-bits in that case our string will too be of 32 or 64 characters long. In that scenarion the number of creation of 32 bits iteration will be just 32 or 64.

And in the second approach what we are doing is we are finding the and of x and x-1 and in each iteration we are removing one set bit from our x. In that case we will need just set bit count iteration to remove set bits from the number x. We run our iteration till the time give number x doesn't becomes .
So in this approach the number of iteration we are giving is equal to the number of set bits we have in that number. And this approach is known as Brain Kerniglen's Algorithm.
*/

int numberOfSetBits(int num) { //Time-Comlexity -> O(number of set bits in a given number)
    int count = 0;

    while(num > 0) {
        count++;
        num = (num & num-1);
    }

    return count;
}

int main() {
    int num = 4; //100
    cout<<numberOfSetBits(num)<<endl;

    int num1 = 7; //111
    cout<<numberOfSetBits(num1)<<endl;

    int num2 = 18; //10010
    cout<<numberOfSetBits(num2)<<endl;

    return 0;
}