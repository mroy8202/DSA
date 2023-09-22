// LINK: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
// created an adjacency list and using bfs we found ans
// TC: O(M+N)
// SC: O(M+N)
class Solution {
  private:
    vector<int> bfs(int src, vector<int>& vis, vector<int> adj[], int N) {
        vector<int> ans(N, -1);
        
        queue<int> q;
        q.push(src);
        
        vis[src] = 1;
        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                ans[node] = dist;
                
                for(auto it: adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            dist++;
        }
        return ans;
    }
    
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src){
        vector<int> adj[N];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(N, 0);
        return bfs(src, vis, adj, N);
    }
};