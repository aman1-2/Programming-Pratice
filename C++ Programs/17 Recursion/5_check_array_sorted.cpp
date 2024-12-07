/*
WAP to create a function which resurcively checks if the given array is sorted or not.
*/

#include<iostream>
using namespace std;

bool checkSorted(int arr[], int size){
    if(size == 1)   return true;
    if(arr[size] < arr[size-1]) return false;
    checkSorted(arr, size-1);
}

int main(){
    int arr[] = {5,4,3,2,1};
    cout<<checkSorted(arr, 5);
    return 0;
}