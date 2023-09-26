// LINK: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

class Solution {
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        st.insert({0, S});
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int distance = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it: adj[node]) {
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(distance + edgeWeight < dist[adjNode]) {
                    // when 
                    if(dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode});
                    
                    dist[adjNode] = distance + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};