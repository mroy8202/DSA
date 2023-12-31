// LINK: https://leetcode.com/problems/n-queens/description/
// NOTES: https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/

// Solution 1
// TC: O(N! * N)
// SC: O(N^2)
class Solution
{
private:
    bool isSafe(int row, int col, vector<string> board, int n) {
        int dupRow = row;
        int dupCol = col;

        // <-- (col--)
        // <-- (row-1)
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // <-- (col--)
        row = dupRow;
        col = dupCol;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = dupRow;
        col = dupCol;
        // <-- (col--)
        // <-- (row+1)
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> board, vector<vector<string>> &ans, int n) {
        // base case
        if (col >= n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};

// Solution 2
// TC: O(N! * N)
// SC: O(N^2)
class Solution {
private: 
    void solve(int col, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, vector<string>& board, vector<vector<string>>& ans, int n) {
        // base case
        if(col >= n) {
            ans.push_back(board);
            return ;
        }

        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1, leftRow, upperDiagonal, lowerDiagonal, board, ans, n);
                // backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);

        solve(0, leftRow, upperDiagonal, lowerDiagonal, board, ans, n);
        return ans;
    }
};