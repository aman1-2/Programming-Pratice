#include<iostream>
using namespace std;

void countingSort(int nums[], int size){
    //Finding the max_ele - Because the size of the frequency array depends on the size of the maximum element. Thisis for finding the range.
    int max_ele = nums[0];
    for(int i=1; i<size; i++)   if(max_ele<nums[i]) max_ele = nums[i];

    int freq[max_ele+1] ;
    //Storing zero in the frequency array.
    for(int i=0; i<max_ele+1; i++){
        freq[i] = 0;
    }
    //Updating the count of each element in the frequency array.
    for(int i=0; i<size; i++){
        freq[nums[i]]++;
    }

    //Now updating the original array accordingly untill the count of an index is not zero in the freq array.
    int j = 0;
    for(int i=0; i<max_ele+1; i++){
        while(freq[i]>0){
            nums[j++] = i;
            freq[i]--;
        }
    }

    //Time Complexity for this is O(n+range) which is sometime O(n+n) ~ O(n) only.
    //Space Complexity is O(max_ele+1) - Because created a frequency array of the max_ele+1 size.

    return;
}

void countingSortMethod2(int nums[], int size){
    //Finding the max_ele - Because the size of the frequency array depends on the size of the maximum element. Thisis for finding the range.
    int max_ele = nums[0];
    for(int i=1; i<size; i++)   max_ele = max(max_ele, nums[i]);

    int freq[max_ele+1] = {0}; //Storing zero in the frequency array.
    //Updating the count of each element in the frequency array.
    for(int i=0; i<size; i++){
        freq[nums[i]]++;
    }

    //Calculating the cumulative or can say prefix sum for the frequency array. We could have stored it in any other cumulative frequency array too.
    for(int i=1; i<max_ele+1; i++){
        freq[i] = freq[i-1] + freq[i];
    }

    //Now we have to place the element at its correct position since we need to traverse the orginal array for updating the position therefore we cann't update the orginal array at its own place.
    int ans[size]; //Creates an extra ans array
    for(int i=size-1; i>=0; i--){
        ans[--freq[nums[i]]] = nums[i]; //Placing the element at correct position in the ans array.
    }

    //At last just copied the ans array as the nums array.
    for(int i=0; i<size; i++)   nums[i] = ans[i]; 

    //Time Complexity for this is O(n+range) which is sometime O(n+n) ~ O(n) only.
    //Space Complexity is O(max_ele+1) - Because created a frequency array of the max_ele+1 size.
    //And one ans array of size - n (i.e number of elements in the array).

    return;
}

void print(int nums[], int size){
    for(int i=0; i<size; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return;
}

int main(){
    int nums[] = {1,4,1,3,2,4,3,7};
    countingSortMethod2(nums, 8);
    print(nums, 8);

    return 0;
}