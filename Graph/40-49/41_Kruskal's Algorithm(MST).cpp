// LINK: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
// NOTES: https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47/

// TC: O(N+E) + O(E logE) + O(E*4α*2)
// SC: O(N) + O(N) + O(E)
class DisjointSet {
    vector<int> rank, parent;
  public:
    // Constructor
    DisjointSet(int n) {
        // initialise every element of rank with 0 and parent with itself
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // find the ultimate parent of a node
    // and update the parent vector to reduce Time Complexity
    // PATH COMPRESSION
    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    // update the rank and ultimate parents
    void unionByRank(int u, int v) {
        // find the ultimate parents of u & v
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // when u & v has same ultimate parent
        if(ulp_u == ulp_v) return;

        // connect the ultimate parent with a smaller rank 
        // to the other ultimate parent with a larger rank
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }

        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }

        else { // when both has same rank
            parent[ulp_v] = ulp_u;
            // increase the rank of the parent node to whom we have connected the other one
            rank[ulp_u]++;
        }
    }
};

class Solution {
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // create an edge vector
        vector<vector<int>> edges;
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt, u, v});
            }
        }
        
        // sort the edges
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        
        int mstWt = 0;
        for(int i = 0; i < edges.size(); i++) {
            int wt = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            
            if(ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionByRank(u, v);
            }
        }
        return mstWt;
    }
};