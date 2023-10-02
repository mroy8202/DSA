// NOTES: https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/
// Two methods, one is Union by Rank and other one is Union by Size

// UNION BY RANK | Path Compression
// TC: O(1)
// SC: O(n)
#include<bits/stdc++.h>
using namespace std;

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

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // till here, find if 3 & 7 are connected or not
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Yes, they are in same connected component\n";
    }
    else {
        cout << "No, they are in not in same connected component\n";
    }

    ds.unionByRank(3, 7);

    // find again
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Yes, they are in same connected component\n";
    }
    else {
        cout << "No, they are in not in same connected component\n";
    }

    return 0;
}



// UNION BY Size | Path Compression
// TC: O(1)
// SC: O(n)
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> size, parent;
public:
    // Constructor
    DisjointSet(int n) {
        // initialise every element of size with 1 and parent with itself
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
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

    // update the size of node and ultimate parents
    void unionBySize(int u, int v) {
        // find the ultimate parents of u & v
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // when u & v has same ultimate parent
        if(ulp_u == ulp_v) return;

        // add the size and update
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // till here, find if 3 & 7 are connected or not
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Yes, they are in same connected component\n";
    }
    else {
        cout << "No, they are in not in same connected component\n";
    }

    ds.unionBySize(3, 7);

    // find again
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Yes, they are in same connected component\n";
    }
    else {
        cout << "No, they are in not in same connected component\n";
    }

    return 0;
}