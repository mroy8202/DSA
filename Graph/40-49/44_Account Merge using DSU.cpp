// LINK: https://practice.geeksforgeeks.org/problems/account-merge/1
// NOTES: https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/

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

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        
        // push everything to the map
        map<string, int> mp;
        for(int row = 0; row < n; row++) {
            for(int col = 1; col < accounts[row].size(); col++) {
                string mail = accounts[row][col];
                // check if email already exists in the map
                if(mp.find(mail) == mp.end()) { // not exist, push in map
                    mp[mail] = row;
                }
                else { // exist, merge their row nodes
                    ds.unionByRank(mp[mail] ,row);
                }
            }
        }
        
        vector<string> mergedMail[n];
        
        // start traversing in the map and push into the adjacency list
        for(auto m: mp) {
            string mail = m.first;
            int user = ds.findUPar(m.second);
            mergedMail[user].push_back(mail);
        }
        
        // push adjacecy list mails (if valid) into the ans
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;
            
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};