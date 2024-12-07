#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int nums[] = {1,4,1,3,2,4,3,7};
    //Need to pass the starting and ending iterator (pointers).
    //Sorted whole array from starting till end. -> In ascending order.
    sort(nums, nums+7);

    for(int i=0; i<8; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    //Sorting a portion of the array.
    sort(nums+2, nums+5);
    for(int i=0; i<8; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    //Sorting whole array from starting till end. -> In descending order.
    sort(nums, nums+8, greater<int>()); // This third parameter is a comparison logic function.

    for(int i=0; i<8; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}