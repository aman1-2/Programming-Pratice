/*

Question 3 : Write a program to Find Transpose of a Matrix. 
What is Transpose?
Transpose of a matrix is the process of swapping the rows to columns. For a 2x3 
matrix,
Matrix
a11 a12 a13 
a21 a22 a23
Transposed Matrix 
a11 a21
a12 a22
a13 a23

*/

#include<iostream>
#include<vector>
using namespace std;

void transpose(vector<vector<int>> nums){
    vector<vector<int>> temp(nums[0].size(), vector<int>( nums.size()));

    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size(); j++){
            temp[j][i] = nums[i][j];
        }
    }

    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp[i].size(); j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }

    return;
}

int main(){
    vector<vector<int>> nums = { {1,2,3}, {4,5,6} };
    transpose(nums);

    return 0;
}