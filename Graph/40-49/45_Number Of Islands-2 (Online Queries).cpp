// LINK: https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
// NOTES: https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/

// Disjoint Set class
class DisjointSet {
  public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }

        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }

        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
  private:
    bool validNeigh(int nRow, int nCol, int n, int m) {
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
            return true;
        }
        return false;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<int> ans;
        
        int cnt = 0;
        for(auto it: operators) {
            int row = it[0];
            int col = it[1];
            
            // when co-ordinate is already visited
            if(vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
            // visit the node and increase the count
            vis[row][col] = 1;
            cnt++;
            
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            
            // travel to its adjacent co-ordinates
            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(validNeigh(nRow, nCol, n, m) && vis[nRow][nCol] == 1) {
                    int node = (row * m) + col;
                    int adjNode = (nRow * m) + nCol;
                    // Check if they are already connected or not
                    // if their ultimate parent is same, do nothing
                    if(ds.findUPar(node) != ds.findUPar(adjNode)) {
                        cnt--;
                        ds.unionByRank(node, adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};