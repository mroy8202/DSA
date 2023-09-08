// Push all the coordinates of rotten oranges in the queue
// maintain a visited matrix to store rotten oranges
// while queue is not empty, take the size of queue and increase the time
// traverse through all the queue element neighbors to rott another oranges and push into the queue as well
// TC: O(n*m)
// SC: O(n*m)

int bfs(queue<pair<int, int>> q, vector<vector<int>> vis, vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size();
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            int rr = q.front().first;
            int cc = q.front().second;
            q.pop();
            
            // traverse all 4 coordinates and update vis
            for(int i = 0; i < 4; i++) {
                int nRow = rr + delRow[i];
                int nCol = cc + delCol[i];
                if( (nRow>=0 && nRow<n && nCol>=0 && nCol <m) && (vis[nRow][nCol] == 1) ) {
                    vis[nRow][nCol] = 2;
                    q.push({nRow, nCol});
                }
            }
        }
        time++;
    }
    
    // check if any orange is still not rotten
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 1) return -1;
        }
    }
    
    return time-1;
}

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis = grid;
    
    // queue to carry all rotten oranges
    queue<pair<int, int>> q;
    
    // traverse and push rotten tomatoes coordinates in queue
    int cntZero = 0, cntOne = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) q.push({i, j});
            else if(grid[i][j] == 1) cntOne++;
            else cntZero++;
        }
    }
    
    if(q.size() > 0) return bfs(q, vis, grid);
    else if(cntOne > 0) return -1;
    else return 0;
}
