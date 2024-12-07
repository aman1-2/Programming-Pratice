/*
LEETCODE -> PPROBLEM NUMBER 136

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

 
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
 

Constraints:
-> 1 <= nums.length <= 3 * 104
-> -3 * 104 <= nums[i] <= 3 * 104
-> Each element in the array appears twice except for one element which appears only once.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int singleNumber(vector<int>& nums){
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
        if((nums[i] ^ nums[i+1])) return nums[i];
        else    i++;
    }

    return -1;
}

// Optimized version is
int optimize(vector<int>& nums){
    int answer = 0; //Initialized answer with zero.

    for(int i=0; i<nums.size(); i++){
        answer ^= nums[i]; //XOR with a number gives back the same number in the answer.
        //Whereas XOR with the same number always gives 0.
    }

    return answer;
}

int main(){
    vector<int> nums = {1};
    int ans = singleNumber(nums);
    cout<<ans<<endl;

    // cout<<(2^2);

    return 0;
}