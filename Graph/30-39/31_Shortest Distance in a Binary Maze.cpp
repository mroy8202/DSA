// LINK: https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

// TC: O(N*M)
// SC: O(N*M)
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, 
    pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[source.first][source.second] = 1;
        queue<pair<pair<int,  int>, int>> q;
        // push source in queue and level 0
        q.push({{source.first, source.second}, 0});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int level = q.front().second;
            q.pop();
            
            // when we reach our destination
            int dRow = destination.first;
            int dCol = destination.second;
            if(row == dRow && col == dCol) {
                return level;
            }
            
            // travel all 4 directions to find 1
            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                // check for valid co-ordinates
                if((nRow>=0 && nRow<n && nCol>=0 && nCol<m) && 
                grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, level+1});
                } 
            }
        }
        return -1;
    }
};