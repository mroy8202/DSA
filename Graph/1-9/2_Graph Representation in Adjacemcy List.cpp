// graph representation in adjacency List
#include<bits/stdc++.h>
using namespace std;

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

    // printing the list
    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(auto it: adj[i]) {
            cout << it << " ";
        } cout << endl;
    }

    return 0;
}
// time complexity: O(n)
// space complexity: O(2*E)