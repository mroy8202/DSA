// LINK: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

// Using Kahn's Algorithm / BFS
// Kahn's algorithm gives the topological sort of a Directed Acyclic Graph
// So, if a cycle is present, then queue will get empty before visiting all the nodes
// if all nodes are counted and they are not equal to the given nodes, then cycle is present

// TC: O(V+E) + O(V) + O(V+E) = O(V+E)
// SC: O(V) + O(V) = O(V)
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        // fill the indegree
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            // push nodes into the queue with indegree 0
            if(indegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            // traverse through the adjacent nodes of node and decrese their indegree
            for(auto it: adj[node]) {
                indegree[it]--;
                // when indegree of a adjacent node becomes 0, push into the queue
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        // if we have visited all the nodes, that means there is no cycle
        if(count == V) return false;
        else return true;
    }
};