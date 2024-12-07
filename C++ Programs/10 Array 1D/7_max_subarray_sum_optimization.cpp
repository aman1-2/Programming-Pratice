/*WAP to find the maximum sum from the subarray of an array.
Optimization on Brute force approach will be doing it on O(log n^2)*/
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {2,-3,6,-5,4,2}, largest = INT_MIN;

    for(int start=0; start<6; start++){
        int sum = 0;
        for(int end=start; end<6; end++){
            sum += arr[end];
        }
        largest = max(sum, largest);
    }

    cout<<"The Sum largest subarray is: "<<largest;
    
    return 0;
}