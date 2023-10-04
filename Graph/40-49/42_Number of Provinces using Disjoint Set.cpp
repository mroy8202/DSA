// LINK: https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces

// We have to find the number of different connected components
// perfrom unionByRank to modify the parent vector when adj[i][j] = 1
// union by rank will make sure that parent vector will store the ultimate parents of every node
// traverse the parent vector and if parent[i] = i, that means they are the ultimate parent of themselves.
// count the nodes which are ultimate parents of themselves.

// Disjoin Set class
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
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(i != j && adj[i][j] == 1) {
                    ds.unionByRank(i, j);
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < V; i++) {
            if(ds.parent[i] == i) count++;
        }
        return count;
    }
};