// We are finding no. of connected components in a graph
// Created a visited 2D vector to keep track of visited islands
// Start traversing the grid, if island or '1' is found and it is not marked as visited, then that is the start of a node
// call the BFS, and mark all paths from island to island or '1' to '1'.
// In one BFS call, every connected islands will be marked.
// Number of times BFS is called = number of connected components = number of islands
// TC: O(m*n) + O(m*n*9) = O(m*n)
// SC: O(m*n) + O(m*n) = O(m*n)

class Solution {
    private:
        void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
            int n = grid.size(), m = grid[0].size();
            queue<pair<int, int>> q;
            q.push({row, col});
            vis[row][col] = 1;
            
            while(!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                // traverse through all 8 directions to find another island
                for(int delRow = -1; delRow <= 1; delRow++) {
                    for(int delCol = -1; delCol <= 1; delCol++) {
                        int nRow = r + delRow;
                        int nCol = c + delCol;
                        if( (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) && (!vis[nRow][nCol] && grid[nRow][nCol] == '1') ) {
                            vis[nRow][nCol] = 1;
                            q.push({nRow, nCol});
                        }
                    }
                }
            }
        }
    
    public:
        // Function to find the number of islands.
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> vis(n, vector<int> (m, 0));
            
            // traverse into the grid
            int count = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    // if not visited and is an island
                    if(!vis[i][j] && grid[i][j] == '1') {
                        count++;
                        bfs(i, j, vis, grid);
                    }
                }
            }
            return count;
        }
};