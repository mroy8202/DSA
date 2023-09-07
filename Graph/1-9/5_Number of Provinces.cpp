// Created a adjacency List from Adjacency Matrix for the ease of DFS travesal
// Created a visited vector initialised with o to track if nodes are already visited or not
// start traversing visited array and if 0 is found that means it it not visited, so calling a DFS
// which will mark all the connected nodes
// no. of provinces = no. of times when DFS is called
// TC: O(V) + O(V + 2E)
// SC: O(V) + O(V)

class Solution {
  private:
    void dfs(int node, vector<int>& vis, vector<int> adjList[]) {
        vis[node] = 1;
        for(auto it: adjList[node]) {
            if(!vis[it]) {
                dfs(it, vis, adjList);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        //create an adjacency List
        vector<int> adjList[V];
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        // create a visited vector
        vector<int> vis(V, 0);
        int provinces = 0;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                provinces++;
                dfs(i, vis, adjList);
            }
        }
        return provinces;
    }
};