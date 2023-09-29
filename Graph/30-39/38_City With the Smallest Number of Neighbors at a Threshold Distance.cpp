// LINK: https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
// NOTES: https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/

// TC: O(N^3)
// SC: O(N^2)
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][via] == 1e9 || dist[via][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j], 
                                    dist[i][via] + dist[via][j]);
                }
            }
        }
        
        int maxCount = n-1;
        int city = -1;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i==j) continue;
                else if(dist[i][j] <= distanceThreshold) count++;
            }
            if(count <= maxCount) {
                city = i;
                maxCount = count;
            }
        }
        return city;
    }
};