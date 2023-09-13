// Traverse through the boundary and call dfs function if mat[i][j] = 'O' and mark the visited
// Traverse again and if(mat[i][j] = 'O') and is not visited, replace mat[i][j] = 'X'
// TC: O(m*n)
// SC: O(m*n)

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, int n, int m, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        
        // find all neighbour '0' and mark them visited
        for(int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            // check for valid neighbour and 'O' and not visited
            if( (nRow>=0 && nRow<n && nCol>=0 && nCol<m) && (mat[nRow][nCol] == 'O' && !vis[nRow][nCol]) ) {
                dfs(nRow, nCol, vis, mat, n, m, delRow, delCol);
            }
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        // traverse at the boundary of mat
        // and mark all adjacent O's visited
        
        // traverse 1st row and last row
        for(int i = 0; i < m; i++) {
            if(mat[0][i] == 'O' && !vis[0][i]) dfs(0, i, vis, mat, n, m, delRow, delCol);
            if(mat[n-1][i] == 'O' && !vis[n-1][i]) dfs(n-1, i, vis, mat, n, m, delRow, delCol);
        }
        
        // traverse 1st column and last column
        for(int i = 1; i < n-1; i++) {
            if(mat[i][0] == 'O' && !vis[i][0]) dfs(i, 0, vis, mat, n, m, delRow, delCol);
            if(mat[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1, vis, mat, n, m, delRow, delCol);
        }
        
        // traverse throught whole array
        // and if not visited and is 'O', make 'X'
        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) {
                if(mat[i][j] == 'O' && !vis[i][j]) mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};