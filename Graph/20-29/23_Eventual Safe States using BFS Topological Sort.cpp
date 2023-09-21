// LINK: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // create a reverse adjacency list
        vector<int> revAdj[V];
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                revAdj[it].push_back(i);
            }
        }
        
        // calculate indegree of every node
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto it: revAdj[i]) {
                indegree[it]++;
            }
        }
        
        // push nodes with indegree 0 in queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: revAdj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            } 
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};