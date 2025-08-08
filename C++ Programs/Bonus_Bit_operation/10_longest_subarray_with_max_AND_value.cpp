/**
 * PROBLEM STATEMENT :- Given an integer array. Find the length of longest Subarray which has
maximum possible bitwise AND value.

This problem is asking us to find a subarray in which its maximum possible bitwise AND value exists.
Just assume that you are given an array like this [2,3,1,2,3,3,6,4] and now if you take out AND value
of any of the subarray(contiguous cross-section) then numbers will interfare with each other and ideally
if two numbers are interfaring each other and a AND operation is carried out between them. We have two numbers
x and y and out of these two numbers one will be greater and other smaller and we are calculating the AND 
operation of both (until and unless both are equal) then and we will always get a smaller value. In short 
trying to say that the result of x and y will always be smaller than x(if x is greater otherwise y).

And we have to take out that subarray whose bitwise AND is maximized and bitwise AND will be maximum when all
of the bits or numbers of the subarray is same. Which say x & x -> x other wise AND with any other number will
result in smaller.

So we have to just figure out this thing that our answer will come out from the bigger number itself. So we have
to find a subarray in which all the numbers are maximum.

At first just figure out the maximum element from the array and then just create a sliding window with i and j two
pointers pointing to the very first element of the arrayand just start the traversal see if at the jth position do we
have the maximum element if not in that case increment both i and j else at what so ever index we find our max element
from that just increment the j pointer at the end the value of j-i that will only be our answer that how much big subarray
we have in which the we have our max value.
*/

#include<iostream>
#include<climits>
using namespace std;

int maxANDValueSubArray(int arr[], int n) {
    int maxEle = INT_MIN;

    int ans = 0;
    int currCount = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] > maxEle)     maxEle = arr[i];
        if(arr[i] == maxEle)     currCount++;
        else {
            ans = max(ans, currCount);
            currCount = 0;
        }
    }

    return ans;
}

int main() {
    int arr[] = {12, 3, 1, 6, 1, 6, 6, 18, 6, 6, 4, 3, 8, 13, 13, 13, 13, 8};
    cout<<maxANDValueSubArray(arr, 18)<<endl;

    return 0;
}