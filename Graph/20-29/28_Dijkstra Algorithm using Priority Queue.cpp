// LINK: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
// TC: O(E * LogV)
// SC: 
class Solution {
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        pq.push({0, S}); // pair<dist, node>
        
        while(!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // travel to all it's adjacent nodes and compare the distance
            for(auto it: adj[node]) {
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(distance + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};