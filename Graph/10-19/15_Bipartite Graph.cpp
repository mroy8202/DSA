// Question Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

/* Approach: 
Check for multiple connected components.
Maintain a color array and initialise it with -1, to colour it with 0 & 1.
if node index is not colored, call traversal function to color its adjacent nodes with different color from node
if a adjacemt node is already colored with same color as node, that means graph is not bipartite. return false  

NOTE: if a cycle of a graph has odd number of edges, it is not BIPARTITE. Else everything is BIPARTITE.
*/

// Using BFS
// Time Complexity: O(V + 2E)
// Space Complexity: O(N)
class Solution {
  private:
    bool bfs(int start, vector<int> adj[], vector<int>& color) {
	    queue<int> q;
	    q.push(start);
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        
	        for(auto adjacentNode: adj[node]) {
	            // when adjacent node is not colored yet
	            // color them with opposite color of node color
	            if(color[adjacentNode] == -1) {
	                q.push(adjacentNode);
	                color[adjacentNode] = !color[node];
	            }
	            
	            // when adjacent node is already colored and is same as node color
	            else if(color[adjacentNode] == color[node]) {
	                return false;
	            }
	        }
	    }
	    return true;
    }
    
  public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    
	    // when there is more than 1 connected components
	    for(int i = 0; i < V; i++) {
	        // when node is not visited yet
	        if(color[i] == -1) {
	            if(bfs(i, adj, color) == false)
	                return false;
	        }
	    }
	    return true;
	}
};

// Using DFS
// Time Complexity: O(V + 2E)
// Space Complexity: O(N)
class Solution {
  private:
    bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
        color[node] = col;
        
        // traverse to all adjacent nodes of node
        for(auto it: adj[node]) {
            // when adjacent node is not colored yet
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) {
                    return false;
                }
            }
            
            // when adjacent node is already colored and their color is same
            else if(color[it] == color[node]) {
                return false;
            }
        }
        return true;
    }
    
  public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    // check for multiple components
	    for(int i = 0; i < V; i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) {
	                return false;
	            }
	        }
	    }
	    return true;
	}
};