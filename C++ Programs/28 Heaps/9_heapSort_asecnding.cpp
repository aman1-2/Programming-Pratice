#include<iostream>
#include<vector>
using namespace std;

//Inside the heapify function we will basically recieve the index of the parent, we will recieve the vector of arr, and the last parameter which is size of the vector.
void heapify(int ParIdx, vector<int> &arr, int size) {
    //Now with the help of the parent idx we will first try to calculate our left and right child index value
    int leftIdx = 2*ParIdx + 1;
    int rightIdx = 2*ParIdx + 2;

    //Currently storing the maxIdx as the parent index value.
    int maxIdx = ParIdx;

    //If the left child index is a valid index and if the value of left-child-index is more then the maxIdx then update maxIdx.
    if(leftIdx < size && arr[leftIdx] > arr[maxIdx]) {
        maxIdx = leftIdx;
    }

    //If the right child index is a valid index and if the value of right-child-index is more then the maxIdx then update maxIdx.
    if(rightIdx < size && arr[rightIdx] > arr[maxIdx]) {
        maxIdx = rightIdx;
    }

    //Swap the maxIdx with the parent index.
    swap(arr[maxIdx], arr[ParIdx]);

    //If the maxIdx is not same as the parent index then call the heapify again for the maxIdx.
    if(maxIdx != ParIdx)   heapify(maxIdx, arr, size);

    return;
}

void heapSort(vector<int> &arr) {
    //STEP 1: Creating a maxHeap as we want to sort the given data in ascending order.
    int n = arr.size();
    //Calling the Heapify function for the first 0 to n/2-1 elements.
    for(int i=n/2-1; i>=0; i--) { 
        heapify(i, arr, n); //Here Heapify function will fix the heap for the ith node and 
        //inside the Heapify function we passed the vector and the size of the vector there 
        //is a specific reason for passing the size of the vector which will get clear in step 2.
    }
    //STEP 2: Sorting the array.
    for(int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]); //Swaping the first element with the last element i.e placing the greatest element at the end of the vector.
        heapify(0, arr, i);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3}; //This is the Array which we want to sort
    heapSort(arr);
    for(int ele: arr) {
        cout<<ele<<" ";
    }

    return 0;
}