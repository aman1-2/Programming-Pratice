/*
Question 1 : Write a recursive function to perform Binary Search.
Input : arr[ ] = {1, 2, 3, 4, 5, 6, 7}, n = 7, key = 5
Output : 4 (index of key)

*Use the starting index & ending index logic used in rotated, sorted array Qs.
*/

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> v, int start, int end, int target){
    if(start > end) return -1;

    int mid = start + (end - start)/2;
    if(v[mid] == target)    return mid;
    else if(v[mid] > target){
        return binarySearch(v, start, mid-1, target);
    } else{
        return binarySearch(v, mid+1, end, target);
    }
}

int main(){
    vector<int> v = {1,2,3,4,5};
    cout<<binarySearch(v, 0 , 4, 3);
    return 0;
}