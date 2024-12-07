/**
 * Largest subarray sum with zero
 */
#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

int largestSumSubarray(vector<int> &nums) { //T.C - O(n)
    //STEP 1: Created an unordered map for storing the pairs <sum, index> position for the elements.
    unordered_map<int, int> um;
    int length = 0; //Initalized a length variable for calculating the max length of the sub-array with elements having sum as 0.
    int sum = 0; //Initialized sum as 0.

    //STEP 2: Runned a for loop from 0 to nums.size(). where we are performing few steps as
    for(int i=0; i<nums.size(); i++) { 
        sum += nums[i]; //Calculating the sum of elements from 0 till the ith index position.

        if(um.count(sum)){ //Now making a check if the sum is in the map.
            length = max(length, (i - um[sum])); //Checking if the current sub-array length is more then update it
        } else{ //If the sum doesn't exists in map
            um[sum] = i; //Then add that sum in the map.
        }
    }

    return length; //At the returning the length which is storing the max sub-array length.
}

int main() {
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10};
    int res = largestSumSubarray(nums);
    cout<<res;
    return 0;
}