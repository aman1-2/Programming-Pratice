/**
 * Given an Integer Array you need find out the pair of elements at two differnet indices whose sums are equal to the target value.
 * Both the elements in the pair must reside at two different indices.
 * And we need to print those two indices whose sum is equal to the target value.
 * 
 * Brute Force 
 */

#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 7, 11, 15, 5, 9};
    int n = 7, target = 9;
    unordered_map<int, int> um; //Pair will be somewhat like key will be arr[i] and value will be its index position.

    for(int i=0; i<n; i++) {
        //Calculating the compliment
        int comp = target - arr[i];
        //Then we will search the compliment in our map. We already have arr[i] we just need to find out the compliment.
        if(um.count(comp)) { //if we found the comp and our target sum is achieved.
            cout<<"Ans = "<<um[comp]<<", "<<i<<endl;
            break;
        }

        //If element is not found then we need to add that element in our map.
        um[arr[i]] = i;

    }

    return 0;
}