#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int KSubarraySumCount(vector<int> &nums, int target) {
    //STEP 1: Create an unordered map to store the pair of <sum, count>
    unordered_map<int, int> mp;
    mp[0] = 1; //STEP 2: We need to store the pair of <0, 1> where for the sum = 0 there always exists 1 count lets say if we don't take any element of the array in that case its sum will be 0
    //This pair is added for the case where we have only 1 element in the array and the target sum is equal to that one array element itself.

    //STEP 3: Initialized the variable count and sum with 0 sum for storing the sum of the elements and count for storing the count of the sub-array whose sum are equal to k. 
    int sum = 0;
    int count = 0;

    //STEP 4: Looping on the vector.
    for(int i=0; i<nums.size(); i++) {
        //While looping calculating the sum of the elements till that index position.
        sum += nums[i];
        //STEP 5: Checking if there exists sum value (sum-target) in map or not if yes then update the count variable.
        if(mp.count(sum - target)) {
            count += mp[sum - target];
        } //If doesn't exists then don't need to do anything. 

        //STEP 6: Checking if the sum is present in map or not for future reference
        if(mp.count(sum)) { //Lets say the sum value exists in the map in the case increase the count of that sum value.
            mp[sum]++;
        } else { //If that sum doesn't exists then the add it in the map.
            mp[sum] = 1;
        }
    }

    return count; //Return the count at the end.
}

int main() {
    vector<int> nums = {10, 2, -2, -20, 10};
    int target = -10;
    int res = KSubarraySumCount(nums, target);
    cout<<res;
    return 0;
}