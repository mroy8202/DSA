// LINK: https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

// If we can create a topological sort values, then ans is true

// TC: O(m+n)
// SC: O(m+n)
class Solution {
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        // create an adjacency list
        vector<int> adj[n];
        for(int i = 0; i < m; i++) {
            int adjacentNode = prerequisites[i][0];
            int node = prerequisites[i][1];
            adj[node].push_back(adjacentNode);
        }
        
        // calculate indegree of each node
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        // create a queue and push nodes with indegree 0
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // traverse through all adjacent nodes and decrease their indegree
            for(auto it: adj[node]) {
                indegree[it]--;
                // when indegree becomes 0, push adjacent node in queue
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        // check if ans size is n or not
        if(ans.size() == n) return ans;
        else return {};
    }
};