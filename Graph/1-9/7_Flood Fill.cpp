// Stand at given index and call DFS function
// color the index with given color
// traverse through all four directions and move recursively if it is a valid move
// when dfs is completed, ans will be computed
// TC: O(n*m)
// SC: O(n*m)

class Solution {
private:
    void dfs(int row, int col, int newColor, vector<vector<int>>& ans, vector<vector<int>> image, int delRow[], int delCol[], int initialColor) {
        ans[row][col] = newColor;
        int n = image.size(), m = image[0].size();
        for(int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            // check for valid coordinates
            // then check for same initial color and unvisited pixel
            if( (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) && (image[nRow][nCol] == initialColor) && (ans[nRow][nCol] != newColor) ) {
                dfs(nRow, nCol, newColor, ans, image, delRow, delCol, initialColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, color, ans, image, delRow, delCol, initialColor);
        return ans;
    }
};