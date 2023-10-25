// LINK: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// NOTES: https://takeuforward.org/data-structure/rat-in-a-maze/

class Solution{
  private:
    void dfs(int row, int col, vector<vector<int>> &m, vector<string>& ans, vector<vector<bool>> vis, int n, string path) {
        if(row == n-1 && col == n-1) {
            ans.push_back(path);
            return ;
        }

        vis[row][col] = true;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        string dir = "URDL";
        
        for(int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && m[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                path += dir[i];
                dfs(nRow, nCol, m, ans, vis, n, path);
                path = path.substr(0, path.size()-1); // backtrack
            }
        }
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0) return {"-1"};
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        
        dfs(0, 0, m, ans, vis, n, "");
        if(ans.size() == 0) return {"-1"};
        return ans;
    }
};

    