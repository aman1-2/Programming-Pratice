#include<iostream>
using namespace std;

void bubbleSort(int nums[], int size){
    for(int i=0; i<(size-1); i++){
        for(int j=0; j<(size-1)-i; j++){
            if(nums[j]>nums[j+1])   swap(nums[j],nums[j+1]);
        }
    }

    return;
}

void optimizedBubbleSort(int nums[], int size){
    //This is to provide an optimization that if the array is alreadt sorted or we haven't done as such swapping in the
    //array in that case we use this check method.
    for(int i=0; i<(size-1); i++){
        bool flag = false;
        for(int j=0; j<(size-1)-i; j++){
            if(nums[j] > nums[j+1]){
                flag = true;
                swap(nums[j], nums[j+1]);
            }
        }
        if(!flag) break; //If no swap was there then just break the loop as we have recieved our sorted array.
    }

    //Time complexity is O(1,1) where our first outer loop runs one time and the inner loop is too running just one complete iteration for the outer loop.

    return;
}

void output(int nums[], int size){
    for(int i=0; i<size; i++){
        cout<<nums[i]<<", ";
    }
    cout<<endl;
    return;
}

int main(){
    int nums[] = {3,5,4,1,2};
    cout<<"Array before sorting:-"<<endl;
    output(nums, 5);
    optimizedBubbleSort(nums,5);
    cout<<"Array after sorting:-"<<endl;
    output(nums, 5);

    return 0;
}