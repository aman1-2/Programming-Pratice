/**
 * PROBLEM STATEMENT :- Given an Integer Array where every element occurs twice except one
occurs only one. Find that Unique number.

Problem says that we are given an integer array as [2,1,3,2,1,5,5,6,3] where element occurs twice
except one element and we need to find that unique element. 

If would solve this problem using sorting or hashmap but lets solve it through Bit manipulation 
where XOR of any two same number will be 0 and XOR of 0 with x will be x only.
And XOR is a commucative property which means x^y^z = z^x^y.
So technically if we take out the XOR or all the elements of arrays in any order the same 
numbers XOR will become 0 and since we have just unique element XOR of 0 and that unique 
element will result into that element.
*/

#include<iostream>
using namespace std;

int uniqueEle(int arr[], int n) {
    int res = 0;

    for(int i=0; i<n; i++) {
        res = res ^ arr[i];
    }

    return res;
}

int main() {
    int arr[] = {1,2,3,1,2,3,4};
    cout<<uniqueEle(arr, 7)<<endl;

    return 0;
}