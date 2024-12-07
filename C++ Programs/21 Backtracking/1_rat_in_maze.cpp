/*
Question 1 : Rat in a Maze

You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the 
maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a 
square matrix of order N * N where the cells with value 0 represent the maze’s blocked 
locations while value 1 is the open/available path that the rat can take to reach its destination. 
The rat's destination is at (N - 1, N - 1).
Your task is to find all the possible paths that the rat can take to reach from source to 
destination in the maze.
The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down)
i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y). 
(This problem is similar to Grid ways.)

Sample Input : int maze[ ][ ] = { { 1, 0, 0, 0 },
                                  { 1, 1, 0, 1 },
                                  { 1, 1, 0, 0 },
                                  { 0, 1, 1, 1 }
                                };

Sample Outputs : 
DDRDRR
DRDDRR

Hint : To track which cell has or not been visited, create a NxN vector called visited.
This vector will be initialized with false values for all cells & make the value for a particular cell 
to true when you have visited it
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> grid;

bool isVisited(int rowIdx, int colIdx){
    return (rowIdx>=0 && colIdx>=0 && rowIdx < grid.size() && colIdx < grid.size() && grid[rowIdx][colIdx] == 1);
}

int ratInMaze(int row, int col, string str){
    if(row == grid.size()-1 && col == grid.size()-1){
        int n = grid.size(); 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"*****************\n";
        return 1;
    }

    grid[row][col] = 0;

    int ans = 0;

    //Up-move
    if(isVisited(row-1,col)){
        ans += ratInMaze(row-1, col, str+"u");
    }

    //Down-move
    if(isVisited(row+1,col)){
        ans += ratInMaze(row+1, col, str+"d");
    }

    //left-move
    if(isVisited(row,col-1)){
        ans += ratInMaze(row, col-1, str+"l");
    }

    //right-move
    if(isVisited(row,col+1)){
        ans += ratInMaze(row, col+1, str+"r");
    }

    grid[row][col] = 1;

    cout<<str<<endl;

    return ans;
}

int main(){
    grid = { { 1, 0, 0, 0 },
             { 1, 1, 0, 1 },
             { 1, 1, 0, 0 },
             { 0, 1, 1, 1 }
            };

    int possiblePaths = ratInMaze(0, 0, "");
    cout<<"Answer is: "<<possiblePaths;

    return 0;
}
