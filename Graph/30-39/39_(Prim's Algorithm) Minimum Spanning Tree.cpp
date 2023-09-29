// LINK: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
// NOTES: https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/

// TC: O(E * log E) + O(E * log E) = O(E * log E)
// SC: O(E) + O(V)
class Solution {
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        using pi = pair<int, int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> vis(V, 0);
        // {edWt, node}
        pq.push({0, 0});
        
        int sum = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int edWt = pq.top().first;
            pq.pop();
            
            if(vis[node] == 1) continue;
            // if node is not visited, visit it and add it's edWt to the sum
            vis[node] = 1;
            sum += edWt;
            
            // traverse through the adjacent nodes
            for(auto it: adj[node]) {
                int adjNode = it[0];
                int wt = it[1];
                if(!vis[adjNode]) {
                    pq.push({wt, adjNode});
                }
            }
        }
        return sum;
    }
};