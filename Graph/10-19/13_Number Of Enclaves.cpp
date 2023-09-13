// Traverse through the boundary and call dfs function if grid[i][j] = 1 and mark them visited
// Traverse again and if(grid[i][j] = 1) and is not visited, count them in ans
// TC: O(m*n)
// SC: O(m*n)

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[], int n, int m) {
        vis[row][col] = 1;
        
        // traverse through all 4 neighbours
        for(int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            // check for valid neighbours and should be a land && should not be visited
            if( (nRow>=0 && nRow<n && nCol>=0 && nCol<m) && (grid[nRow][nCol] == 1 && !vis[nRow][nCol]) ) {
                dfs(nRow, nCol, grid, vis, delRow, delCol, n, m);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        // traverse boundary elements and mark them visited if it is a land
        // traverse 1st row and last row
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 1 && !vis[0][i]) dfs(0, i, grid, vis, delRow, delCol, n, m);
            if(grid[n-1][i] == 1 && !vis[n-1][i]) dfs(n-1, i, grid, vis, delRow, delCol, n, m);
        }
        
        // traverse 1st column and last column
        for(int i = 1; i < n-1; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) dfs(i, 0, grid, vis, delRow, delCol, n, m);
            if(grid[i][m-1] == 1 && !vis[i][m-1]) dfs(i, m-1, grid, vis, delRow, delCol, n, m);
        }
        
        // traverse through matrix and count the land that is not visited
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        
        return cnt;
    }
};