class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // create an adjacency list
        vector<pair<int, int>> adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // {time, node}
        using pi = pair<long long, int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        
        vector<long long> time(n, LLONG_MAX);
        time[0] = 0;
        
        vector<int> ways(n, 0);
        ways[0] = 1;
        
        int mod = (int)(1e9 + 7);
        while(!pq.empty()) {
            long long minTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int t = it.second;
                
                // first time coming with short distance
                if(minTime + t < time[adjNode]) {
                    time[adjNode] = minTime + t;
                    pq.push({time[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                
                else if(minTime + t == time[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};