/*Question 1 : Use the following sorting algorithms to sort an array in DESCENDING
order :
a. Bubble Sort
b. Selection Sort
c. Insertion Sort
d. Counting Sort
You can use this array as an example : [3, 6, 2, 1, 8, 7, 4, 5, 3, 1]*/

#include<iostream>
using namespace std;

void print(int nums[], int size){
    for(int i=0; i<size; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return;
}

void bubbleSort(int nums[], int size){
    for(int i=0; i<size-1; i++){
        bool flag = false;
        for(int j=0; j<(size-1)-i; j++){
            if(nums[j]<nums[j+1]){
                flag = true;
                swap(nums[j], nums[j+1]);
            }
        }
    }

    cout<<"Bubble Sort Printing:-"<<endl;
    print(nums, size);

    return;
}

void selectionSort(int nums[], int size){
    for(int i=0; i<size-1; i++){
        int max_ele_idx = i;
        for(int j=i+1; j<size; j++){
            if(nums[max_ele_idx] < nums[j]) max_ele_idx = j;
        }
        if(i != max_ele_idx)  swap(nums[max_ele_idx], nums[i]);
    }

    cout<<"Selection Sort Printing:-"<<endl;
    print(nums, size);

    return;
}

void insertionSort(int nums[], int size){
    for(int i=1; i<size; i++){
        int curr_ele = nums[i];
        int prev_idx = i-1;
        
        while(prev_idx >= 0 && nums[prev_idx]<curr_ele){
            swap(nums[prev_idx+1], nums[prev_idx]);
            prev_idx--;
        }
        nums[prev_idx+1] = curr_ele;
    }

    cout<<"Insertion Sort Printing:-"<<endl;
    print(nums, size);

    return;
}

void countingSort(int nums[], int size){
    int max_ele = nums[0];
    for(int i=1; i<size; i++)   max_ele = max(max_ele, nums[i]);

    int freq[max_ele+1] = {0};
    for(int i=0; i<size; i++)   freq[nums[i]]++;

    int j=0;
    for(int i=max_ele; i>=0; i--){
        while(freq[i] > 0){
            nums[j++] = i;
            freq[i]--;
        }
    }

    cout<<"Counting Sort Printing:-"<<endl;
    print(nums, size);

    return;
}

int main(){
    int nums[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};

    bubbleSort(nums, 10);
    selectionSort(nums, 10);
    insertionSort(nums, 10);
    countingSort(nums, 10);

    return 0;
}