// TC: O(V + 2E) + O(V)
// SC: O(V) + O(V)

class Solution {
  private:
    bool dfs(int node, int parent, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, adj, vis) == true)
                    return true;
            }
            
            // already visited, but not equals to its parent
            else if(adjacentNode != parent) {
                return true;
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                // parent = -1 for source node
                if (dfs(i, -1, adj, vis) == true)
                    return true;
            }
        }
        return false;
    }
};