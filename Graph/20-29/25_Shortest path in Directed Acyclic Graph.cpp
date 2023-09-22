// LINK: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

// Do Topological Sorting on the Graph using DFS and store it in stack
// Take the nodes out of the stack and relax the edges

// TC: O(M+N)
// SC: O(M+N)
class Solution {
  private:
    void topoSort(int node, stack<int>& st, vector<int>& vis, vector<pair<int, int>> adj[]) {
        vis[node] = 1;
        
        // traverse to all the adjacent nodes
        for(auto it: adj[node]) {
            if(!vis[it.first]) {
                topoSort(it.first, st, vis, adj);
            }
        }
        
        // push into stack
        st.push(node);
    }
    
  public:
     vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        for(int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // store topo sort using dfs in the stack
        stack<int> st;
        vector<int> vis(N, 0);
        topoSort(0, st, vis, adj);
        
        // to store distance
        vector<int> ans(N, INT_MAX);
        ans[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            // traverse to all the adjacent nodes and update the ans
            for(auto it: adj[node]) {
                int wt = ans[node];
                if(wt + (it.second) < ans[it.first]) {
                    ans[it.first] = wt + (it.second);
                }
            }
        }
        
        // when it is impossible to reach some nodes
        for(int i = 0; i < N; i++) {
            if(ans[i] == INT_MAX) ans[i] = -1;
        }
        
        return ans;
    }
};