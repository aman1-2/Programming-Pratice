/*WAP to calculate the maximum sum of the subarray?
Brute Force Approach*/
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {2,-3,6,-5,4,2}, largest = INT_MIN;

    for(int start=0; start<6; start++){
        for(int end=start; end<6; end++){
            int sum=0;
            for(int i=start; i<=end; i++){
                sum += arr[i];
            }
            if(sum>largest) largest=sum;
        }
    }

    cout<<"The maximum sum of the Subarray is: "<<largest;

    return 0;
}