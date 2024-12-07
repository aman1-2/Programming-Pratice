/*
Question 2 : Print out the sum of the numbers in the second row of the “nums” array.
Example :
Input - int nums[ ][ ] = { {1,4,9}, {11,4,3}, {2,2,3} };
Output - 18
*/

#include<iostream>
using namespace std;

int sum(int nums[][3]){
    int sum = 0;

    for(int i=0; i<3; i++){
        sum += nums[1][i];
    }

    return sum;
}

int main(){
    int nums[][3] = { {1,4,9}, {11,4,3}, {2,2,3} };
    int res = sum(nums);

    cout<<"Sum of the second row values is: "<<res;

    return 0;
}