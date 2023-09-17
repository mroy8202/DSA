// LINK: https://practice.geeksforgeeks.org/problems/topological-sort/1
// Kahn's Algorithm is the BFS version of Topological Sort

// In Topological sort, if a->b, that means, a should appear before b in TOPO SORT.
// Since, b has an incoming edge from a, so, it will definately appear after a
// We will maintain a vector of indegree of nodes
// Due to DAG, there must be a node/nodes which has indegree as 0
// that means, there will be no nodes appearing before them. They will be the first.
// So, push them into the queue.
// Take the front node of the queue and travel to all its adjacent nodes and decrease the indegree of adjacent nodes.
// if degree of an adjacent node becomes 0, push them into the queue.

// TC: O(V+E) + O(V) + O(V+E) = O(V+E)
// SC: O(V) + O(V) = O(V)
class Solution {
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0);
	    
	    // fill the indegree
	    for(int i = 0; i < V; i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    // push nodes into the queue with indegree 0
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) q.push(i);
	    }
	        
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        // traverse through the adjacent nodes of node and decrese their indegree
	        for(auto it: adj[node]) {
	            indegree[it]--;
	            // when indegree of a adjacent node becomes 0, push into the queue
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    return ans;
	}
};