class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        // priority queue : {maxDiff, {row, col}}
        using pi = pair<int, pair<int, int>>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int maxDiff = top.first;
            int row = top.second.first;
            int col = top.second.second;
            
            // when {row, col} is target co-ordinates
            if(row == n-1 && col == m-1) return maxDiff;
            
            // travel in all 4 directions
            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                // check if valid
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m) {
                    int absDiff = abs(heights[row][col] - heights[nRow][nCol]);
                    int newEffort = max(absDiff, maxDiff);
                    
                    if(newEffort < dist[nRow][nCol]) {
                        dist[nRow][nCol] = newEffort;
                        pq.push({newEffort, {nRow, nCol}});
                    }
                }
            }
        }
        return 0;
    }
};