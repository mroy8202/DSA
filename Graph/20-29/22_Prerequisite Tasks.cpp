// LINK: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

// If we can create a topological sort values, then ans is true

// TC: O(m+n)
// SC: O(m+n)
class Solution {
public:
	bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
	    // create an adjacency list
	    vector<int> adj[N];
	    for(int i = 0; i < P; i++) {
	        int adjacentNode = prerequisites[i].first;
	        int node = prerequisites[i].second;
	        adj[node].push_back(adjacentNode);
	    }
	    
	    // calculate indegree of each node
	    vector<int> indegree(N, 0);
	    for(int i = 0; i < N; i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    // push all nodes in queue with indegree 0
	    for(int i = 0; i < N; i++) {
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    int count = 0;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        count++;
	        
	        // traverse through all adjacent nodes and decrease their indegree
	        for(auto it: adj[node]) {
	            indegree[it]--;
	            // when indegree becomes 0, push adjacent node in queue
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    // when topo sort has N counts, then ans is true
	    if(count == N) return true;
	    else return false;
 	}
};