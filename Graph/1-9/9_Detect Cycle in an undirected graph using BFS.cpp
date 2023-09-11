// For detect the cycle using BFS, we push the source node and its source in queue
// traverse level wise and mark them in visited array
// if we can reach to a node in next level from more than one paremt node, then cycle is present
// multiple connected components may be present, so send every source node in detectCycle function
// TC: O(V + 2E) + O(V)
// SC: O(V) + O(V)

class Solution {
  private:
    bool detectCycle(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentNode: adj[node]) {
                if(!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                
                // adjacentNode is already visited, but it is not the parent
                else if(parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        // find the source node of all connected components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if( detectCycle(i, adj, vis) ) return true;
            }
        }
        return false;
    }
};    

