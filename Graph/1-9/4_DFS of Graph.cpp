#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], vector<int> adj[], vector<int>& ans) {
    ans.push_back(node);
    vis[node] = 1;

    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            dfs(it, vis, adj, ans);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    int node = 1;
    int vis[n+1] = {0};
    vector<int> ans;
    dfs(node, vis, adj, ans);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    // storing in a List
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "dfs: ";
    vector<int> ans = dfsOfGraph(n, adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    } cout << endl;

    return 0;
}

// Time Complexity: O(n + 2E)
// Space Complexity: O(n)