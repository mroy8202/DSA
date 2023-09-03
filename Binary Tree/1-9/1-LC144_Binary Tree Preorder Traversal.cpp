/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// Recursive Solution
/*
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
    void preorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

// Iterative Solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        // use a stack
        stack<TreeNode*> s;
        // push the root element in stack
        s.push(root);
        while(!s.empty()) {
            TreeNode* temp = s.top();
            // Since, in PreOrder (NLR), so push the root->val first
            ans.push_back(temp->val);
            // pop the top of stack
            s.pop();

            // Push right node first and then left node because of Stack(LIFO)
            if(temp->right != NULL) s.push(temp->right);
            if(temp->left != NULL) s.push(temp->left);
        }
        return ans;
    }
};