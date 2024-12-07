/* LEETCODE PROBLEM -> 42
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6
units of rain water (blue section) are being trapped.


Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5*/

//BRUTE-FORCE APPROACH

#include<iostream>
#include<climits>
using namespace std;

int trap(int height[], int size){
    int left_max_bar[size];
    int right_max_bar[size];

    //Calculating the maximum height bar present at the left most side for each bar.
    left_max_bar[0] = height[0];
    for(int i=1; i<size; i++){
        left_max_bar[i] = max(left_max_bar[i-1], height[i-1]);
    }

    //Calculating the maximum height bar present at the right most side for each bar.
    right_max_bar[size-1] = height[size-1];
    //Since placed the value at the last most element hence traversing the array from the second last position.
    for(int i=size-2; i>=0; i--){
        right_max_bar[i] = max(right_max_bar[i+1], height[i+1]);
    }

    int trap_water = 0;
    //Calculating the water getting traped for each bar.
    for(int i=0; i<size; i++){
        int curr_water = (min(left_max_bar[i], right_max_bar[i]) - height[i]);
        if(curr_water < 0)  curr_water = 0;
        trap_water += curr_water;
    }

    return trap_water;
    
}

int main(){
    int height[] ={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"The water getting trapped is: "<<trap(height, 12);
    return 0;
    
}