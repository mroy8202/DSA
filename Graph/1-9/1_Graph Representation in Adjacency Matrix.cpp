// graph representation in adjacency matrix
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // graph
    int adj[n+1][n+1] =  {};
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // printing the adjacenecy matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        } cout << endl;
    }

    return 0;
}

// time complexity: O(n)
// space complexity: O(n*n)