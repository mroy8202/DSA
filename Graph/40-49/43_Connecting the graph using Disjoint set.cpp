// LINK: https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
// NOTES: https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/

// TC: O(E*4α)+O(N*4α)

// Disjoint Set class
class DisjointSet {
public:
    vector<int> rank, parent;

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

        parent[node] = findUPar(parent[node]);
        return parent[node];
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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int extras = 0;
        for(auto it: edge) {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) extras++;
            else ds.unionByRank(u, v); 
        }
        
        int noOfComponents = 0;
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) noOfComponents++;
        }
        
        // for n components, we need n-1 extra edges to make it a single component graph
        int ans = noOfComponents - 1;
        if(extras >= ans) return ans;
        return -1;
    }
};