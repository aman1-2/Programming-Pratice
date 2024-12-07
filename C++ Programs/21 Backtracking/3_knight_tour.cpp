/*
Question 3 : Knight’s Tour

Given a N*N board with the Knight placed on the first block of an empty board. Moving 
according to the rules of chess, knights must visit each square exactly once. Print the order
of each cell in which they are visited.

Sample Input 1 : N = 8
Sample Output 1 :
0 59 38 33 30 17 8 63
37 34 31 60 9 62 29 16
58 1 36 39 32 27 18 7
35 48 41 26 61 10 15 28
42 57 2 49 40 23 6 19
47 50 45 54 25 20 11 14
56 43 52 3 22 13 24 5
51 46 55 44 53 4 21 12

(Hint : Similar to N Queens)
*/

#include<iostream>
#include<vector>
using namespace std;

bool knightTour(int currRow, int currCol, vector<vector<int>> &grid, int size, int count){
    cout<<currRow<<" "<<currCol<<endl;
    //Base case
    //If not able to make a move
    if(currRow < 0 || currCol < 0 || currRow >= size || currCol >= size || grid[currRow][currCol] >= 0)    return false;
    //Check whether its our last move or not.
    if(count == (size*size-1)){
        cout<<"Last"<<endl;
        grid[currRow][currCol] = count;
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        return true;
    }

    grid[currRow][currCol] = count;

    if(knightTour(currRow+1, currCol+2, grid, size, count+1))   return true;
    if(knightTour(currRow+1, currCol-2, grid, size, count+1))   return true;
    if(knightTour(currRow-1, currCol+2, grid, size, count+1))   return true;
    if(knightTour(currRow-1, currCol-2, grid, size, count+1))   return true;
    if(knightTour(currRow+2, currCol+1, grid, size, count+1))   return true;
    if(knightTour(currRow+2, currCol-1, grid, size, count+1))   return true;
    if(knightTour(currRow-2, currCol+1, grid, size, count+1))   return true;
    if(knightTour(currRow-2, currCol-1, grid, size, count+1))   return true;

    //Backtracking
    grid[currRow][currCol] = -1;

    return false;

}
int main(){
    int n = 8;
    vector<vector<int>> grid(n, vector<int> (n, -1));
    knightTour(0,0,grid,n,0);
    return 0;
}