class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // create an adjacency list
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
        }
        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            
            // travel to all its adjacent nodes
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                
                if(distance + edgeWt < dist[adjNode]) {
                    // update dist and push in pq
                    dist[adjNode] = distance + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    // update parent of adjNode
                    parent[adjNode] = node;
                }
            }
        }
        
        vector<int> path;
        // when nth node is not reachable
        if(parent[n] == n) return {-1};
        
        // when nth node is reachable and shortest path has been calculated
        int node = n;
        while(node != parent[node]) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        
        reverse(path.begin(), path.end());
        return path;
    }
};