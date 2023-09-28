// LINK: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm
// NOTES: https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/

// TC: O(V*E)
// SC: O(N)
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        // traverse the whole edges for N-1 iterations
        for(int i = 0; i < V-1; i++) {
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int edWt = it[2];
                
                if(dist[u] != 1e8 && dist[u] + edWt < dist[v]) {
                    // update shorter distance
                    dist[v] = dist[u] + edWt;
                }
            }
        }
        
        // Check for Negative cycle
        // when values of dist[] is still changing in Nth iteration
        // then Negative cycle is present
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int edWt = it[2];
            
            if(dist[u] != 1e8 && dist[u] + edWt < dist[v]) {
                // dist[] is still updating, negative cycle is present
                return {-1};
            }
        }
        
        return dist;
    }
};