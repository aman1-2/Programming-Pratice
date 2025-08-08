/**
 * PROBLEM STATEMENT :- Given an Integer Array where every element occurs twice except two
occurs only one. Find those two Unique number.

In last problem we had one number which was occuring only once but in this we have two numbers
which occur only once. And we have been asked to find that unique element.
First of all we can see that this problem is quite similar to last problem and whenever we have 
such kind of similarities in the problem. Then try to think your problem which respect to that 
are you able to solve it with little modification or not.

So in the last problem we just took XOR of each element. But this time we have two unique element
so at the end we will have two xor values as our answer. But how we will extract the individual
element from the XOR result. One thing is confirm that we will not get 0. Because if we get 0 then
it means we have no unique element and if there is no 0 as result then it means we will have a non-zero
number and if we get a non-zero number then it means any of the bit will get set in short this is trying
to say in result we will have atleast one bit where we have the bits being different at least one set bit 
will be there.

So you take out any set bits position
*/

#include<iostream>
using namespace std;

void uniqueEles(int arr[], int n) {
    int res = 0;
    for(int i=0; i<n; i++) {
        res = res ^ arr[i];
    }

    //For the result of XOR you just need to hold any one bit which is a set bit
    int temp = res;
    int k = 0;
    while(true) {
        //No we have to check form the LSB the first set bit which we encounter. And if we
        //want to check if any bit is set or not then we can check it we can do add of that number with 1
        //Benefit of doing add with 1 is that we have just 1 set bit in Binary of 1 which is at the least significant Place .
        if((temp & 1) == 1) {
            break; //This means we have recieved one such bit where the bit is set. otherwise incerement k and in next iteration we will check next bit.
        }
        temp = temp >> 1;
        k++;
    }

    //Once we have found the kthe position where we have found the first set bit then we will loop back on the array and check the if
    //the given number arr[i] its kth bit is set or not and How can we check it and we can check it by right shifting that num (k)th times
    int retVal = 0;
    for(int i=0; i<n; i++) {
        int num = arr[i];
        if(((num >> k) & 1) == 1) retVal ^= num;
    }

    //Finally we will have one of the unique number in the retVal 
    cout<<retVal<<endl;

    //And then we will XOR the retVal with res which will give us our second unique element.
    cout<<(retVal^res);

    return;
}

int main() {
    int arr[] = {1,2,3,4,1,2,3,5};
    uniqueEles(arr, 8);

    return 0;
}