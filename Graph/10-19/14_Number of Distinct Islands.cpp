/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands 
where a group of connected 1s (horizontally or vertically) forms an island. 
Two islands are considered to be distinct if and only if 
one island is not equal to another (not rotated or reflected).

Example 1:
Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output: 1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:
Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output: 3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:
You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/

/*
                APPROACH ->
Traverse through the grid and if 1 is found, call dfs function which will mark all its neighbour 1's visited.
Use a set data structure to store unique shapes of islands.

How to store shapes in a set ?
Ex: 
   0  1  2  3  4
0 [1, 1, 0, 1, 1]
1 [1, 0, 0, 0, 0]
2 [0, 0, 0, 1, 1]
3 [1, 1, 0, 1, 0]

We have to consider a base Co-ordinates, from where we will start moving or seaching for 1.
Subtract every Co-ordinates from their base Co-ordinate and store.
Store the resultant Co-ordinates in set.
if 2 shapes are similar, then they will have same resultant Co-ordinates.

grid[0, 0] = 1
Connections: {0, 0}, {0, 1}, {1, 0}.    base: {0, 0}
result1: {0, 0}, {0, 1}, {1, 0}

grid[2, 3] = 1
Connections: {2, 3}, {2, 4}, {3, 3}.    base: {2, 3}
result2: {0, 0}, {0, 1}, {1, 0}

Here result1 and result2 are similar. Hence, they are not distinct.
*/

// TC: O(n*m) * log(n*m) + )(n*m*4)
// SC: O(n*m)
class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, 
    int delRow[], int delCol[], int n, int m, vector<pair<int, int>>& v, int baseRow, int baseCol) {
        vis[row][col] = 1;
        
        v.push_back({row-baseRow, col-baseCol});
    
        // traverse in all 4 directions to find another island
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            // check for valid neighbours, island, and should not be visited
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
            && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, grid, delRow, delCol, n, m, v, baseRow, baseCol);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        set<vector<pair<int, int>>> s;
        
        // traverse through the grid and call dfs for island
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> v;
                    dfs(i, j, vis, grid, delRow, delCol, n, m, v, i, j);
                    s.insert(v);
                }
            }
        }
    
        return s.size();
    }
};