/*
Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

Example 1:
Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3 
Explanation: 
Inorder traversal : 1 2 3 
Hence, inorder successor of 2 is 3.

Example 2:
Input:
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
K(data of x) = 8
Output: 10
Explanation:
Inorder traversal: 4 8 10 12 14 20 22
Hence, successor of 8 is 10.
 
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 105, where N is number of nodes
*/
/**
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  private:
    void solve(Node* root, Node* x, Node* &ans) {
        // base case
        if(root == NULL) return ;
        
        if(x->data < root->data) {
            ans = root;
            solve(root->left, x, ans);
        }
        else {
            solve(root->right, x, ans);
        }
    }
    
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x){
        Node* ans = NULL;
        solve(root, x, ans);
        return ans;
    }
};

// TC: O(H)
// SC: O(1), except recursion call stack