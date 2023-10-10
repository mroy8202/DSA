// LINK: https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group
// NOTES: https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/

class DisjointSet {
  public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  private:
    bool isValid(int nR, int nC, int n) {
        return nR >= 0 && nR < n && nC >= 0 && nC < n;
    }
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
    
        // Connecting components
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    // travel in all 4 directions
                    int delRow[] = {-1, 0, 1, 0};
                    int delCol[] = {0, 1, 0, -1};
                    
                    for(int k = 0; k < 4; k++) {
                        int nR = i + delRow[k];
                        int nC = j + delCol[k];

                        if(isValid(nR, nC, n) && grid[nR][nC] == 1) {
                            // connect them
                            int node = (i * n) + j;
                            int adjNode = (nR * n) + nC; 
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }  
            }
        }
        
        // traverse again to flip atmost one '0' and calculate the size
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    // travel in all 4 directions and store the size
                    int delRow[] = {-1, 0, 1, 0};
                    int delCol[] = {0, 1, 0, -1};
                    
                    set<int> components;
                    for(int k = 0; k < 4; k++) {
                        int nR = i + delRow[k];
                        int nC = j + delCol[k];
                        
                        if(isValid(nR, nC, n) && grid[nR][nC] == 1) {
                            int adjNode = (nR * n) + nC; 
                            components.insert(ds.findUPar(adjNode));
                        }
                    }
                    
                    int connectedSize = 0;
                    for(auto it: components) connectedSize += ds.size[it];
                    ans = max(ans, connectedSize + 1);
                }
            }
        }
        
        // edge case, when grid has no 0's at all
        for(int cell = 0; cell < n*n; cell++) {
            ans = max(ans, ds.size[ds.findUPar(cell)]);
        }
        
        return ans;
    }
};