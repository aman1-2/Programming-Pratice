/*Print the following in the spiral order
[
[1,2,3,4],
[5,6,7,8],
[9,10,11,12],
[13,14,15,16]
]

OUTPUT -> 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10 */

#include<iostream>
#include<vector>
using namespace std;

// While passing a matrix as an parameter we need to pass the columns value even though if we leave the rows.
void spiralMatrix(int nums[][4], int rows, int cols){
    int starting_row = 0, starting_col = 0, ending_row = rows-1, ending_col = cols-1;

    while(starting_row <= ending_row && starting_col <= ending_col){
        //Traversing the Top Side. Here our starting_row will be fix. And we will be moving through col.
        for(int j=starting_col; j<=ending_col; j++)     cout<<nums[starting_row][j]<<" ";

        //Traversing the Right Side. Here our ending_col will be fix. And we will be moving through row.
        for(int j=starting_row+1; j<=ending_row; j++)   cout<<nums[j][ending_col]<<" ";

        //Traversing the Bottom Side. Here our ending_row will be fix. And we will be moving through col.
        for(int j=ending_col-1; j>=starting_col; j--)   cout<<nums[ending_row][j]<<" ";

        //Traversing the Left Side. Here our starting_col will be fix. And we will be moving through row.
        for(int j=ending_row-1; j>=starting_row+1; j--) cout<<nums[j][starting_col]<<" ";

        //Once we have traversed through all the boundaries Before going to the next iteration update these values.
        starting_row++;
        starting_col++;
        ending_row--;
        ending_col--;
    }

    return;
}

int main(){
    int nums[4][4] = {
        {1,2,3,4},
        {5,6,7,8,},
        {9,10,11,12},
        {13,14,15,16}
    };

    spiralMatrix(nums, 4, 4);
    
    return 0;
}