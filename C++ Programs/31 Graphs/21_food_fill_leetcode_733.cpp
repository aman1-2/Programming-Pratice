// class Solution {
// public:
//     void dfs(int row, int col, int rows, int cols, vector<vector<int>>&image, vector<vector<bool>>&visited, int newColor, int oldColor) {
        
//         visited[row][col] = true;
//         image[row][col] = newColor;

//         // up
//         if(row-1 >= 0 && !visited[row-1][col] && image[row-1][col] == oldColor)
//             dfs(row-1, col, rows, cols, image, visited, newColor, oldColor);

//         // down
//         if(row+1 < rows && !visited[row+1][col] && image[row+1][col] == oldColor)
//             dfs(row+1, col, rows, cols, image, visited, newColor, oldColor);
//         // left
//         if(col-1 >= 0 && !visited[row][col-1] && image[row][col-1] == oldColor)
//             dfs(row, col-1, rows, cols, image, visited, newColor, oldColor);
//         // right
//         if(col+1 < cols && !visited[row][col+1] && image[row][col+1] == oldColor)
//             dfs(row, col+1, rows, cols, image, visited, newColor, oldColor);
//     }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int rows = image.size();
//         int cols = image[0].size();

//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));

//         dfs(sr, sc, rows, cols, image, visited, color, image[sr][sc]);

//         return image;
//     }
// };