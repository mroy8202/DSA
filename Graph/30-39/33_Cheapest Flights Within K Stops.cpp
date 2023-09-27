class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create an adjacency list
        vector<pair<int, int>> adj[n];
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> price(n, 1e9);
        price[src] = 0;

        while(!q.empty()) {
            auto iter = q.front();
            q.pop();

            int stops = iter.first;
            int node = iter.second.first;
            int cost = iter.second.second;

            if(stops > k) continue;

            // travel to adjacent nodes
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int newCost = it.second;

                if(cost + newCost < price[adjNode]) {
                    // update adjNode's price
                    price[adjNode] = cost + newCost;
                    q.push({stops+1, {adjNode, cost+newCost}});
                }
            }
        }

        if(price[dst] == 1e9) return -1;
        return price[dst];
    }
};