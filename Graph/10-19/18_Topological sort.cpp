// TC: O(V+E)
// SC: O(2V) = O(V)
class Solution {
  private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
        vis[node] = 1;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }
    
  public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> vis(V, 0);
	    stack<int> st;
	    
	    // go to every node & if not visited, call DFS
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, st, adj);
	        }
	    }
	    
	    // push stack elements into ans
	    vector<int> ans;
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};