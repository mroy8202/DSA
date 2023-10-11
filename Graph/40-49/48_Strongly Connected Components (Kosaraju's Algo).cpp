// LINK: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo
// NOTES: https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/

// TC: O(V+E)
// SC: O(V+E)
class Solution {
    private:
        void dfs(int node, vector<vector<int>>& adj, stack<int>& s, vector<int>& vis) {
            vis[node] = 1;
            for(int i = 0; i < adj[node].size(); i++) {
                int adjNode = adj[node][i];
                if(!vis[adjNode]) dfs(adjNode, adj, s, vis);
            }
            s.push(node);
        }
        
        void dfs2(int node, vector<vector<int>>& adj2, vector<int>& vis) {
            vis[node] = 1;
            for(int i = 0; i < adj2[node].size(); i++) {
                int adjNode = adj2[node][i];
                if(!vis[adjNode]) dfs2(adjNode, adj2, vis);
            }
        }
        
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        
        // step 1: Sort all the nodes according to their finishing time and store in a stack
        stack<int> s;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, adj, s, vis);
        }
        
        // step2: Reverse the graph
        vector<vector<int>> adj2(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                int u = adj[i][j];
                adj2[u].push_back(i);
            }
        }
        
        // step 3: Do a dfs
        for(int i = 0; i < V; i++) vis[i] = 0;
        int ans = 0;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            
            if(!vis[node]) {
                ans++;
                dfs2(node, adj2, vis);
            }
        }
        return ans;
    }
};