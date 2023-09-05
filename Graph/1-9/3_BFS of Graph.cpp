#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    // visited array of size n, initialised with 0
    vector<int> vis(n, 0);
    vis[0] = 1;

    queue<int> q;
    q.push(0);

    // vector for storing answer
    vector<int> bfs;

    while(!q.empty()) {
        int value = q.front();
        q.pop();
        bfs.push_back(value);

        // iterating the adjacency vector and pushing into queue if value is not visited
        for(auto it: adj[value]) {
            if(vis[it] == 0) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    
    return bfs;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    // storing in a List
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs = bfsOfGraph(n, adj);
    for(int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    } cout << endl;

    return 0;
}