/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 
Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// Recursive Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    void postorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return ;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

// iterative solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if(root == NULL) return postOrder;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        
        while(!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL) st1.push(root->left);
            if(root->right != NULL) st1.push(root->right); 
        }

        while(!st2.empty()) {    
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }
        return postOrder;
    }
};