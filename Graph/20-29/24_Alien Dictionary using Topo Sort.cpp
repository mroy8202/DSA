class Solution{
    private:
    vector<int> topologicalSort(int V, vector<int> adj[]) {
        // calculate indegree of every node
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        // push nodes with indegree 0 in queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return ans;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        // created an adjacency list and stored values an an Directed Graph
        vector<int> adj[K];
        for(int i = 0; i < N-1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(), s2.size());
            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        // Perfoming Topological sort to maintain the order
        vector<int> topo = topologicalSort(K, adj);
        
        string ans = "";
        for(auto it: topo) {
            ans += it + 'a';
        }
        
        return ans;
    }
};