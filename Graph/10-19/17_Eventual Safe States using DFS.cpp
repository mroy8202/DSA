// Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
// same as detect cycle in a directed graph

// If any node is a part of cycle or any node which leads to a cycle cannot be a safe node.
// everything else will be safe node

// TC: O(V+E)
// SC: O(2V) + O(V) = O(v)
class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
    vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        // traverse deep to neighbour nodes
        for(auto it: adj[node]) {
            // when adjacent node is not visited yet
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, adj) == true) {
                    return true;
                }
            }
            
            // when adjacent node is visited and pathVisited
            else if(pathVis[it]) {
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    } 
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        // traverse for multiple connected components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, pathVis, adj);
            }
        }
        
        // traverse through pathVis, and push in ans
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            // if(pathVis[i] == 1), that means it is a part of cycle, or leads to a cycle
            if(pathVis[i] == 0) 
                ans.push_back(i);
        }
        return ans;
    }
};