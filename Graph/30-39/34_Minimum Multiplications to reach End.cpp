class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        q.push({0, start});
        
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        
        while(!q.empty()) {
            int level = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node == end) return level;
            
            for(int i = 0; i < arr.size(); i++) {
                int newNode = (node*arr[i])%100000;
                if(level + 1 < dist[newNode]) {
                    dist[newNode] = level + 1;
                    q.push({level+1, newNode});
                }
            }
        }
        return -1;
    }
};