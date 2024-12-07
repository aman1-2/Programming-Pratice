#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &nums, int strating, int ending, int search){
    while(strating<=ending){
        int mid = (strating+ending)/2;
        
        if(nums[mid] == search) return mid;
        else if(nums[mid] > search) ending = mid - 1;
        else    strating = mid + 1;
    }

    return -1;
}

void searchSortedMatrix(vector<vector<int>> &nums, int search){

    //Brute Force Approach for solving Search Question could be traversing and checking each element and if that element is found return its index or just return -1.
    //This Brute Force Approach will have a time complexity of O(n*m)


    //Second Approach could be row wise or column wise binary approach
    //In someWhat same fashion we can too do with the column wise binary search
    //It has a time complexity of O(n*log m) where n->is number of rows and m is the number of elements each row has.
    // for(int i=0; i<nums.size(); i++){
    //     int res = binarySearch(nums[i], 0, nums[i].size(), search);
    //     if(res != -1){
    //         cout<<"Row = "<<i<<" Column = "<<res;
    //         return;
    //     }
    // }

    // cout<<"Element not found";
    
    /*
    Best Searching Technique for the Sorted Matrix Search is the Stair-case Search:-
    Stair-case Search uses both the row and column sorted information.
    */

    //Situation when we have taken Upper-right element as starting point.
    int row = 0, col = nums.size()-1;
    while(row<nums.size() && col>=0){
        if(nums[row][col] == search){
            cout<<"Row = "<<row<<" Column = "<<col;
            return;
        }
        else if(nums[row][col] > search){ //In this situation we have to move in downward direction.
            col--;
        }
        else{ //If the value of cell is less than search element in that case we have to move leftward direction.
            row++;
        }
    }

    cout<<"Element not found";
    return;

    //Time-Complexity of O(n+m)

}

int main(){
    vector<vector<int>> nums = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    searchSortedMatrix(nums, 50);
    
    return 0;
}