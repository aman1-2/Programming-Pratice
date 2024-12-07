/*Given an integer array nums, return true if any value appears at least twice in the
array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true


Example 2:
Input: nums = [1,2,3,4]
Output: false


Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:
1 <= nums.length <= 10^5
-109 <= nums[i] <= 10^9
*/

//BRUTE-FORCE APPROACH

#include<iostream>
using namespace std;

bool containsDuplicate(int nums[], int size){
    for(int i=0;i<size;i++){
        for(int j=i+1; j<size; j++){
            if(nums[i] == nums[j])   return true;
        }
    }

    return false;
}

int main(){
    int nums[] = {1,1,1,3,3,4,3,2,4,2};
    bool result = containsDuplicate(nums, 10);

    if(result)  cout<<"Duplicate Element Present.";
    else    cout<<"Duplicate Element not Present.";
    
    return 0;
}

//OPTIMIZE WAY BY SORTING THE ARRAY/VECTOR
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// bool containsDuplicate(vector<int>& nums){
//     sort(nums.begin(), nums.end());
    
//     for(int i=0; i<nums.size(); i++){
//         if(nums[i] == nums[i+1])    return true;
//     }

//     return false;
// }

// int main(){
//     vector<int> nums = {1,2,3,1};
//     bool result = containsDuplicate(nums);

//     if(result)  cout<<"Duplicate Element Present.";
//     else    cout<<"Duplicate Element not Present.";
    
//     return 0;
// }