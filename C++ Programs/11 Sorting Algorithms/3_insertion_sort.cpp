#include<iostream>
using namespace std;

void insertionSort(int nums[], int size){
    for(int i=1; i<size; i++){
        int curr_ele = nums[i];
        int previous_idx = i-1;
        //Backward loop for checking in the sorted position
        while(previous_idx >= 0 && nums[previous_idx]>curr_ele){
            swap(nums[previous_idx], nums[previous_idx+1]);
            previous_idx--;
        }
        nums[previous_idx+1] = curr_ele; //At the end loop will end one position before the correct position that's why previous_idx + 1 done.
    }

    //Time complexity of the Insertion sort is O(n^2) as we are running the loop only once.

    return;
}

void print(int nums[], int size){
    for(int i=0; i<size; i++){
        cout<<nums[i]<<" ";
    }

    return;
}

int main(){
    int nums[] = {3,5,4,1,2};
    insertionSort(nums, 5);
    print(nums, 5);

    return 0;
}