#include<iostream>
using namespace std;

void selectionSort(int nums[], int size){
    for(int i=0; i<size-1; i++){
        int minIdx = i;
        for(int j=i+1; j<size; j++){
            if(nums[minIdx]>nums[j])    minIdx = j;
        }

        if(minIdx != i) swap(nums[minIdx], nums[i]);
    }

    return;

    //It has a time complexity of O(n^2).
}

void print(int nums[], int size){
    for(int i=0; i<size; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return;
}

int main(){
    int nums[] = {3,5,4,1,2};
    selectionSort(nums, 5);
    print(nums, 5);

    return 0;
}