// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// take 2 arrays visited, pathvisited.
// Check for connected components, and if a node is not visited call dfs function.
// start traversing in dfs and mark adjacent node visited and path visited
// while returning from the dfs function, unmark the path visited
// if a node is visited and it is in the path already(pathVis), then there is a cycle

// Using 2 additional vectors
// TC: O(V+E)
// SC: O(2V) + O(V) = O(v)
class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]) {
            // adjacent node is not visited
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, adj) == true) {
                    return true;
                }
            }

            // adjacent node has been previously visited
            // but it has to be visited on the same path
            else if(pathVis[it]) {
                return true;
            }
        }
        
        // unvisit the path when returning back
        pathVis[node] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        // check for multiple connected components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};


// using 1 additional vector only, mark vis as 1 and mark pathVis as 2
// TC: O(V+E)
// SC: O(V) + O(V) = O(v)
class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 2;
        
        for(auto it: adj[node]) {
            // adjacent node is not visited
            if(!vis[it]) {
                if(dfs(it, vis, adj) == true) {
                    return true;
                }
            }

            // adjacent node has been previously visited
            // but it has to be visited on the same path
            else if(vis[it] == 2) {
                return true;
            }
        }
        
        // unvisit the path when returning back
        vis[node] = 1;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        // check for multiple connected components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, adj) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};