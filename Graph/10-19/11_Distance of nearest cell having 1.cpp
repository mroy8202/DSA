// traverse the whole matrix and push every {row,column} having value 1 in queue and mark them visited
// Now, take every element from the queue and look for all its 4 neighbours with value 0 and update them in ans level wise
// mark them visited too.
// TC: O(m*n) + O(m*n) = O(m*n)
// SC: O(m*n) + O(m*n) = O(m*n)

class Solution {
  private:
    void bfs(queue<pair<int, int>> q, vector<vector<int>>& ans, vector<vector<int>> grid, vector<vector<int>> vis) {
        int n = grid.size(), m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int level = 1;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // traverse to all 4 neighbours
                for(int i = 0; i < 4; i++) {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    // check for valid neighbours
                    if((nRow>=0 && nRow<n && nCol>=0 && nCol<m) && grid[nRow][nCol] == 0 && !vis[nRow][nCol]) {
                        vis[nRow][nCol] = 1;
                        ans[nRow][nCol] = level;
                        q.push({nRow, nCol});
                    }
                }
            }
            level++;
        }
    }

  public:
    vector<vector<int>>nearest(vector<vector<int>> grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        queue<pair<int, int>> q;
        // collect all the row,col having element 1 in queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        bfs(q, ans, grid, vis);
        return ans;
    }
};