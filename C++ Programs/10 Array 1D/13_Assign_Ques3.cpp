/*Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.*/

#include<iostream>
#include<climits>
using namespace std;

int maximumProduct(int nums[], int size){ //It will calculate the Maximum Product in O(n^3) Same logic as of calculating the sum of the subarray.
    int max_product = nums[0];
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            int product = 1;
            for(int k=i; k<=j; k++){
                product *= nums[k]; 
            }
            max_product = max(max_product, product);
        }
    }

    return max_product;
}

int optimization(int nums[], int size){ //Here we are doing the same work in O(n^2) time.
    int max_product = nums[0];

    for(int i=0; i<size; i++){
        int product = 1;
        for(int j=i; j<size; j++){
            product *= nums[j];
            max_product = max(max_product, product);
        }
    }

    return max_product;
}

int kadanesMethod(int nums[], int size){ //Here it is much faster as we are calculating maximum product in O(n) time.
    int maxTillNow = nums[0]; 
    int minTillNow = nums[0]; 
    int ans = maxTillNow;

    for(int i=1; i<size; i++){ 
        int curr = nums[i];
        int tempMaxTillNow = max(curr, max(maxTillNow*curr, minTillNow*curr));
        minTillNow = min(curr, min(maxTillNow*curr, minTillNow*curr)); 
        maxTillNow = tempMaxTillNow;
        ans = max(maxTillNow, ans);
    }

    return ans;
}

int main(){

    int nums[] = {2,-5,-2,-4,3};
    cout<<"Maximum Product is: "<<kadanesMethod(nums, 5);

    return 0;
}