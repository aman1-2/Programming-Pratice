/*WAP to find the maximum sum of the sub-array using the Kadane's Algorithm.*/
#include<iostream>
#include<climits>
using namespace std;
int kadaneAlgorithm(int arr[], int size){
    int currSum = 0, maxSum = INT_MIN;
    for(int i=0; i<size; i++){
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum<0)   currSum = 0;
    }

    return maxSum;
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};

    cout<<"Maximum sum of the sub-array is: "<<kadaneAlgorithm(arr, 6);

    return 0;
}